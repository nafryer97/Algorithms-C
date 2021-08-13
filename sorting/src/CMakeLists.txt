# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB LIB_SOURCES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
foreach( libsource ${LIB_SOURCES} )
    string( REPLACE ".c" "" libname ${libsource} )
    add_library( ${libname} ${libsource} )

    install(TARGETS ${libname} DESTINATION "../bin")
endforeach()
