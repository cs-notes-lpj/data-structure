<div align="center">

# 数据结构与算法的代码实现

<a href="https://www.github.com/brannua" target="_blank">
  <img src="https://img.shields.io/badge/author-Lpj-000000.svg?style=flat-square&logo=GitHub">
</a>
<a href="https://github.com/Brannua/ds_algorithm/blob/master/LICENSE" target="_blank">
  <img src="https://img.shields.io/badge/license-MIT-000000.svg?style=flat-square">
</a>

</div>

> 如果这个仓库对你有帮助，记得点个 star 🌟 哈，让我们一起向更优秀的 programmer 🏅 前进 ！

## docs

- [online](http://liupj.top/ds_algorithm/#/)

```sh
# offline
npm run serve
```

## 其他总结 & 参考

- [编码语法基础](https://zir7ybc667.feishu.cn/docs/doccnFK2tBJmocV4BCGkGzeFEXe)

- [用 cin.getline() 取代 gets()](https://zir7ybc667.feishu.cn/docs/doccnYC1giupn3EXvJRbctmSdOh)

- 参考了

  - C-翁恺-浙大-mooc

  - [C-软一峰](https://wangdoc.com/clang/)

  - [C++ 参考手册](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5)

  - 数据结构与算法-王道-mooc

  - 数据结构与算法-天勤-腾讯课堂

  - 数据结构与算法-王卓-青岛大学-bilibili

  - [算法笔记](https://zir7ybc667.feishu.cn/file/boxcnDdo3iqbVHyoubYA7AISyNb)

## 算法思想小结

- 递归思想
  - 想出口
  - 想递推
  - 注意但凡递归均可能 「栈溢出」

- 贪心算法不一定是最优解，可采用动态规划找最优解

- 动态规划思想
  - 将问题的求解划分为多个阶段，阶段之间有某种递进关系（所谓的状态转移方程）

- 不同算法思想可以结合使用，比如求解 0-1 背包问题时，动态规划思想所谓的状态转移方程其实就是递归的递推式

## 库函数使用注意事项

- 将主要精力放在题目的逻辑本身，题目中的某一步需要排序时，直接调用 C++ 的 ```sort``` 函数

- <string.h>
  - 以下两函数 「不安全」，应避免使用
    - ```char * strcpy(char *restrict dst, const char *restrict src);```
    - ```char * strcat(char *restrict s1, const char *restrict s2);```
  - 原因：目的地可能没有充足的空间；安全的替代品如下
    - ```char * strncpy(char *restrict dst, const char *restrict src, size_t n);```
    - ```char * strncat(char *restrict s1, const char *restrict s2, size_t n);```
  - 解释：新参数 ```size_t n``` 用来限制 「最多」 能够拷贝多少字符，即目的地还有多少空间可用
  - 更多关于 <string.h> 的知识参见自己的 .md 笔记总结

- <math.h>
  - 编译需添加 ```-lm``` 参数，否则可能报 ```undefined reference``` 的错误
  - 如 ```pow``` 函数

## 已实现的数据结构与算法

> In /src

- 线性表：1_linearList/
  - 顺序表
    - [x] 静态分配方式：SqList.c
    - [x] 动态分配方式：SqList-dynamic.c
  - 单链表
    - [x] 无头结点：LinkedList-single.c
    - [x] 有头结点：LinkedList-single-withHead.c
    - [x] 原地逆置有头结点的单链表：LinkedList-single-withHead-reverse.c
  - 双链表
    - [x] 有头结点：DoubleLinkedList-withHead.c
    - [ ] 无头结点
  - 循环链表
    - 循环单链表
      - [x] 有头结点：CircularSingleLinkedList.c
      - [ ] 无头结点
    - 循环双链表：
      - [x] 有头结点：CircularDoubleLinkedList.c
      - [ ] 无头结点
  - [x] 静态链表：StaticLinkedList.c
  - [x] 原地反转单链表.c

- 栈：2_stack/
  - [x] 顺序栈：SeqStack.c
  - [x] 共享栈：ShStack.c
  - [x] 链栈：LinkStack.c (与线性表不同，链栈推荐无头结点实现)
  - 用栈实现的括号匹配算法
    - [x] 原生语法：matchBrackets.c
    - [x] 用栈实现：matchBrackets-stack.c
  - 表达式求值问题
    - [x] 中缀表达式转后缀表达式：normal-2-reverse-polish-notation.c
    - [x] 计算后缀表达式：count-reverse-polish-notation.c
    - [ ] 计算中缀表达式：前两个算法的结合，开两个栈实现

- 队列：3_queue/
  - [x] 顺序存储实现的逻辑上的循环队列：SeqQueue.c
  - 链队列
    - [x] 有头结点：LinkedQueue-withHead.c
    - [x] 无头结点：LinkedQueue.c
  - [ ] 双端队列

- 串：4_string/
  - [x] 比较串的大小 & 子串拷贝 & 子串定位：string.c
  - [x] 字符串的朴素模式匹配算法（暴力解）：string.c
  - [x] KMP算法（优化解，掌握了 KMP 的优化思路和算法思想，掌握了根据模式串手算 next 数组的方法）：string.c

- 树：5_tree/
  - [x] 二叉链表（链式存储二叉树）的先、中、后序遍历 & 后序遍历的应用之求树高 & 任意指定结点，找其前驱（土方法，伪代码）：order.c
  - [x] 二叉链表（链式存储二叉树）的层次遍历：levelOrder.c
  - [x] 将二叉树中序线索化：cluesBiTree.c
  - [x] 将二叉树先序线索化：cluesBiTree-pre.c
  - [ ] 将二叉树后序线索化（同中序线索化）
  - [ ] 线索二叉树找前驱/后继（分析思路见笔记）
  - [x] 二叉排序树：BST.c
  - [x] 平衡的二叉排序树（AVL树）：AVL.c

- 图：6_graph/
  - [x] 图，边 「无」 权值，邻接矩阵法存储 「边」：graph.c
  - [x] 带权图，邻接矩阵法存储 「边的权值」：weighted-graph.c
  - [x] 无向图，邻接表法：adjacency-list-graph.c
  - [x] 图的广度优先遍历算法，兼容非连通图（伪代码）：BFS.c
  - [x] 图的深度优先遍历算法，兼容非连通图（伪代码）：DFS.c
  - [x] 单源最短路径问题-无权图-基于BFS算法：oneSourceMinLen-BFS.c
  - [ ] 有向无环图的拓朴排序和逆拓扑排序

- 堆：7_heap/
  - [x] 将完全二叉树自底向上调整为大根堆_&_基于大根堆的堆排序.c（逻辑视角_大根堆的构建，存储视角_基于大根堆的堆排序）

- 查找算法：8_find/
  - [x] 二分查找：erFenChaZhao.c

- 排序算法：9_sort/
  - [x] 直接插入排序：insertSort.c
  - [x] 折半插入排序：insertSort-erFen.c
  - [x] 希尔排序：shellSort.c
  - [x] 冒泡排序：bubbleSort.c
  - [x] 快速排序：quickSort.c
  - [x] 简单选择排序：simpleSelectSort.c
  - [x] 二路归并排序：mergeSort.c

- 手写string.h/
  - [x] my_strlen.c
  - [x] my_strcmp.c
  - [x] my_strcpy.c
  - [x] my_strcat.c

- 数组的传参方式/
  - [x] 一维数组的传参方式.c
  - [x] 二维数组的传参方式.c
  - [x] 矩阵转置.c

- permutation-全排列问题/
  - [x] 1_暴力解.c
  - [x] 2_递归解_输出顺序任意.c
  - [x] 3_递归解_输出顺序任意_考虑有重复的元素.c
  - [x] 4_递归解_按字典序输出.cpp
  - [x] 5_dfs递归解_按字典序输出.c
  - [x] 6_next_permutation.c
  - [x] 7_next_permutation_按字典序输出.cpp
  - [ ] 8_康托展开&逆康托展开.md

- 算法题目整理/
  - [x] 求e的值.c
  - [x] 进制转换.c
  - [x] 水仙花数.c
  - [x] 判断回文数.c
  - [x] 判断回文串.c
  - [x] 汉诺塔问题.c
  - [x] 杨辉三角形.c
  - [x] 简易计算器.c
  - [x] 大整数加法.c
  - [x] 大整数减法.c
  - [x] 0-1背包问题.c
  - [x] 约瑟夫环问题.c
  - [x] 数组循环右移.c
  - [x] 打印蛇形矩阵.c
  - [x] 输出空心正方形.c
  - [x] 从外向内顺时针打印螺旋矩阵.md
  - [x] 最大公约数问题.c
  - [x] 最小公倍数问题.c
  - [x] 英文句子倒着读.c
  - [x] 将数组乱序.c
  - [x] 数组去重-先排序.c
  - [x] 数组去重-保持原序.c
  - [x] 数组中只出现一次的数字.c
  - [x] 求正数的算术平方根.c
  - [x] 斐波纳契数列-用缓存.c
  - [x] 输出一个范围内的素数.c
  - [x] 递归法-求1到100的和.c
  - [x] 递归法-逆序输出正整数.c
  - [x] 递归法-逆序输出字符串.c
  - [x] 统计字符串中的单词个数.c
  - [x] 找出1000以内的所有完全数.c
  - [x] 分解正整数-从高位到低位依次输出.c
  - [x] 输入学生成绩-输出对应的分数等级.c
  - [x] 统计字符串中有多少整数，并依次输出.c
  - [x] 求整数数组中，连续相同元素的最大长度.c
  - [x] 输入一串字符，找出其中的连续数字并输出.c
  - [x] 按出生日期的先后输出同学们的名字.c
  - [x] 输入小明的出生年月日，输出截止到今天他经历了几个2月29.c
  - [x] 计算A年B月C日到X年Y月Z日的总天数_含出发和返回当天（一）.c
  - [x] 计算A年B月C日到X年Y月Z日的总天数_含出发和返回当天（二）.c
  - [x] 让矩阵每行都升序排列.c
  - [x] 输出班级前十名学生的成绩.c
  - [x] 任意输入4个数，由大到小输出它们.c
  - [x] 输入一个n阶矩阵，输出每一列的最大值的和.c
  - [x] 找出数组中任意一个重复的数字.c

## todo

- [ ] 对于中缀表达式 => 后缀表达式（逆波兰式）

```txt
// 2_stack/normal-2-reverse-polish-notation.c

目前只支持操作数是个位数
  输入：((5/(7-(1+1)))*3)-(2+(1+1))
  输出：5 7 1 1 + - / 3 * 2 1 1 + + -

待尝试操作数有多位数的情况
  输入：((15/(7-(1+1)))*3)-(2+(1+1))
  输出：15 7 1 1 + - / 3 * 2 1 1 + + -

有几种思路：
  1. 用单链表存，而不用数组存
  2. 建立表达式树，然后中序遍历
  3. 字符转整型，统一用 ascii 码存；即 int 数组
  4. 将 12 存成 '1' 和 '2', 统一用 char 型数组存，只不过在数组中添加空格，用来分割操作数和操作符
  5. 用指针型数组，即数组元素都是一个个的地址，这些地址有可能指向的是数，有可能指向的是字符
```
