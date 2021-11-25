/**
 * 单源最短路径问题-无权图-基于BFS算法（奶奶的BFS也只适用于无权图）
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
void BFS(Graph G, int v) {

  // 初始化一个标记数组
  int isVisited[G.vexNum];
  for (int i = 0; i < G.vexNum; i ++) {
    isVisited[i] = false;
  }

  // 初始化一个辅助队列
  Queue q; initQueue(&q);

  // 数组下标 v 入队
  enQueue(&q, v);

  while (!isEmpty(q)) {

    int vex = deQueue(&q); visit(vex); isVisited[vex] = true;

    for (int i = firstNeighbor(G, vex); i >= 0; i = nextNeighbor(G, vex, i)) {
      if (!isVisited[i]) {
        enQueue(&q, i);
      }
    }

  }
}

int main(void) {
  return 0;
}
