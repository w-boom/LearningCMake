cmake_minimum_required(VERSION 3.10)

# 设置工程名
project(CalculateSqrt VERSION 1.0)

# 设置最大版本号和最小版本号
set(CalculateSqrt_version_major 1)
set(CalculateSqrt_version_minor 0)

#将版本号传递给源文件，.h.in是新建文档，.h文件是自动生成文件
configure_file(
	"${CalculateSqrt_SOURCE_DIR}/CalculateSqrtConfig.h.in"
	"${CalculateSqrt_BINARY_DIR}/CalculateSqrtConfig.h"
)

# 添加文件
add_executable(CalculateSqrt main.cpp)

# 设置开关项相应操作
if(USE_MYMATH)
	target_compile_definitions(CalculateSqrt PRIVATE USE_MYMATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
endif()

target_link_libraries(CalculateSqrt PUBLIC ${EXTRA_LIBS})

#包含头文件
target_include_directories(
 	CalculateSqrt 
 	PUBLIC 
 	"${PROJECT_BINARY_DIR}"
)