cmake_minimum_required(VERSION 3.14)
project(autodiffCPP LANGUAGES CXX)

# 1) Set your C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2) Put headers in include/ so users can do #include <ad/dual.hpp>
add_library(autodiff_headers INTERFACE)
target_include_directories(autodiff_headers INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 3) Build your core library from src/*.cpp
add_library(autodiff_core
  src/dual.cpp
  src/tape.cpp
)
target_link_libraries(autodiff_core PUBLIC autodiff_headers)
# (later you can add PRIVATE flags, warnings, etc.)

# 4) Example executable that links against your library
add_executable(demo examples/demo.cpp)
target_link_libraries(demo PRIVATE autodiff_core)

# 5) Tests (using Catch2 as an example)
#    - You can either install Catch2 system‑wide or pull it via FetchContent.
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.10
)
FetchContent_MakeAvailable(catch2)

add_executable(test_dual tests/test_dual.cpp)
target_link_libraries(test_dual PRIVATE autodiff_core Catch2::Catch2)
add_test(NAME DualTests COMMAND test_dual)
