cmake_minimum_required(VERSION 3.08)

message("父目录 CMakeLists.txt 文件")
set(VAR1 "123456")

message("第一次在父目录 VAR1 = ${VAR1}")

# 函数定义
function(MyFunction VAR_F)
set(VAR_F "456" PARENT_SCOPE)
# set(VAR_F "789")
message("函数中， VAR1 = ${VAR_F}")
endfunction(MyFunction)

#函数调用
MyFunction(${VAR1})
message("函数调用后，VAR1 = ${VAR1}")

add_subdirectory(SubDirecTest)  # 添加子目录
message("第二次在父目录，VAR1 = ${VAR1}")