# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AddContract_autogen"
  "CMakeFiles\\AddContract_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AddContract_autogen.dir\\ParseCache.txt"
  )
endif()
