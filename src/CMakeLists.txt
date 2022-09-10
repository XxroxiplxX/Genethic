set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} genethic-lib/Individual.cpp genethic-lib/Individual.h genethic-lib/Population.cpp genethic-lib/Population.h Lower_Diag_Parser.cpp Lower_Diag_Parser.h Abstract_Parser.h genethic-lib/Habitat.cpp genethic-lib/Habitat.h)
