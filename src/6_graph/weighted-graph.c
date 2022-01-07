/**
 * 带权图，邻接矩阵法存储 「边的权值」
 */

#include <stdio.h>

typedef struct {
  char data;
} Vertex;

#define maxVertexNum 6
#define Infinity 999999 // 宏定义常量 => 「无穷」

typedef struct {
  Vertex vexs[maxVertexNum];
  int edges[maxVertexNum][maxVertexNum]; // 邻接矩阵法存储图的 「边的权值」
  int vexNum;
  int edgNum;
} WGraph;

int main() {
  return 0;
}
