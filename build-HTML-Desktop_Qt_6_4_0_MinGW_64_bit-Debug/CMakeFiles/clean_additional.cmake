# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HTML_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HTML_autogen.dir\\ParseCache.txt"
  "HTML_autogen"
  )
endif()
