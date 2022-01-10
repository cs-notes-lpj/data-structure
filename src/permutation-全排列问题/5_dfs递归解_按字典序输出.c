#include <stdio.h>

int path[8];                // 用来记录一条答案路径
int isVisited[8] = { 0 };   // 用来标记当前深搜到的结点是否被访问过
void _printPath(int arrLen);// 用来输出一条答案路径

void dfs_permutation(int arr[], int Idx, int arrLen) {

  // 当叶子结点也已经被遍历过时，打印当前的答案路径
  if (Idx == arrLen) {
    _printPath(arrLen);
  }

  for (int i = 0; i < arrLen; i ++) {
    if (!isVisited[i]) {
      path[Idx] = arr[i]; isVisited[i] = 1; // 访问
      dfs_permutation(arr, Idx + 1, arrLen);// 继续深搜
      isVisited[i] = 0;                     // 开始回溯
    }
  }
}

int main(void) {
  int arr[] = { 1, 2, 3 },
      arrLen = sizeof(arr) / sizeof(int);

  dfs_permutation(arr, 0, arrLen);
  return 0;
}

/*-- Utils are under below. --*/

void _printPath(int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
      printf("%d ", path[i]);
  }
  printf("\n");
}
