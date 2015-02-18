# Convert a binary data file into a C++
# source file for embedding into an application binary
#
# Requires 'node' to be installed.
#
# TARGET_NAME : The name of the target to generate
#
# INPUT_FILE  : The name of the binary data file to be converted into a C++
#               source file.  The name of the input file will be used as the basis for the
#               symbols in the generated C++ file referring to the data buffer.
#
# CPP_FILE    : The path of the C++ source file to be generated.
#               See the documentation for file2int.js for information on
#               the structure of the generated source file.
#
function (generate_cpp_header_file TARGET_NAME INPUT_FILE CPP_FILE)
	add_custom_command(OUTPUT ${CPP_FILE}
		COMMAND node ${CMAKE_CURRENT_LIST_DIR}/../cmake/file2int.js ${INPUT_FILE} > ${CPP_FILE}
	    DEPENDS ${INPUT_FILE})
	add_custom_target(${TARGET_NAME} ALL DEPENDS ${CPP_FILE})
endfunction()