
尝试给项目添加一个库，还是以上一篇的CalculateSqrt为例。
# 1、新建库
新建一个子目录，命名为MathFunctions。在该目录下新建MySqrt.h和MySqrt.cpp，MySqrt.h为函数声明，MySqrt.cpp为实现文件， 不调用math.h中的sqrt()函数，自己实现平方根的计算。当然为了检验方便，可以直接返回形参两倍值。
同样，MathFunctions目录下也需要构建CMakeLists.txt，将其设定为库，并添加源文件：
```
add_library(MathFunctions MySqrt.h MySqrt.cpp)
```
# 2、顶层调用
为了使用这个新库，我们将在顶级CMakeLists中使用add_subdirectory()添加库调用。
```
# 添加库
add_subdirectory(MathFunctions)
```
然后将新库添加到可执行文件中，并将MathFunctions库添加到包含目录中，以便能够找到MySgrt.h头文件。
```
target_link_libraries(CalculateSqrt PUBLIC MathFunctions)

#包含头文件
target_include_directories(
 	CalculateSqrt 
 	PUBLIC 
 	"${PROJECT_BINARY_DIR}"
 	"${PROJECT_SOURCE_DIR}/MathFunctions"
 	)
 ```
修改main.cpp文件，添加MySqrt.h文件的包含并调用该函数
```
#include "MySqrt.h"
```
这样就简单地添加了MathFunctions库
# 3、尝试使用开关项
对于我们设计的MySqrt()函数，功能比较简单，很容易就能检测出是否正确，但有些情况下可能会涉及与库函数比较；或者，当math.h头文件无法找到，只能使用MySqrt.h。此时，需要设计一个开关项，用户可以设置是否使用MySqrt()函数。
设置开关项：
```
# 设置开关项默认为ON
option(USE_MYMATH "Use MySqrt provided math implementation" ON)
```
设置开关项ON、OFF时相应的操作。如果为USE_MYMATH为ON，需要添加MathFunctions库；为OFF，则不用。后续的包含头文件也是类似的操作。使用list语句（相当于构建了一个类似与python中的list数据结构），
```
list(APPEND <list> [<element> ...])
```
创建一个变量名为<list>的变量，并将<element>添加append（附加）到list中。如<list>已有，则只执行append操作。
整体语句如下：
```
# 设置开关项相应操作
if(USE_MYMATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
	list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 添加文件
add_executable(CalculateSqrt main.cpp)

target_link_libraries(CalculateSqrt PUBLIC ${EXTRA_LIBS})

#包含头文件
target_include_directories(
 	CalculateSqrt 
 	PUBLIC 
 	"${PROJECT_BINARY_DIR}"
 	"${EXTRA_INCLUDES}")
```
相应地，要将该变量传递到源文件中，CalculateSqrtConfig.h.in中定义USE_MYMATH:
```
#cmakedefine USE_MYMATH
```
在main.cpp中加入:
```
#ifdef USE_MYMATH
#include "MySqrt.h"
#endif

// 在调用处加入
#ifdef USE_MYMATH
		const int outputValue = MySqrt(inputValue);
#else
		const int outputValue = sqrt(inputValue);
#endif
```
定义了开关项之后，在命令行中设置开关项：
```
cmake .. -D USE_MYMATH=ON
cmake --build .
./CalculateSqrt 9
```
为了验证USE_MYMATH有没有起作用，可以将MySqrt()函数先设置为2倍值。
# 4、问题
尝试过程中出现报错，找不到MySqrt()函数，后续发现是由于main.cpp中将
```
#ifdef USE_MYMATH
#include "MySqrt.h"
#endif
```
放在
```
#include "CalculateSqrtConfig.h"
```
之前，还没定义就开始使用导致的。
# 5、拓展
（1）除了在config.h.in中定义开关项之外，也可以在CMakeLists.txt文件中用以下命令定义：
```
target_compile_definitions(CalculateSqrt PRIVATE USE_MYMATH)
```
（2）像这种标准库函数的开关项，其实也可以用cmake中的CheckSymbolExists检查库函数是否可以使用，如果不能使用再设置使用自定义函数。