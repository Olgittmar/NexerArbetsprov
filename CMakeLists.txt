# --------------------------------------------------------------------------------------
# This project is a container for solutions to a programming test.
# It is not intended to be used outside of that context.
# --------------------------------------------------------------------------------------
# You might see comments that starts with "TODO", "!", "?" or similar,
# this is because VScode has a neat way of keeping track of issues and todo-lists through comments.
# --------------------------------------------------------------------------------------
# PROJECT
cmake_minimum_required(VERSION 3.18)
project(NexerArbetsprov VERSION 0.0.1)
# I'm reusing the same package manager structure 
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
# --------------------------------------------------------------------------------------
# SETTINGS
# Need compile_commands for VSCode's intellisense to play nice with Ninja
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Options
option(ENABLE_TESTING "Enable building of test" TRUE )
option(ENABLE_CPPCHECK "Enable cppcheck analyzer" FALSE )

# --------------------------------------------------------------------------------------
# EXTERNAL


# Recount to user what we are doing
message("=========================================")
message("\t\t\tSummary")
message("=========================================")
message("Build type:       \t ${CMAKE_BUILD_TYPE}")
message("Compiler:         \t ${CMAKE_CXX_COMPILER_ID}")
message("Version:          \t ${PROJECT_VERSION}")
message("Build dir:        \t ${CMAKE_BINARY_DIR}")
message("Install prefix:   \t ${CMAKE_INSTALL_PREFIX}")
message("-----------------------------------------")
message("Testing enabled:  \t ${ENABLE_TESTING}")
message("Cppcheck:         \t ${ENABLE_CPPCHECK}")
message("-----------------------------------------")

# ---------------------------------------------------------------------------

if(ENABLE_CPPCHECK)
    find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck REQUIRED)
    if(CMAKE_CXX_CPPCHECK)
        list(APPEND CMAKE_CXX_CPPCHECK
        --enable=performance
        --library=qt
        --project=${CMAKE_BINARY_DIR}/compile_commands.json
        --platform=win64
        --quiet
        )
    else()
        message(SEND_ERROR "cppcheck enabled but program not found")
    endif()
endif()

# ---------------------------------------------------------------------------
# BUILD
add_executable(NexerArbetsprov
    main.cpp
)
set_target_properties(NexerArbetsprov
    PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)
add_subdirectory( src )
target_link_libraries(NexerArbetsprov PRIVATE
    NexerArbetsprov::Utils
    NexerArbetsprov::Solutions
)

if(ENABLE_TESTING)
    enable_testing(TRUE)
    add_subdirectory(test)
endif()


install(TARGETS NexerArbetsprov
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
    RESOURCE DESTINATION rsc
)

# Copy conan imports to installation folder, workaround for testing and installing separately
add_custom_command(TARGET NexerArbetsprov POST_BUILD
    COMMAND conan imports
    ${PROJECT_SOURCE_DIR}/conan/conanfile.py -imf
    ${CMAKE_INSTALL_PREFIX}
)
# -----------------------------------------------------------------------------------------