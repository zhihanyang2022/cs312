cmake_minimum_required(VERSION 3.5)
set(APPNAME "midiout_cmp33")
project("{$APPNAME}")
### set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -D __MACOSX_CORE__ ")

### set for your path
set( HOME "/Volumes/cs312-00-w20/StuWork/yangz2" )

set(COMMON "${HOME}/common")
set(RTM "${COMMON}/RtMidi")
set(SOURCE_FILES
    ${RTM}/RtMidi.cpp
    ${COMMON}/hw332_CMidiPacket.cpp
    ${COMMON}/hw421_CDelayMs.cpp
    hw622_midiout_cmp33.cpp
)

include_directories(${COMMON} ${RTM} )
add_executable(${APPNAME} ${SOURCE_FILES})

target_link_libraries(${APPNAME} "-framework CoreMIDI")
target_link_libraries(${APPNAME} "-framework CoreAudio")
target_link_libraries(${APPNAME} "-framework CoreFoundation")