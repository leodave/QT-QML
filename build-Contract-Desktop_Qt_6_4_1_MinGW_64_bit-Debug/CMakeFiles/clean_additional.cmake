# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Contract_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Contract_autogen.dir\\ParseCache.txt"
  "Contract_autogen"
  )
endif()
