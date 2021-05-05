cmake_minimum_required(VERSION 3.13)

enable_language(CXX)

project("cse-tactics")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      "${PROJECT_SOURCE_DIR}/contrib/sdl2-cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(contrib/json)

add_compile_options(
  -Wall
  -Wextra
  -Werror
  -ggdb
  -Wno-unused-variable
  -Wno-unused-private-field
  -Wno-unused-parameter)

include_directories(include SDL2 SDL2::Image)

file(GLOB source_files "src/*" "include/*")

add_executable(cse-tactics ${source_files})

target_link_libraries(cse-tactics SDL2 SDL2::Image nlohmann_json::nlohmann_json
                      stdc++fs)
