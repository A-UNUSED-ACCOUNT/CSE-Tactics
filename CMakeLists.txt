cmake_minimum_required(VERSION 3.13)

enable_language(CXX)

project("cse-tactic")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
add_compile_options(
  -Wall
  -Wextra
  -Werror
  -ggdb
  -Wno-unused-variable
  -Wno-unused-private-field
  -Wno-unused-parameter)

include_directories(include ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})

file(GLOB source_files "src/*" "include/*")

add_executable(cse-tactic ${source_files})

target_link_libraries(cse-tactic ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
