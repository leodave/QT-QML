# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QmlContract_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QmlContract_autogen.dir\\ParseCache.txt"
  "QmlContract_autogen"
  )
endif()
