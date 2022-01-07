/**
 * 将二叉树中序线索化 ==得到==> 中序线索二叉树
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

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

/**
 * 初始化线索二叉树的结点
 * - tag == 0 表示指针指向孩子
 * - tag == 1 表示指针是「线索」
 */
bool InitCluesBiNode(cluesBiNode * node) {
  node->data = '*';
  node->lChild = NULL;
  node->rChild = NULL;

  node->lTag = 0;
  node->rTag = 0;
  return true;
}

cluesBiNode * _prePtr = NULL;

// 将结点线索化
void _visit(cluesBiNode * curNode) {

  if (curNode->lChild == NULL) {
    curNode->lChild = _prePtr;
    curNode->lTag = 1;
  }

  if (_prePtr != NULL && _prePtr->rChild == NULL) {
    _prePtr->rChild = curNode;
    _prePtr->rTag = 1;
  }

  _prePtr = curNode;

}

// 中序遍历二叉树
void _midOrder(cluesBiTree T) {
  if (T == NULL) { return; }

  _midOrder(T->lChild);
  _visit(T);
  _midOrder(T->rChild);
}


// 将二叉树中序线索化
void clueBiTree(cluesBiTree T) {
  if (T == NULL) { return; }

  // 初始化辅助变量（否则代码是一次性的，对二叉树执行一次中序线索化就把辅助变量污染了）
  _prePtr = NULL;

  // 一边中序遍历二叉树，一边将结点线索化
  _midOrder(T);

  // 把遍历的最后一个结点的 rChild 线索化
  if (_prePtr->rChild == NULL) {
    _prePtr->rTag = 1;
  }
}

int main() {
  return 0;
}
