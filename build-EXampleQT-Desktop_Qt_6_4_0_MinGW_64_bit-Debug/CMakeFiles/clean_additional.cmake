# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EXampleQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EXampleQT_autogen.dir\\ParseCache.txt"
  "EXampleQT_autogen"
  )
endif()
