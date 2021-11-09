/**
 * 线索二叉树
 */

#include <stdio.h>

/*-- 定义线索二叉树的结点 --*/
struct Node {
  char data;
  struct Node * lChild;
  struct Node * rChild;
  int lTag;
  int rTag;
};

typedef struct Node cluesBiNode;
typedef struct Node * cluesBiTree;
/*-- 定义线索二叉树的结点 --*/

int main() {
  return 0;
}
