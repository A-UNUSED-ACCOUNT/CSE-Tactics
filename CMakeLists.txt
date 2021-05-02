cmake_minimum_required(VERSION 3.13)

enable_language(CXX)

project("cse-tactic")

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
add_compile_options(
  -Wall
  -Wextra
  -Werror
  -ggdb
  -Wno-unused-variable
  -Wno-unused-private-field
  -Wno-unused-parameter)

include_directories(include)

file(GLOB source_files "src/*" "include/*")

add_executable(cse-tactic ${source_files})

target_link_libraries(cse-tactic ${SDL2_LIBRARIES})
