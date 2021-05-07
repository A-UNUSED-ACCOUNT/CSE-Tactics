# This makefile builds and pulls the executables out of the SDL2 build tree
# without installing, and has easy multiplatform support Only works with
# GCC-like compilers, and only tested on GCC

cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/contrib/sdl2")

option(PLATFORM "Set the target platform" NATIVE)

# Guesses the compiler from the native system
if(PLATFORM STREQUAL "NATIVE")
  set(CMAKE_C_COMPILER "cc")
  set(CMAKE_CXX_COMPILER "c++")
endif(PLATFORM STREQUAL "NATIVE")

# Linux x86
if(PLATFORM STREQUAL "LINUX-X86")
  set(CMAKE_C_COMPILER "i686-linux-gnu-gcc")
  set(CMAKE_CXX_COMPILER "i686-linux-gnu-g++")
  set(CMAKE_SYSTEM_NAME Linux)
endif(PLATFORM STREQUAL "LINUX-X86")

# Linux x64
if(PLATFORM STREQUAL "LINUX-X64")
  set(CMAKE_C_COMPILER "x86_64-linux-gnu-gcc")
  set(CMAKE_CXX_COMPILER "x86_64-linux-gnu-g++")
  set(CMAKE_SYSTEM_NAME Linux)
endif(PLATFORM STREQUAL "LINUX-X64")

# Linux Armeabi
if(PLATFORM STREQUAL "LINUX-ARMEABI")
  set(CMAKE_C_COMPILER "arm-linux-gnueabi-gcc")
  set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-g++")
  set(CMAKE_SYSTEM_NAME Linux)
endif(PLATFORM STREQUAL "LINUX-ARMEABI")

# Linux Armeabihf
if(PLATFORM STREQUAL "LINUX-ARMHF")
  set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
  set(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
  set(CMAKE_SYSTEM_NAME Linux)
endif(PLATFORM STREQUAL "LINUX-ARMHF")

# Windows x64
if(PLATFORM STREQUAL "WINDOWS-X64")
  set(CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc")
  set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
  set(CMAKE_RC_COMPILER "x86_64-w64-mingw32-windres")
  set(CMAKE_FIND_ROOT_PATH "/usr/x86_64-w64-mingw32")
  set(CMAKE_SYSTEM_NAME Windows)
endif(PLATFORM STREQUAL "WINDOWS-X64")

# Windows x86
if(PLATFORM STREQUAL "WINDOWS-X86")
  set(CMAKE_C_COMPILER "i686-w64-mingw32-gcc")
  set(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")
  set(CMAKE_RC_COMPILER "i686-w64-mingw32-windres")
  set(CMAKE_FIND_ROOT_PATH "/usr/i686-w64-mingw32")
  set(CMAKE_SYSTEM_NAME Windows)
endif(PLATFORM STREQUAL "WINDOWS-X86")

project("cse-tactics")
message("${PLATFORM}")

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

add_subdirectory(contrib/json)
add_subdirectory(contrib/sdl2)

file(GLOB source_files "${CMAKE_SOURCE_DIR}/src/*"
     "${CMAKE_SOURCE_DIR}/include/*")

add_executable(cse-tactics ${source_files})

target_compile_options(
  cse-tactics
  PUBLIC -Wall
         -Wextra
         -Werror
         -pedantic
         -ggdb
         -Os
         -Wno-unused-variable
         -Wno-unused-private-field
         -Wno-unused-parameter)

include_directories("${CMAKE_SOURCE_DIR}/include"
                    "${CMAKE_SOURCE_DIR}/contrib/sdl2/include")

if(MINGW)
  target_link_options(cse-tactics PUBLIC -lmingw32)
endif()

target_link_options(cse-tactics PUBLIC -L${CMAKE_SOURCE_DIR}/build/contrib/sdl2
                    -lSDL2 -lSDL2main)

target_link_libraries(cse-tactics SDL2 SDL2main nlohmann_json::nlohmann_json
                      stdc++fs)
