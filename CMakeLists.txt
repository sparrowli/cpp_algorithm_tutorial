# CMake requirement for minimum version
cmake_minimum_required (VERSION 2.8)

# project information
project (anagrams)

aux_source_directory(. DIR_SRCS)

#include_directories ("${PROJECT_SOURCE_DIR}/digital_agc")
#add_subdirectory (digital_agc)
#add_subdirectory(agc)

add_executable(anagrams ${DIR_SRCS})
#add_library (audio_processing ${DIR_SRCS})
#target_link_libraries(audio_processing digital_agc)
