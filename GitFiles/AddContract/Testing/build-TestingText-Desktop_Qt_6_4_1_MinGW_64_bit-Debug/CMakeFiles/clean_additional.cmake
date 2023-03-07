# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TestingText_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TestingText_autogen.dir\\ParseCache.txt"
  "TestingText_autogen"
  )
endif()
