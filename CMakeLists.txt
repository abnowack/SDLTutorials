cmake_minimum_required(VERSION 2.8)
project(SDLTutorials)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(lesson01 lesson01.cpp)
target_link_libraries(lesson01 ${SDL2_LIBRARIES})
set_target_properties(lesson01 PROPERTIES LINK_FLAGS ${SDL2_LINK_FLAGS})

add_executable(lesson02 lesson02.cpp)
target_link_libraries(lesson02 ${SDL2_LIBRARIES})
set_target_properties(lesson02 PROPERTIES LINK_FLAGS ${SDL2_LINK_FLAGS})

# show console for visual studio debug builds
if(WIN32)
   set_target_properties(lesson01 PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
   set_target_properties(lesson01 PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
   set_target_properties(lesson01 PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
   set_target_properties(lesson01 PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
   set_target_properties(lesson01 PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
   set_target_properties(lesson01 PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")

   set_target_properties(lesson02 PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
   set_target_properties(lesson02 PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
   set_target_properties(lesson02 PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
   set_target_properties(lesson02 PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
   set_target_properties(lesson02 PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
   set_target_properties(lesson02 PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif(WIN32)
