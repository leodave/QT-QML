# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ESGsender1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ESGsender1_autogen.dir\\ParseCache.txt"
  "ESGsender1_autogen"
  )
endif()
