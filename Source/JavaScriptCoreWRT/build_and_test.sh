#!/usr/bin/env bash

# JavaScriptCoreWRT
#
# Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

if ! test -d "${GTEST_ROOT}"; then
    echo "GTEST_ROOT must point to your Google Test installation."
    exit 1
fi

declare -rx VERBOSE=1

declare -r JavaScriptCoreWRT_DISABLE_TESTS="ON"

cmd+="cmake"
cmd+=" -DJavaScriptCoreWRT_DISABLE_TESTS=${JavaScriptCoreWRT_DISABLE_TESTS}"
cmd+=" -DHAL_DISABLE_TESTS=ON"

cmake -P cmake/IsWin32.cmake 2>&1 | grep -q -e 1
declare -r CMAKE_HOST_WIN32=${PIPESTATUS[1]}

if [[ ${CMAKE_HOST_WIN32} == 0 ]]; then
    declare -r project_name=$(grep -E '^\s*project[(][^)]+[)]\s*$' CMakeLists.txt | awk 'BEGIN {FS="[()]"} {printf "%s", $2}')
    declare -r solution_file_name="${project_name}.sln"
    declare -r MSBUILD_PATH="c:/Program Files (x86)/MSBuild/12.0/Bin/MSBuild.exe"
    declare -r BUILD_DIR="build"
    cmd+=" ../"
    cmd+=" && \"${MSBUILD_PATH}\" ${solution_file_name}"
else
    declare -r CMAKE_BUILD_TYPE=Debug
    declare -r BUILD_DIR=build.$(echo ${CMAKE_BUILD_TYPE} | tr '[:upper:]' '[:lower:]')
    cmd+=" -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
    cmd+=" ../"
    cmd+=" && make -j 4"
fi

function echo_and_eval {
    local -r cmd="${1:?}"
    echo "${cmd}" && eval "${cmd}"
}

echo_and_eval "rm -rf \"${BUILD_DIR}\""
echo_and_eval "mkdir -p \"${BUILD_DIR}\""
echo_and_eval "pushd \"${BUILD_DIR}\""

echo_and_eval "${cmd} 2>error.log | tee ./build.log"

#
# uncomment following block if you want to exit(1) on compiler warnings
#

if [ -s error.log ]; then
  echo "[ERROR] stderr output found on build."
  cat ./error.log
  exit 1
fi

if [[ "${JavaScriptCoreWRT_DISABLE_TESTS}" != "ON" ]]; then
    echo_and_eval "ctest -VV --output-on-failure"
fi

echo_and_eval "popd"
