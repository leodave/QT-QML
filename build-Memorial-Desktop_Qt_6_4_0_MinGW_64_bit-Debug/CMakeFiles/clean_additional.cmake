# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Memorial_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Memorial_autogen.dir\\ParseCache.txt"
  "Memorial_autogen"
  )
endif()
