# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DineAutoProjectV3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DineAutoProjectV3_autogen.dir\\ParseCache.txt"
  "DineAutoProjectV3_autogen"
  )
endif()
