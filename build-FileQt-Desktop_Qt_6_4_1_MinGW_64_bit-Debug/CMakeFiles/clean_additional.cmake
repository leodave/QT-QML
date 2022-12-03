# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appFileQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appFileQt_autogen.dir\\ParseCache.txt"
  "appFileQt_autogen"
  )
endif()
