# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Ajenda2_autogen"
  "CMakeFiles\\Ajenda2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ajenda2_autogen.dir\\ParseCache.txt"
  )
endif()
