#!/usr/bin/env bash

# Author: Matt Langston
# Date:   2014.09.02
#
# This bash script generates Visual Studio 2013 project files using
# CMake. To use it simply run it from any directory where you want
# your VS 2013 project files and pass in the name of one of the
# example apps in the Examples directory. For example:
#
# cd "c:/Users/matt/Documents/Visual Studio 2013/"
# c:/Users/matt/Documents/GitHub/titanium_mobile_windows/Tools/Scripts/generate_vs_project.sh Russ

if ! test -d "${GTEST_ROOT}"; then
    echo "GTEST_ROOT must point to your Google Test installation."
    exit 1
    #declare -rx GTEST_ROOT="c:/Users/matt/Downloads/gtest-1.7.0"
fi

declare -r example_name="${1:?}"

declare -r PROJECT_SOURCE_DIR="../../Examples/${example_name}"
declare -r PROJECT_NAME="$(basename ${PROJECT_SOURCE_DIR})"

#declare -r TARGET_PLATFORM_LIST="WindowsStore WindowsPhone"
declare -r TARGET_PLATFORM_LIST="WindowsPhone"
#declare -r TARGET_ARCHITECTURE_LIST="Win32 ARM"
declare -r TARGET_ARCHITECTURE_LIST="Win32"

declare -rx VERBOSE=1

# No user-servicable parts below this line.

function cmake_build_cmd {
    local -r target_platform="${1:?}"
    local -r target_architecture="${2:?}"
    
    case "${target_platform}" in
        "WindowsStore")
            ;;
        "WindowsPhone")
            ;;
        *)
            echo "ERROR: Unrecognized target_platform \"${target_platform}\""
            exit 1
            ;;
    esac
    
    local cmake_generator_name="Visual Studio 12 2013"
    case "${target_architecture}" in
        "Win32")
            ;;
        "ARM")
            cmake_generator_name+=" ${target_architecture}"
            ;;
        *)
            echo "ERROR: Unrecognized target_architecture \"${target_architecture}\""
            exit 1
            ;;
    esac
    
    getScriptAbsoluteDir
    local -r script_absolute_dir="${RESULT}"
    
    normalize_path "${script_absolute_dir}/${PROJECT_SOURCE_DIR}"
    local -r project_source_dir=$(cygpath -m "${RESULT}")
    
    local cmd=""
    cmd=""
    cmd+=" cmake"
    cmd+=" -G \"${cmake_generator_name}\""
    cmd+=" -DCMAKE_SYSTEM_NAME=${target_platform}"
    cmd+=" -DCMAKE_SYSTEM_VERSION=8.1"
    cmd+=" \"${project_source_dir}\""
    
    RESULT="${cmd}"
}

function generate_project_files {
    local -r target_platform="${1:?}"
    local -r target_architecture="${2:?}"
    local -r build_dir="${PROJECT_NAME}.${target_platform}.${target_architecture}"
    
    local cmd=""
    local RESULT=""
    
    cmake_build_cmd "${target_platform}" "${target_architecture}"
    cmd="(time"
    cmd+="${RESULT}"
    cmd+=")"
    # cmd+=" 2>&1 | tee ${LOG_FILE_PATH}"
    
    echo_and_eval "mkdir -p \"${build_dir}\""
    echo_and_eval "pushd \"${build_dir}\""
    
    echo_and_eval "${cmd}"
    echo_and_eval "popd"
}

# @description Normalize the given pathname by removing /./ and
# dir/.. sequences from it. This was found on
# http://www.linuxjournal.com/content/normalizing-path-names-bash
#
# Usage: normalize_path PATH
#
# @param $1 the pathname to normalize
#
function normalize_path() {
    # Remove all /./ sequences.
    local path=${1//\/.\//\/}
    
    # Remove dir/.. sequences.
    while [[ $path =~ ([^/][^/]*/\.\./) ]]
    do
        path=${path/${BASH_REMATCH[0]}/}
    done
    RESULT="$path"
}

# @description Private helper function for the "import" function
# documented below.
#
# @param $1 the script's $0 parameter
#
function getScriptAbsoluteDir {
    local script_invoke_path=$(cygpath -u "${0}")

    # If the first character is not a "/" then it is not an absolute path.
    if ! test "x${script_invoke_path:0:1}" = 'x/'; then
        script_invoke_path="${PWD}/${script_invoke_path}"
    fi
    
    normalize_path "${script_invoke_path}"
    RESULT=$(dirname "${RESULT}")
}

function echo_and_eval {
    local -r cmd="${1:?}"
    echo "${cmd}" && eval "${cmd}"
}

for target_platform in ${TARGET_PLATFORM_LIST}; do
    for target_architecture in ${TARGET_ARCHITECTURE_LIST}; do
        generate_project_files "${target_platform}" "${target_architecture}"
    done
done

#make -j 4 package
#make -j 4
#make test

