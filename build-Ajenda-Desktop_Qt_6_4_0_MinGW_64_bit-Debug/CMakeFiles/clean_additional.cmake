# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Ajenda_autogen"
  "CMakeFiles\\Ajenda_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ajenda_autogen.dir\\ParseCache.txt"
  )
endif()
