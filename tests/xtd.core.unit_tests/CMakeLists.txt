cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.unit_tests)
set(SOURCES
  src/main.cpp 
  src/argument_exception.cpp
  src/argument_null_exception.cpp
  src/argument_out_of_range_exception.cpp
  src/arithmetic_exception.cpp
  src/bit_converter.cpp
  src/bytes_assert.h
  src/divided_by_zero_exception.cpp
  src/domain_exception.cpp
  src/environment.cpp
  src/format_exception.cpp
  src/guid.cpp
  src/index_out_of_range_exception.cpp
  src/invalid_cast_exception.cpp
  src/invalid_operation_exception.cpp
  src/invalid_program_exception.cpp
  src/length_exception.cpp
  src/not_finite_number_exception.cpp
  src/not_implemented_exception.cpp
  src/not_supported_exception.cpp
  src/null_pointer_exception.cpp
  src/object.cpp
  src/operation_canceled_exception.cpp
  src/overflow_exception.cpp
  src/platform_not_supported_exception.cpp
  src/system_exception.cpp
  src/time_out_exception.cpp
  src/underflow_exception.cpp
  src/version.cpp
  src/xml_syntax_exception.cpp
)
set(COLLECTIONS_SOURCES
  src/collections/key_not_found_exception.cpp
)
set(IO_SOURCES
  src/io/directory_not_found_exception.cpp
  src/io/drive_not_found_exception.cpp
  src/io/end_of_stream_exception.cpp
  src/io/file_format_exception.cpp
  src/io/file_load_exception.cpp
  src/io/file_not_found_exception.cpp
  src/io/ioexception.cpp
  src/io/path_too_long_exception.cpp
)
source_group(src FILES ${SOURCES})
source_group(src\\collections FILES ${COLLECTIONS_SOURCES})
source_group(src\\io FILES ${IO_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES} ${COLLECTIONS_SOURCES} ${IO_SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.core xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
