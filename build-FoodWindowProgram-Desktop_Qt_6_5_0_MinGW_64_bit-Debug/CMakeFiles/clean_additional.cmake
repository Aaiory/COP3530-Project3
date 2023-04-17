# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FoodWindowProgram_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FoodWindowProgram_autogen.dir\\ParseCache.txt"
  "FoodWindowProgram_autogen"
  )
endif()
