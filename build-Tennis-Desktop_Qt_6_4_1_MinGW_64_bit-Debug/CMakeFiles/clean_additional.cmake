# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Tennis_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tennis_autogen.dir\\ParseCache.txt"
  "Tennis_autogen"
  )
endif()
