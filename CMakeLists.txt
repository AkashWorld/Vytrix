cmake_minimum_required (VERSION 3.11)
project(Vytrix)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -mavx2 -mfma -ffp-contract=fast")
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()
set (CMAKE_CXX_STANDARD 11)
set(LIB_PATH "./libs")
include_directories(${LIB_PATH}/Catch2/single_include/catch2)
include_directories(./src)
include_directories(CATCH_SINGLE_INCLUDE)
add_executable(test test_vytrix.cpp)