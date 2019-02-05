cmake_minimum_required(VERSION 3.0)
message("Compile UUIDs")
PROJECT(UUIDs)
INCLUDE (CheckIncludeFile)

include_directories(include)

SET(HEADERS include/UUIDs.hpp)
SET(CORES SRCs/UUIDs.cpp SRCs/nDestroyer.cpp)

if(BUILD_SHARED_LIBS)
  ADD_LIBRARY(UUIDs SHARED ${CORES} ${HEADERS})
  add_definitions("-DBUILD_SHARED_LIBS=1")
  add_definitions("-DEXPORT_UUIDS=1")
  install(TARGETS UUIDs
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
  install(FILES include/UUIDs.hpp DESTINATION include)
else(BUILD_SHARED_LIBS)
  ADD_LIBRARY(UUIDs STATIC ${CORES} ${HEADERS})
  install(TARGETS UUIDs DESTINATION lib)
  install(FILES include/UUIDs.hpp DESTINATION include)
endif(BUILD_SHARED_LIBS)
