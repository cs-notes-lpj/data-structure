/**
 * 二叉链表（链式存储二叉树）的层次遍历
 * 思想：
 * 1. 初始化一个辅助队列
 * 2. 根结点入队
 * 3. 若队列非空，则队头结点出队，访问该结点，并将其左、右孩子插入队尾（如果有的话）
 * 4. 重复步骤 3 直至队列为空
 */

#include <stdio.h>

/*-- 定义二叉链表 --*/
struct Node {
  char data;
  struct Node * lchild;
  struct Node * rchild;
};

typedef struct Node BiNode;
typedef struct Node * BiTree;
/*-- 定义二叉链表 --*/

/*-- 定义链队列 --*/
typedef struct LinkedNode {
  BiNode * data; // 存指针比直接存二叉链表的结点要更节省内存空间
  struct LinkedNode * next;
} LinkedNode;

typedef struct {
  LinkedNode * head;
  LinkedNode * tail;
} LinkedQueue;
/*-- 定义链队列 --*/

void levelOredr(BiTree T) {
  if (T == NULL) {
    return;
  }

  // 初始化辅助队列
  LinkedQueue Q;
  if (InitLinkedQueue(&Q)) {

    // 根结点入队
    enQueue(&Q, T);

    while (!isEmpty(Q)) {
      BiNode tmp;
      deQueue(&Q, &tmp);

      visit(tmp);

      if (tmp.lchild != NULL) {
        enQueue(&Q, tmp.lchild);
      }
      if (tmp.rchild != NULL) {
        enQueue(&Q, tmp.rchild);
      }
    }

  }
}

int main() {
  return 0;
}

