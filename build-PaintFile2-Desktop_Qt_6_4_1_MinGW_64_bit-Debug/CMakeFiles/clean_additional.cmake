# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PaintFile2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PaintFile2_autogen.dir\\ParseCache.txt"
  "PaintFile2_autogen"
  )
endif()
