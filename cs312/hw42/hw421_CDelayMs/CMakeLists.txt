cmake_minimum_required(VERSION 2.8)
set(APPNAME "hw421_CDelayMs")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

set(COMMON "/Volumes/cs312-00-w20/StuWork/yangz2/common")

set(SOURCE_FILES
  ${COMMON}/hw332_CMidiPacket.h
  ${COMMON}/hw332_CMidiPacket.cpp
  hw421_CDelayMs.cpp
  hw421_main.cpp
)

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCE_FILES})

# add framework libraries to your project.
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreServices")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioUnit")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioToolbox")