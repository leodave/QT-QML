# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Ajendaa_autogen"
  "CMakeFiles\\Ajendaa_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ajendaa_autogen.dir\\ParseCache.txt"
  )
endif()
