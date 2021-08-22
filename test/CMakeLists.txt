include(GoogleTest)
add_executable(testNexerArbetsprov
    test_main.cpp
    test_solutions.cpp
)
target_link_libraries(testNexerArbetsprov
    CONAN_PKG::gtest
    NexerArbetsprov::Utils
    NexerArbetsprov::Solutions
)
gtest_discover_tests(testNexerArbetsprov)
add_custom_command(TARGET testNexerArbetsprov
    POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/testData ${CMAKE_BINARY_DIR}/testData
)