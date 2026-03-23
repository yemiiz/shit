cmake_minimum_required(VERSION 3.10)
project(speech_app)
#第一种
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
#第二种
#file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(speech_app ${SRC_LIST})
add_library(speechapp SHARED ${SRC_LIST})
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_library(speechapp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)