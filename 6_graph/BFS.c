/**
 * 图的广度优先遍历
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

/*--定义图--*/
#define maxVexNum 10

// 顶点
typedef struct {
  char data;
} Vertex;

// 图（邻接矩阵法）
typedef struct {
  Vertex vexs[maxVexNum];
  int edges[maxVexNum][maxVexNum];

  int vexNum;
  int edgeNum;
} Graph;
/*--定义图--*/


/** 对图的广度优先遍历（本算法兼容 「非连通图」）
 * 
 * @param {Graph} G 图
 * 
 * - 注意：图的顶点集肯定非空
*/

// 设置一个标记数组，用来记录顶点是否被访问过
bool visited[maxVexNum];

// 设置辅助队列
Queue Q;

void BFS(Graph G) {

  // 初始化标记数组
  for (int i = 0; i < G.vexNum; i ++) {
    visited[i] = false;
  }

  // 初始化队列
  initQueue(&Q);

  // 兼容非连通图
  for (int i = 0; i < G.vexNum; i ++) {
    if (!visited[i]) {
      _foo(G, i);
    }
  }

}

/** 对极大连通子图的广度优先遍历
 * 
 * @param {Graph} G 图
 * @param {int}   v 顶点在数组中的下标，从这个顶点开始遍历
*/
void _foo(Graph G, int v) {

  // 顶点下标入队
  enQueue(&Q, v);

  // while ( 队列非空 ) { 出队; 访问; 打上顶点已访问的标记; 将其所有邻接顶点没有被访问过的入队; }

  while (!isEmpty(Q)) {

    int vex = deQueue(&Q); visit(vex); visited[vex] = true;

    for (int i = firstNeighbor(G, vex); i >= 0; i = nextNeighbor(G, vex, i)) {
      if (!visited[i]) {
        enQueue(&Q, i);
      }
    }

  }
}

int main(void) {
  return 0;
}
