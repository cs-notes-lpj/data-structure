/**
 * 图的深度优先遍历
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

#define maxVertexNum 10

/**
 * @param {Graph} G 图
 *
 * - 注意：图的顶点集一定 「非空」
 * - 注意：新找到的相邻结点有可能被访问过，故设置了一个标记数组
 */

bool isVisit[maxVertexNum];

void DFS(Graph G) {

  // 初始化标记数组
  for (int i = 0; i < G.vertexNum; i ++) {
    isVisit[i] = false;
  }

  // 兼容非连通图
  for (int i = 0; i < G.vertexNum; i++) {
    if (isVisit[i] == false) {
      _foo(G, i);
    }
  }

}

/** 极大连通子图进行深度优先遍历
 * 
 * @param {Graph} G  图
 * @param {int}   v  某顶点的数组下标，从该顶点开始，深度优先遍历整个图
 */

void _foo(Graph G, int v) {

  visit(v); isVisit[v] = true;

  for (int i = firstNeighbor(G, v); i >= 0; i = nextNeighbor(G, v, i)) {
    if (!isVisit[i]) {
      DFS(G, i);
    }
  }

}

int main(void) {
  return 0;
}