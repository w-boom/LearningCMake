aux_source_directory(. MathFunctions_SOURCE)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

#target_compile_definitions(MathFunctions PRIVATE BUILD_SHARED_LIBS)

if(BUILD_SHARED_LIBS)
	
	#设置为动态库
	add_library(MathFunctions SHARED ${MathFunctions_SOURCE})
	target_compile_definitions(MathFunctions PRIVATE MathFunctions_EXPORTS)
else()
	add_library(MathFunctions STATIC ${MathFunctions_SOURCE})
endif()

target_include_directories(
	MathFunctions
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS MathFunctions 
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(FILES MySqrt.h DESTINATION include)
