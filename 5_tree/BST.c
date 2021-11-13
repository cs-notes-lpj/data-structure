/**
 * 二叉排序树
 */

#include <stdio.h>
#include <stdlib.h>
typedef enum { false = 0, true } bool;

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

  // // 完全不用写
  // if (T == NULL || T->data == key) {
  //   return T;
  // }

  while (T != NULL && T->data != key) {

    T = key < T->data ? T->lChild : T->rChild;

  }

  // 蹦出循环的情况只有 2 种：（没找到 or 找到了）
  return T;

}

bool insert(BST_Tree * T, char key) {

  // 树空，则直接插入
  if ((*T) == NULL) {

    BST_Node * tmp = (BST_Node *)malloc(sizeof(BST_Node));
    if (tmp == NULL) {
      return false;
    }

    tmp->data = key;
    tmp->lChild = NULL;
    tmp->rChild = NULL;

    (*T) = tmp;

  }

  // （当前结点的关键字 == key），则拒绝插入
  if ((*T)->data == key) {
    return false;
  }

  if (key < (*T)->data) {
    BST_Tree lTree = (*T)->lChild;
    return insert(&lTree, key);
  } else {
    BST_Tree rTree = (*T)->rChild;
    return insert(&rTree, key);
  }

}

bool create_BST(BST_Tree * T, int arr[], int arrLen) {

  if (arrLen < 1) {
    return false;
  }

  *T = NULL;

  for (int i = 0; i < arrLen; i ++) {
    // &(*T) == T
    insert(T, arr[i]);
  }

  return true;

}

int main() {
  return 0;
}