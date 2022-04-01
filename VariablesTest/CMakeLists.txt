cmake_minimum_required(VERSION 3.08)
message("父目录 CMakeLists.txt 文件")
set(VAR1 "123456")

message("第一次在父目录 VAR1 = ${VAR1}")
add_subdirectory(SubDirecTest)  # 添加子目录
message("第二次在父目录，VAR1 = ${VAR1}")