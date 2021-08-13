cmake_minimum_required(VERSION 3.21)

project(Algorithms-C 
    LANGUAGES C
    VERSION 0.1.1.1
    DESCRIPTION "Algorithms & Data Structures implemented in C"
    )

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

message(STATUS "Compiler Version: ${CMAKE_C_COMPILER_ID}")
message(VERBOSE "Host Architecture: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(VERBOSE "Compilation Architecture: ${CMAKE_SYSTEM_PROCESSOR}")

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-std=c11 -I /opt/homebrew/include -Wall -Wextra -pedantic -Og)
elseif(CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
    add_compile_options(-std=c11 -I /opt/homebrew/include -Weverything -pedantic -Og)
elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-std=c11 -I /opt/homebrew/include -Weverything -pedantic -Og)
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    # add_compile_options(/Za)
endif()

find_library(CMOCKA cmocka HINTS /opt/homebrew)
if(NOT CMOCKA)
    message(WARNING "Cmocka library not found.")
endif()

# Optional flag - can be set by user 
# Default "ON"
#option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
#if(USE_OPENMP)
#    find_package(OpenMP)
#    if (OpenMP_C_FOUND)
        #message(STATUS "Building with OpenMP Multithreading.")
        #    else()
        #        message(STATUS "No OpenMP found, no multithreading.")
        #    endif()
        #endif()

include(CheckIncludeFile)
include(CheckSymbolExists)

add_subdirectory(sorting/src sorting/bin)

find_package(Doxygen OPTIONAL_COMPONENTS dot dia)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_USE_MATHJAX NO)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_INLINE_SOURCES YES)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_ENABLE_PREPROCESSING YES)
    set(DOXYGEN_EXT_LINKS_IN_WINDOW YES)
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
    set(DOXYGEN_FILE_PATTERNS *.c *.h *.md)
    set(DOXYGEN_TAGFILES "doc/cppreference-doxygen-web.tag.xml=http://en.cppreference.com/w/")
    if(Doxygen_dot_FOUND)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_INTERACTIVE_SVG YES)
        set(DOXYGEN_DOT_IMAGE_FORMAT "svg")
    endif()
    if(OPENMP_FOUND)
        set(DOXYGEN_PREDEFINED "_OPENMP=1")
    endif()
    if(GLUT_FOUND)
        set(DOXYGEN_PREDEFINED ${DOXYGEN_PREDEFINED} "GLUT_FOUND=1")
    endif()

    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate documentation"
    )
endif()

## Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(CTest)

add_subdirectory(sorting/test)

enable_testing()
