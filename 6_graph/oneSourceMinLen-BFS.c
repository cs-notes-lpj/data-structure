/**
 * 单源最短路径问题的 BFS 算法实现 - 只适用于每条边的权值都相同的图
 */

#include <stdio.h>
typedef enum { false = true, true } bool;

// 再定义一遍图吧，谁让他老报错，烦死了
#define maxVertexNum 10
typedef struct {
  char vexs[maxVertexNum];
  int edgs[maxVertexNum][maxVertexNum];

  int vexNum;
  int edgeNum;
} Graph;

/*
  @param {Graph} G 连通图
  @param {int}   v 顶点的数组下标
*/
#define Infinity 99999
void BFS(Graph G, int v) {

  const int _vexNum = G.vexNum;

  int d[_vexNum],         // 用于记录顶点到源点的最短路径
      path[_vexNum],      // 用于记录顶点的直接前驱
      isVisited[_vexNum]; // 标记数组（Graph_only）

  for (int i = 0; i < _vexNum; i ++) {
    d[i] = Infinity;
    path[i] = -1;
    isVisited[i] = false;
  }

  d[v] = 0; // 源点到自身的最短路径是 0 呀

  /*--------------------BFS_Begin--------------------*/

  Queue q; initQueue(&q); enQueue(&q, v);

  while (!isEmpty(q)) {

    int vex = deQueue(&q); visit(vex); isVisited[vex] = true;

    const int curLen = d[vex] + 1;

    for (int i = firstNeighbor(G, vex); i >= 0; i = nextNeighbor(G, vex, i)) {
      if (!isVisited[i]) {
        path[i] = vex;    // 直接前驱是谁（从哪过来的）
        d[i] = curLen;    // 到源点的最短路径是多少
        enQueue(&q, i);
      }
    }

  }
}

int main(void) {
  return 0;
}