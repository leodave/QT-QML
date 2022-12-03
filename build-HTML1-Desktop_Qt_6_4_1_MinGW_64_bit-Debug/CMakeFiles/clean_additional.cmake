# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HTML1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HTML1_autogen.dir\\ParseCache.txt"
  "HTML1_autogen"
  )
endif()
