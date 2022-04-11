# 1、install
install()命令用于指定安装时运行的规则，可以安装目标二进制、动态库、静态库等。具体的参照<a href = "https://cmake.org/cmake/help/latest/command/install.html?highlight=install"> install命令官方文档 </a> 。
对于我们的CalculateSqrt这个项目来说，主要包括MathFunctions库、头文件MySqrt.h、可执行文件和默认的头文件。
（1）MathFunctions库：
在MathFunctions目录下的CMakeLists.txt添加：
```
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MySqrt.h DESTINATION include)
```
将MathFunctions库安装在lib文件夹下，MySqrt.h安装在include文件下。
（2）在CalculateSqrt 目录下的CMakeLists.txt添加：
```
install(TARGETS CalculateSqrt DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/CalculateSqrtConfig.h"
	DESTINATION include
)
```
这就是全部的内容了。
在命令行编译链接之后，输入
```
cmake --install .
```
可能会报错，显示：
```
 file INSTALL cannot set permissions on "/usr/local/bin/CalculateSqrt":
  Operation not permitted.
```
这是访问权限问题，将上条命令更改为
```
sudo cmake --install .
```
# 2、测试
测试主要是用ctest测试项目功能，具体的ctest内容参照<a href = "https://cmake.org/cmake/help/latest/manual/ctest.1.html">官方ctest文档</a> 。
ctest主要有两条命令，“enable_testing()”和“add_test()”，分别是启用测试和增加测试。
在顶层CMakeLists.txt最后添加：
```
# 测试
enable_testing()

# 添加测试，参数分别为NAME 测试名 COMMAND 测试命令
# 也就是测试CalculateSqrt 25是否能够运行
add_test(NAME Runs COMMAND CalculateSqrt 25)

# 测试
# 测试CalculateSqrt命令是否运行正确
add_test(NAME Usage COMMAND CalculateSqrt)
# 设置正确的测试输出结果，对比测试与正确结果
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "错误：输入应大于2"
  )

# 定义测试函数
# 函数名为do_test target名 参数 正确结果
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# 做一些基础测试
do_test(CalculateSqrt 4 "The square root of 4 is :2")
do_test(CalculateSqrt 9 "The square root of 9 is :3")
```
在命令行输入
```
ctest -VV
```
会输出详细的测试结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/1e2a4dba13444d269b3a5f51f6fdce91.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5Zue6aaW5oSB,size_20,color_FFFFFF,t_70,g_se,x_16)

<a href = "https://github.com/w-boom/LearningCMake">具体代码</a>