cmake_minimum_required(VERSION 2.8.0)

set(TARGET_BINARY_NAME kschluff-particle_tracker)

message(STATUS ${TARGET_BINARY_NAME})
project(${TARGET_BINARY_NAME})


file(GLOB SOURCES "sources/*.cpp")

include_directories(includes)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Boost REQUIRED filesystem system)

add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})

add_executable(${TARGET_BINARY_NAME} ${SOURCES})
target_link_libraries(${TARGET_BINARY_NAME} ${OpenCV_LIBRARIES})
