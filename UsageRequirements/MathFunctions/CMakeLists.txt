add_library(MathFunctions MySqrt.h MySqrt.cpp)

target_include_directories(
	MathFunctions
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)