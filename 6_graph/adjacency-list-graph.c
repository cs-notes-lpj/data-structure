/*
  无向图，邻接表法
*/

#include <stdio.h>

/*--数据类型：边--*/
struct Edge {
  int idx;            // 存储_边所指向顶点_的_数组下标
  struct Edge* next;  // 指向下一条边
};

typedef struct Edge Edge;
/*--数据类型：边--*/

/*--数据类型：顶点--*/
typedef struct {
  char data;    // 数据域（存储顶点中的数据）
  Edge* first;  // 指向第一条边
} Node;
/*--数据类型：顶点--*/

#define maxVertexNum 10 // 让图的顶点数最多为 10（即图的阶最大为 10）

/*--数据类型：图（邻接表法存储）--*/
typedef struct {
  Node arr[maxVertexNum];
  int nodeNUm;            // 当前顶点数
  int edgeNum;            // 当前边数
} AGraph;
/*--数据类型：图（邻接表法存储）--*/

int main(void) {
  return 0;
}
