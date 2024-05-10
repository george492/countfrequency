# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\countfrequency_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\countfrequency_autogen.dir\\ParseCache.txt"
  "countfrequency_autogen"
  )
endif()
