# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FilePdfQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FilePdfQt_autogen.dir\\ParseCache.txt"
  "FilePdfQt_autogen"
  )
endif()
