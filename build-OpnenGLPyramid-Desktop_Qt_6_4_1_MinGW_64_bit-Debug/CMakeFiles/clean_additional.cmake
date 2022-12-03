# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OpnenGLPyramid_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OpnenGLPyramid_autogen.dir\\ParseCache.txt"
  "OpnenGLPyramid_autogen"
  )
endif()
