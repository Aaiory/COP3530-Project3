# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WindowProgram_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WindowProgram_autogen.dir\\ParseCache.txt"
  "WindowProgram_autogen"
  )
endif()
