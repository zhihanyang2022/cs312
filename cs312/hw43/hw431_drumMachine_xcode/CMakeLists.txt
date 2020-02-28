cmake_minimum_required(VERSION 3.5)
set(APPNAME "drum_machine")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

set(COMMON "/Volumes/cs312-00-w20/StuWork/yangz2/common")

set(SOURCE_FILES
  ${COMMON}/hw332_CMidiPacket.cpp
  ${COMMON}/hw423_CMidiTrack.cpp
  ${COMMON}/hw421_CDelayMs.cpp
  ${COMMON}/hw422_CAppleMidiSynth.cpp
  hw431_CDrumMachine.cpp
  hw431_CDrumTrack.cpp
  hw431_main.cpp
)

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCE_FILES})

# add framework libraries to your project.
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreServices")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioUnit")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioToolbox")