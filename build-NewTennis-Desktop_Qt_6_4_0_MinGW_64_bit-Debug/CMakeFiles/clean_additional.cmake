# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NewTennis_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NewTennis_autogen.dir\\ParseCache.txt"
  "NewTennis_autogen"
  )
endif()
