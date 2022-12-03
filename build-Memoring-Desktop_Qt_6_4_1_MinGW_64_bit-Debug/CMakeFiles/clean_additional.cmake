# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Memoring_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Memoring_autogen.dir\\ParseCache.txt"
  "Memoring_autogen"
  )
endif()
