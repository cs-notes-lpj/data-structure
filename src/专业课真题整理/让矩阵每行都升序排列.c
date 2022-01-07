/*
  编写一个处理矩阵的函数

  对于一个 m * n 的矩阵

  执行函数后使其每行元素的大小都按照升序排列
*/

#include <stdio.h>

int _partition(int arr[], int begin, int end) {

  // 选取中枢元素
  int pivot = arr[begin];

  while (begin < end) {

    while (arr[end] >= pivot && begin < end) { end--; }
    arr[begin] = arr[end];

    while (arr[begin] < pivot && begin < end) { begin++; }
    arr[end] = arr[begin];

  }

  // begin == end
  arr[begin] = pivot;
  return begin;
}

void _quickSort(int arr[], int begin, int end) {

  if (begin >= end) {
    return;
  }

  // 进行一次划分
  int mid = _partition(arr, begin, end);

  // 对左右分别快排
  _quickSort(arr, 0, mid - 1);
  _quickSort(arr, mid + 1, end);

}

void handleArr(int * arr, int row, int col) {
  for (int i = 0; i < row; i ++) {
    _quickSort(arr + col * i, 0, col - 1);
  }
}

int main(void) {

  int arr[4][5] = {
    { 2, -1, 7, -4, 8 },
    { 0, -6, -2, 8, 0 },
    { -7, -1, 9, 4, -1 },
    { 2, 2, -9, -9, 7 },
  };

  int col = sizeof(arr[0]) / sizeof(int),
      row = sizeof(arr) / sizeof(arr[0]);

  handleArr(arr, row, col);

  for (int i = 0; i < 4; i ++) {
    for (int j = 0; j < 5; j ++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}
