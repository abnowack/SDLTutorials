cmake_minimum_required(VERSION 2.8)
project(SDLTutorials)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES lesson01.cpp)

add_executable(lesson01 ${SOURCE_FILES})
target_link_libraries(lesson01 ${SDL2_LIBRARIES})
set_target_properties(lesson01 PROPERTIES LINK_FLAGS ${SDL2_LINK_FLAGS})
