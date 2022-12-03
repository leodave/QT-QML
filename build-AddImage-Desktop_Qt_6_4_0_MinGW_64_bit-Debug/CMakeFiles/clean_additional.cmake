# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AddImage_autogen"
  "CMakeFiles\\AddImage_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AddImage_autogen.dir\\ParseCache.txt"
  )
endif()
