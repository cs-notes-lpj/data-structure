/**
 * 二叉链表（链式存储二叉树）的
 *  先序遍历（先根遍历）：根左右
 *  中序遍历（中根遍历）：左根右
 *  后序遍历（后根遍历）：左右根
 * 递归
 */

#include <stdio.h>

struct Node {
  int data;
  struct Node * lchild;
  struct Node * rchild;
};

typedef struct Node BiNode;
typedef struct Node * BiTree;

/*-- 任意指定结点，找其前驱（土方法，伪代码） --*/
// BiNode * prePtr = NULL;
// BiNode * finalPtr = NULL;
// void visit(BiNode * curNode, BiNode * target) {
//   if (curNode != target) {
//     prePtr = curNode;
//   } else {
//     finalPtr = prePtr;
//   }
// }
/*-- 任意指定结点，找其前驱（土方法，伪代码） --*/

// 先序遍历
void preOrder(BiTree T) {
  if (T == NULL) { return; }
  
  visit(T);
  preOrder(T->lchild);
  preOrder(T->rchild);
}

// 中序遍历
void midOrder(BiTree T) {
  if (T == NULL) { return; }
  
  midOrder(T->lchild);
  visit(T);
  midOrder(T->rchild);
}

// 后序遍历
void postOrder(BiTree T) {
  if (T == NULL) { return; }
  
  postOrder(T->lchild);
  postOrder(T->rchild);
  visit(T);
}

// 求树的深度（后序遍历的应用）
int treeDepth(BiTree T) {
  if (T == NULL) { return 0; }

  int lDepth = treeDepth(T->lchild);
  int rDepth = treeDepth(T->rchild);
  return (lDepth > rDepth ? lDepth + 1 : rDepth + 1);
}

int main() {
  return 0;
}