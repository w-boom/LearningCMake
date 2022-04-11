aux_source_directory(. MathFunctions_SOURCE)

#设置为动态库
add_library(MathFunctions SHARED ${MathFunctions_SOURCE})

target_include_directories(
	MathFunctions
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(MathFunctions PRIVATE MathFunctions_EXPORTS)

install(TARGETS MathFunctions 
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(FILES MySqrt.h DESTINATION include)
