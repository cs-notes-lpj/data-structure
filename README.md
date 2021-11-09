<img src='https://gitee.com/pj-l/imgs-1/raw/master/screenShot/head.png'></img>

#### 已实现的数据结构与算法

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

- 查找算法：find/
  - [x] 二分查找：erFenChaZhao.c

- 排序算法：sort/
  - [x] 直接插入排序 & 折半插入排序：insertSort.c
  - [x] 冒泡排序：bubbleSort.c
  - [x] 简单选择排序：simpleSelectSort.c

#### todo

对于中缀表达式 => 后缀表达式（逆波兰式）

```txt
// 2_stack/normal-2-reverse-polish-notation.c

目前只支持操作数是个位数
  输入：((5/(7-(1+1)))*3)-(2+(1+1))
  输出：5 7 1 1 + - / 3 * 2 1 1 + + -

待尝试操作数有多位数的情况
  输入：((15/(7-(1+1)))*3)-(2+(1+1))
  输出：15 7 1 1 + - / 3 * 2 1 1 + + -
```

有几种思路：

  1. 用单链表存，而不用数组存
  2. 建立表达式树，然后中序遍历
  3. 字符转整型，统一用 ascii 码存；即 int 数组
  4. 将 12 存成 '1' 和 '2', 统一用 char 型数组存，只不过在数组中添加空格，用来分割操作数和操作符
  5. 用指针型数组，即数组元素都是一个个的地址，这些地址有可能指向的是数，有可能指向的是字符

---
