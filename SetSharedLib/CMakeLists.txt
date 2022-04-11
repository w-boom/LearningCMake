cmake_minimum_required(VERSION 3.10)

# 设置工程名
project(CalculateSqrt VERSION 1.0)

# 设置最大版本号和最小版本号
set(CalculateSqrt_version_major 1)
set(CalculateSqrt_version_minor 0)

#设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

#动态库
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

#将版本号传递给源文件，.h.in是新建文档，.h文件是自动生成文件
configure_file(
	"${CalculateSqrt_SOURCE_DIR}/CalculateSqrtConfig.h.in"
	"${CalculateSqrt_BINARY_DIR}/CalculateSqrtConfig.h"
)

#查找当前目录下所有源文件并保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

add_subdirectory(MathFunctions)

# 添加文件
add_executable(CalculateSqrt ${DIR_SRCS})

target_link_libraries(CalculateSqrt PUBLIC MathFunctions)

