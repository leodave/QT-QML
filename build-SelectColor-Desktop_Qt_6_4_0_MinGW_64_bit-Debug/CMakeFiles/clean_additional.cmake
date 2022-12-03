# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SelectColor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SelectColor_autogen.dir\\ParseCache.txt"
  "SelectColor_autogen"
  )
endif()
