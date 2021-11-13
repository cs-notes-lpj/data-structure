/**
 * 二叉排序树
 */

#include <stdio.h>

struct Node {
  char data;
  struct Node * lChild;
  struct Node * rChild;
};
typedef struct Node BST_Node;
typedef struct Node * BST_Tree;

/*
BST_Node * search(BST_Tree T, char key) {

  if (T == NULL || T->data == key) {
    return T;
  }

  if (key < T->data) {
    return search(T->lChild, key);
  }

  return search(T->rChild, key);

}
*/

// 非递归写法
BST_Node * search(BST_Tree T, char key) {

  if (T == NULL || T->data == key) {
    return T;
  }

  while (T != NULL && T->data != key) {

    T = key < T->data ? T->lChild : T->rChild;

  }

  // 蹦出循环的情况只有 2 种：（没找到 or 找到了）
  return T;

}

int main() {
  return 0;
}