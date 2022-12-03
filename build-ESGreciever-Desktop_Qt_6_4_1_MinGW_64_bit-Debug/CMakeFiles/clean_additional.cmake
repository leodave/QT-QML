# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ESGreciever_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ESGreciever_autogen.dir\\ParseCache.txt"
  "ESGreciever_autogen"
  )
endif()
