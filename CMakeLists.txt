include("$ENV{PSPDEV}/psp/share/pspdev.cmake")

add_library(minIni
  src/minIni.c
)

target_include_directories(minIni
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_definitions(-DNDEBUG)