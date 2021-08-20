add_library(Utils STATIC)
target_include_directories(Utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_INSTALL_PREFIX}/include
)

target_sources(Utils
  PUBLIC
    utils.h
  PRIVATE
    utils.cpp
)

install(TARGETS Utils
    EXPORT UtilsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)
add_library(NexerArbetsprov::Utils ALIAS Utils)