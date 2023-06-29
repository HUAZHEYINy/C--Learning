# 职场老弟重学 C++
上次接触C++还是学生时代，再来接触下，整。以下是我的笔记，查漏补缺，没有任何先后顺序。

## 一些工具
1. [C++ Shell](https://cpp.sh/) 进行在线编译运行程序，简单快捷来验证猜想。
2. 最好的c++ 学习resources -  https://cplusplus.com/doc/tutorial/

## 一些主题
### Preprocessor Statement 
* 比如 # include 或者 # define etc. 
* it's evaludated before compilation; it's essentially copy and paste the file into the current file.
### [Compiler](https://stackoverflow.com/questions/6264249/how-does-the-compilation-linking-process-work#) 
1. Preprocessing - mentioned above; the output 是 pure c++ file without pre-procesor directives
2. Compiling - 
  * compiler 用pure c++ file作为input 产出object file; 
  * one object file per c++ file;  
  * object file中的dependency 可以使用declaration而不是真正的实现。
3. Linking - 
  * Linker 把object files 进行缝合在一起 产出 静态c++ lib 或者 executable binary - 比如在compiling 的时候我们只用了declaration，在linking阶段我们会把真正的definition找到并linking在一起。[Good resource](https://stackoverflow.com/questions/3368121/how-does-a-c-c-compiler-find-the-definitions-of-prototypes-in-header-files)
### L-value & R-value 
* Simply put - (not always true but most of the times) L-value is on the left side of the expression; R-value is on the right side of the expression.
* L-value is a permanent value which has storage in mem and R-value is a temporary value.
* Prior to C++ 11, only L-value and R-value exist; after that, we have L-value; R-value(pr-value or xvalue); glvalue. see [full list](https://en.cppreference.com/w/cpp/language/value_category) of values.
* L-value reference e.g std::string& is the reference of a L-value; R-value reference e.g std::string&& is the reference of a R-value. [NOTE: we can bind a const L-value reference to a R-value reference](https://stackoverflow.com/questions/40873500/binding-rvalue-to-const-lvalue-reference).
### Smart Pointer & Raw Pointer 
* Understand what is **Pointer**. [Very good resource!](https://cplusplus.com/doc/tutorial/pointers/)
* Understand what is **Stack** and **Heap**. [Good resource 1](https://courses.engr.illinois.edu/cs225/fa2022/resources/stack-heap/#:~:text=stack%20%3A%20stores%20local%20variables,stores%20the%20code%20being%20executed) and [Good resource 2](https://www.cs.fsu.edu/~myers/c++/notes/dma.html)
  * Stack stores the data that is not dynamically allocated e.g local variables; (global variable and static are different story. igonre them for now)
  * Heap stores the data that is allocated dynamically. e.g `MyClass* obj = new MyClass();` it **requires** us to remove the allocated memory once its done. e.g `delete obj;`
  * Storage Duration
    * **automatic** - the variables that are created without new and not static; it will be destroyed when it's out of scope.
    * **static** - the variables that are allocated before the program begins, and destroyed when the program ends.
    * **dynamic** - the variables that are created with `new` keyword; must use `delete`.
    * **thread** - the variables that are allocated in thread storage will be removed when threads end.
* Smart Pointer - e.g `std::unique_ptr, std::shared_ptr, std::weak_ptr` are here to help us remove the allocated memory **automatically** based on the smart pointer we used.
  * std::unique_ptr
    * single owner; when the single owner is out of scope, it will remove the memory automatically;
    * can not be re-assigned as copy constructor and assingment operator are deleted. Can only be `std::move`.
  * std::shared_ptr:
    * multiple owners - implemented using referencing counting; it will remove the memory only when all of the owners are out of scope.
    * can be re-assigeng which will increase the reference count; 
  * std::weak_ptr: no owner - it's like - check before use.
 
### Move Semantics 
TODO: Add more details
### Function Return Type
### Function Input Type 
### Lambda Expression
### Copy Constructor & Assigment Operator
TODO: Add more details.
### Co-routine 


## 一些基础中的基础
### Compiler
计算机很笨，只能理解一种语言就是机器语言(由0和1组成). 为了方便人类编程，人类开发出了高级语言(high level programming language 比如 java, C++). 

把高级语言 翻译成 机器语言 的程序就是编译器(compiler).

**题外话** - 通常情况下，我们说c++比java快，在编译运行的角度来说： 
* java 被compiler编译成bytecode(.class), 之后在JVM中运行的时候被JVM转化成机器语言.
* c++ 被compiler 直接编译成机器语言，可以直接运行。
* 注意: 因为java被编译成bytecode，这个bytecode是和JVM适配的，之后无论在什么机器上，只要有JVM 就可以运行这个java程序，这就是所谓的compile once and run anywhere(or platform independent); C++ 是需要根据在什么机器上跑，来使用对应的compiler.

### 为什么叫c++
c++的作者是 Bjarne Stroustrup(丹麦人), 他在C语言的基础上加上了面向对象的功能(当然还有其他)。另外，java的作者是 James Gosling (加拿大人).

### c++的版本
c++ 从最初的版本(1979年)开始到现在已经有大概7个阶段， 其中在C++ 98/03阶段我们加入了很多现在被广泛使用的一些功能比如smart pointer tec. 基本上C++11(2011) 之后现在广泛使用的工具都有了。Reference: [C++ History](https://en.cppreference.com/w/cpp/language/history)
