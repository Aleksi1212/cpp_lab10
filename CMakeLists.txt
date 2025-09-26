cmake_minimum_required(VERSION 3.14)
project(Lab10)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include_directories(${CMAKE_SOURCE_DIR}/utils)

# file(GLOB UTILS_SOURCES ${CMAKE_SOURCE_DIR}/utils/*.cpp)
# add_library(utils STATIC ${UTILS_SOURCES})


file(GLOB LAB10_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(Lab10 ${LAB10_SOURCES})
# target_link_libraries(Lab4 PRIVATE utils)