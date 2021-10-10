## 数据结构与算法代码实现

> 实现《数据结构与算法》课程中基本且重要的数据结构

#### 参考

王道 408 视频课程

[C 语言入门教程 - 阮一峰](https://wangdoc.com/clang/)

[linux 上搭建 C/C++ 开发环境](https://brannua.github.io/2021/10/04/%E7%A7%91%E6%99%AE%E4%B8%8E%E5%AE%9E%E8%B7%B5/vscode_cmake_cppdev_linux/)

#### C 语言没有布尔类型的变量

> C++ 有布尔类型但 C 没有，可是布尔类型能让代码可读性更高，所以模拟布尔类型

```c
// 方法一
typedef enum { false = 0, true } bool;
```

```c
// 方法二
typedef int bool;
#define true 1
#define false 0
```

#### free 掉某个结点可能会造成野指针，需特别注意！

```c
...
free(*list);
(*list) = NULL; // 一定得加这一行，否则出现野指针
...
```

#### 结构体的定义中不允许赋初始值

- 因为一个结构体的定义就相当于是在定义一种新的数据类型

#### 无论如何看见野指针赶紧置 NULL

- 避免野指针

#### 无论如何看见新开辟的内存空间（比如用 malloc 申请的，或是刚定义的一个数组），都应合理擦洗内存（处理内存脏数据的问题）

- 最简单可靠的方式就是遍历赋初值，当然也可用库函数 [fill](https://zh.cppreference.com/w/cpp/algorithm/fill)

- 注意：[memset](https://zh.cppreference.com/w/cpp/string/byte/memset) 不能用于擦洗内存

```c
for (int i = 0; i < maxSize; i ++) {
  list.data[i] = 0;
}
```

#### 结构体中静态数组的长度必须用 「常量」，而不能用 「只读变量」

- 「只读变量」 是在内存中开辟一个地方来存放它的值，只不过这个值由编译器限定不允许被修改，关键字 const 就是用来限定一个变量不允许被改变的修饰符（Qualifier）

- ANSI-C 规定：数组定义时长度必须是 「常量」

```c
// 定义顺序表（静态分配方式）
#define maxSize 10 // 不能用 const int maxSize = 10;
typedef struct {
  int data[maxSize];
  int length;
} SqList;
```

#### 封装函数应认真思考返回值的类型，应尽量避免避免不加思考直接写 void

- 确保代码的健壮性

#### 以线性表为例，如果不涉及结点的增删，只是单纯的 「读」 性质的操作，比如打印操作，参数的传递传 「镜像」 即可

- 避免误操作致使原对象结构被破坏

- 「镜像」 可理解为 「克隆」 「拷贝」，与 C 的传指针或 C++ 的传引用相异
