# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TrafficLight1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TrafficLight1_autogen.dir\\ParseCache.txt"
  "TrafficLight1_autogen"
  )
endif()
