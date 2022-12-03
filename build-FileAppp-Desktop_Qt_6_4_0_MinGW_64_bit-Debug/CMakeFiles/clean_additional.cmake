# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FileAppp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FileAppp_autogen.dir\\ParseCache.txt"
  "FileAppp_autogen"
  )
endif()
