# @author Omar Huseynov
# @license GPLv3

cmake_minimum_required(VERSION 3.12)

if (NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "SDK path is not defined")
endif ()

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

get_filename_component(PICO_SDK_PATH "${PICO_SDK_PATH}" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
if (NOT EXISTS ${PICO_SDK_PATH})
    message(FATAL_ERROR "Directory '${PICO_SDK_PATH}' not found")
endif ()

set(PICO_SDK_INIT_CMAKE_FILE ${PICO_SDK_PATH}/pico_sdk_init.cmake)
if (NOT EXISTS ${PICO_SDK_INIT_CMAKE_FILE})
    message(FATAL_ERROR "Directory '${PICO_SDK_PATH}' does not contain SDK")
endif ()

set(PICO_SDK_PATH ${PICO_SDK_PATH} CACHE PATH "Path to SDK" FORCE)
include(${PICO_SDK_INIT_CMAKE_FILE})

project(sugarcube C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "SDK is wrong version: '${PICO_SDK_VERSION_STRING}'")
endif ()

pico_sdk_init()
# pico_enable_stdio_usb(sugarcube 1)
# pico_enable_stdio_uart(sugarcube 0)

add_compile_options(-Wall -Wextra -Wno-format -Wno-unused-function)
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif ()

add_executable(sugarcube main.c common.c)
target_link_libraries(sugarcube pico_stdlib pico_cyw43_arch_none)
pico_add_extra_outputs(sugarcube)
