add_library(Solutions STATIC)
add_dependencies(Solutions Utils)

target_include_directories(Solutions
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_INSTALL_PREFIX}
)

target_link_directories(Solutions
  PRIVATE
    ${CMAKE_INSTALL_PREFIX}/lib
)

target_link_libraries(Solutions
    NexerArbetsprov::Utils
)

target_sources(Solutions
  PUBLIC
    GeorgesCheesePizza.h
    PlayFair.h
    PersFactorial.h
  PRIVATE
    GeorgesCheesePizza.cpp
    PlayFair.cpp
    PersFactorial.cpp
)

install(TARGETS Solutions
    EXPORT SolutionsTargets
    LIBRARY DESTINATION  ${CMAKE_INSTALL_PREFIX}/lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)
add_library(NexerArbetsprov::Solutions ALIAS Solutions)