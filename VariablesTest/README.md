测试变量：

cmake中有两种变量类型normal变量、cache变量
# normal变量
1、通过在父目录和子目录中分别改变变量的值
2、函数

** normal变量的作用域是以CMakeLists.txt文件为基本单位
** PARENT_SCOPE normal变量加上PARENT_SCOPE便可以在父目录或新函数上起作用

注：一定要注意cmake是不需要逗号的，编辑函数时习惯性加了逗号，调试了好久


# cache变量
有点像是全局变量
1、当第一次运行cmake时，cache变量缓存到CMakeCache.txt中；再次运行cmake，变量会直接使用缓存值
2、使用cache变量需要设定<type>和<docstring>，即变量类型和描述
FILEPATH = File chooser dialog.
PATH     = Directory chooser dialog.
STRING   = Arbitrary string.
BOOL     = Boolean ON/OFF checkbox.
INTERNAL = No GUI entry (used for persistent variables).（内部变量）
3、如果原缓存(cache)中有该变量，不会改变原缓存中该变量的值，除非后面使用FORCE。