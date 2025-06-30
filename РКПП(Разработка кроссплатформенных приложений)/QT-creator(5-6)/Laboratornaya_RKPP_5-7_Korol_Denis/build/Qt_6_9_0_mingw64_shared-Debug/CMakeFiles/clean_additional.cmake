# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Laboratornaya_RKPP_5-7_Korol_Denis_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Laboratornaya_RKPP_5-7_Korol_Denis_autogen.dir\\ParseCache.txt"
  "Laboratornaya_RKPP_5-7_Korol_Denis_autogen"
  )
endif()
