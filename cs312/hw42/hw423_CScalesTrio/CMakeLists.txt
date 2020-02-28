cmake_minimum_required(VERSION 2.8)
set(APPNAME "hw423_CScalesTrio")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

set(COMMON "/Volumes/cs312-00-w20/StuWork/yangz2/common")

set(SOURCE_FILES
  ${COMMON}/hw423_CMidiTrack.cpp
  ${COMMON}/hw423_CMidiTrack.h
  ${COMMON}/hw421_CDelayMs.cpp
  ${COMMON}/hw421_CDelayMs.h
  ${COMMON}/hw422_CAppleMidiSynth.cpp
  ${COMMON}/hw422_CAppleMidiSynth.h
  ${COMMON}/hw332_CMidiPacket.cpp
  ${COMMON}/hw332_CMidiPacket.h
  hw423_CAltoTrack.cpp
  hw423_CAltoTrack.h
  hw423_CBassTrack.cpp
  hw423_CBassTrack.h
  hw423_CScalesTrack.cpp
  hw423_CScalesTrack.h
  hw423_CSopranoTrack.cpp
  hw423_CSopranoTrack.h
  hw423_main.cpp
)

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCE_FILES})

# add framework libraries to your project.
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreServices")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioUnit")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioToolbox")