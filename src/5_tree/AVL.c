/**
 * 平衡的二叉排序树（AVL树）
 */

#include <stdio.h>

/*-- 定义 AVL 树 --*/
struct Node {
  char data;
  struct Node * lChild;
  struct Node * rChild;
  int balance; // 结点的平衡因子
};

typedef struct Node AVL_Node;
typedef struct Node * AVL_Tree;
/*-- 定义 AVL 树 --*/

int main() {
  return 0;
}
