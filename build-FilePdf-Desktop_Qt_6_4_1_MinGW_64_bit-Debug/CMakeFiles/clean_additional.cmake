# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FilePdf_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FilePdf_autogen.dir\\ParseCache.txt"
  "FilePdf_autogen"
  )
endif()
