## 数据结构与算法代码实现

> 实现《数据结构与算法》课程中基本且重要的数据结构 - 参考：王道 & 天勤

#### 已实现的数据结构与算法

- [x] 线性表：1_linearList/
  - [x] 顺序表
    - [x] 静态分配方式：SqList.c
    - [x] 动态分配方式：SqList-dynamic.c
  - [x] 单链表
    - [x] 无头结点：LinkedList-single.c
    - [x] 有头结点：LinkedList-single-withHead.c
    - [x] 原地逆置有头结点的单链表：LinkedList-single-withHead-reverse.c
  - [x] 双链表
    - [x] 有头结点：DoubleLinkedList-withHead.c
    - [ ] 无头结点
  - [x] 循环链表
    - [x] 循环单链表
      - [x] 有头结点：CircularSingleLinkedList.c
      - [ ] 无头结点
    - [x] 循环双链表：
      - [x] 有头结点：CircularDoubleLinkedList.c
      - [ ] 无头结点
  - [x] 静态链表：StaticLinkedList.c

- [x] 栈：2_stack/
  - [x] 顺序栈：SeqStack.c
  - [x] 共享栈：ShStack.c
  - [x] 链栈：LinkStack.c (与线性表不同，链栈推荐无头结点实现)
  - [x] 用栈实现的括号匹配算法
    - [x] 原生语法：matchBrackets.c
    - [x] 用栈实现：matchBrackets-stack.c
  - [ ] 表达式求值问题
    - [x] 中缀表达式转后缀表达式：normal-2-reverse-polish-notation.c
    - [x] 计算后缀表达式：count-reverse-polish-notation.c
    - [ ] 计算中缀表达式：前两个算法的结合，开两个栈实现
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
