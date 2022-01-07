/**
 * 图，边 「无」 权值，邻接矩阵法存储边
 */

#include <stdio.h>

/*
  图的定义：
    图由 「顶点集」 & 「边集（顶点间的关系集）」 组成，顶点集非空
    任何一个边的两端都应该有顶点
*/

/*-- 定义图的顶点 --*/
typedef struct {
  char data;
} Vertex;
/*-- 定义图的顶点 --*/

/*-- 定义图 --*/
#define maxVertexNum 6 // 定义图的最大阶数（即图中最多有多少顶点）

typedef struct {
  Vertex vexs[maxVertexNum];             // 顺序的静态空间，用于存储顶点
  int edges[maxVertexNum][maxVertexNum]; // 邻接矩阵法存储图的 「边（顶点间的关系）」
  int vexNum; // 记录图的当前顶点数
  int edgNum; // 记录图的当前边/弧数
} Graph;
/*-- 定义图 --*/

int main() {
  return 0;
}
