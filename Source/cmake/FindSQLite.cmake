# Author: Kota Iguchi
# Created: 2014.11.04
#
# Try to find SQLite. Once done this will define:
#  
#  SQLITE_FOUND        - system has SQLite
#  SQLite_INCLUDE_DIRS - the include directory
#  SQLite_LIBRARY_DIR  - the directory containing the library
#  SQLite_LIBRARIES    - link these to use SQLite

find_package(PkgConfig)

pkg_check_modules(PC_SQLite QUIET SQLite)

find_path(SQLite_INCLUDE_DIRS
  NAMES sqlite3.h
  HINTS ${PC_SQLite_INCLUDE_DIRS} ${PC_SQLite_INCLUDEDIR}
  PATHS ENV SQLite_HOME
  PATH_SUFFIXES includes
  )

set(SQLite_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(SQLite_ARCH "arm")
endif()

find_library(SQLite_LIBRARIES
  NAMES sqlite3
  HINTS ${PC_SQLite_LIBRARY_DIRS} ${PC_SQLite_LIBDIR}
  PATHS ENV SQLite_HOME
  PATH_SUFFIXES ${CMAKE_SYSTEM_NAME}\\${SQLite_ARCH}-Release ${CMAKE_SYSTEM_NAME}\\${SQLite_ARCH}-Debug
  )

if(NOT SQLite_LIBRARIES MATCHES ".+-NOTFOUND")
  get_filename_component(SQLite_LIBRARY_DIR ${SQLite_LIBRARIES} DIRECTORY)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite DEFAULT_MSG SQLite_INCLUDE_DIRS SQLite_LIBRARIES)

message(STATUS "MDL: SQLITE_FOUND         = ${SQLITE_FOUND}")
message(STATUS "MDL: SQLite_INCLUDE_DIRS  = ${SQLite_INCLUDE_DIRS}")
message(STATUS "MDL: SQLite_LIBRARY_DIR   = ${SQLite_LIBRARY_DIR}")
message(STATUS "MDL: SQLite_LIBRARIES     = ${SQLite_LIBRARIES}")
