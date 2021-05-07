cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/contrib/sdl2")

option(PLATFORM "Set the target platform")

if(PLATFORM STREQUAL "LINUX-X86")
  set(CMAKE_C_COMPILER "i686-linux-gnu-gcc")
  set(CMAKE_CXX_COMPILER "i686-linux-gnu-g++")
endif(PLATFORM STREQUAL "LINUX-X86")

if(PLATFORM STREQUAL "LINUX-X64")
  set(CMAKE_C_COMPILER "x86_64-linux-gnu-gcc")
  set(CMAKE_CXX_COMPILER "x86_64-linux-gnu-g++")
endif(PLATFORM STREQUAL "LINUX-X64")

if(PLATFORM STREQUAL "WINDOWS-X64")
  set(CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc")
  set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
  set(CMAKE_RC_COMPILER "x86_64-w64-mingw32-windres")
  set(CMAKE_FIND_ROOT_PATH "/usr/x86_64-w64-mingw32")
  set(CMAKE_SYSTEM_NAME Windows)
endif(PLATFORM STREQUAL "WINDOWS-X64")

if(PLATFORM STREQUAL "WINDOWS-X86")
  set(CMAKE_C_COMPILER "i686-w64-mingw32-gcc")
  set(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")
  set(CMAKE_RC_COMPILER "i686-w64-mingw32-windres")
  set(CMAKE_FIND_ROOT_PATH "/usr/i686-w64-mingw32")
  set(CMAKE_SYSTEM_NAME Windows)
endif(PLATFORM STREQUAL "WINDOWS-X86")

project("cse-tactics")

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

# find_package(SDL2 REQUIRED) find_package(SDL2_image REQUIRED)

add_subdirectory(contrib/json)
add_subdirectory(contrib/sdl2)

file(GLOB source_files "src/*" "include/*")

add_executable(cse-tactics ${source_files})

target_compile_options(
  cse-tactics
  PUBLIC -Wall
         -Wextra
         -Werror
         -pedantic
         -ggdb
         -Wno-unused-variable
         -Wno-unused-private-field
         -Wno-unused-parameter)

include_directories("include" "contrib/sdl2/include")

target_link_libraries(cse-tactics SDL2 SDL2main nlohmann_json::nlohmann_json
                      stdc++fs)
