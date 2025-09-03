cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES C)

# Force GCC 15
set(CMAKE_C_COMPILER "/opt/gcc-15/bin/gcc")

# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
SET (CMAKE_C_FLAGS_INIT                "-Wall -std=c23")
SET (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET (CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++23")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

macro(add_sanitizer flag)
    if (CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
        message(STATUS "Looking for -fsanitize=${flag}")

        file(WRITE ${CMAKE_BINARY_DIR}/sanitizer_check.c "int main(void) { return 0; }")

        execute_process(
            COMMAND ${CMAKE_C_COMPILER} -fsanitize=${flag} -S ${CMAKE_BINARY_DIR}/sanitizer_check.c -o ${CMAKE_BINARY_DIR}/sanitizer_check.s
            RESULT_VARIABLE SANITIZER_CHECK_RESULT
            OUTPUT_QUIET
            ERROR_QUIET
        )

        if(SANITIZER_CHECK_RESULT EQUAL 0)
            message(STATUS "Found -fsanitize=${flag}")
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=${flag} -fno-omit-frame-pointer")
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${flag}")
        else()
            message(STATUS "Compiler does not support -fsanitize=${flag}")
        endif()
    endif()
endmacro()

# @brief Add address sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_address_sanitizer)
    #[add_address_sanitizer Add address sanitizer to all targets
    add_sanitizer("address")
    #]
endmacro()

# @brief Add thread sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_thread_sanitizer)
    #[add_thread_sanitizer Add thread sanitizer to all targets
    add_sanitizer("thread")
    #]
endmacro()

# @brief Add undefined sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_undefined_sanitizer)
    #[add_undefined_sanitizer Add undefined sanitizer to all targets
    add_sanitizer("undefined")
    #]
endmacro()

# @brief Add memory sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_memory_sanitizer)
    #[add_memory_sanitizer Add memory sanitizer to all targets
    add_sanitizer("memory")
    #]
endmacro()

# @brief @brief Add leak sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_leak_sanitizer)
    #[add_leak_sanitizer Add leak sanitizer to all targets
    add_sanitizer("leak")
    #]
endmacro()

# @brief Add all sanitizers to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_sanitizers)
    #[add_sanitizers Add all sanitizers to all targets
    # Choose a subset of sanitizers not in conflict
    add_address_sanitizer()
    add_leak_sanitizer()
    add_undefined_sanitizer()
    # not allowed with address sanitizer
    # add_thread_sanitizer()
    # not supported
    # add_memory_sanitizer()
    #]
endmacro()

# Choose a subset of sanitizers not in conflict
add_address_sanitizer()

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -lm
    -Wall
    -Wextra
    -ggdb
    # -std=c23
)

# Main executable with mandelbrot sources
add_executable(${ProjectId}
    src/main.c
    src/merge_sort.c
    # src/mandelbrot.c
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

