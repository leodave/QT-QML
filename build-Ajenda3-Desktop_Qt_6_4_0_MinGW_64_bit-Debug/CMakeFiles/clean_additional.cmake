# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Ajenda3_autogen"
  "CMakeFiles\\Ajenda3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ajenda3_autogen.dir\\ParseCache.txt"
  )
endif()
