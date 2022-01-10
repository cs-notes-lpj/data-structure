/**
 * 冒泡排序（基于交换的排序）
 */

#include <stdio.h>

void _printArr(int arr[], int begin, int end);
void _swap(int arr[], int a, int b);

void bubbleSort(int arr[], int begin, int end) {

  // 数组中至少得有俩元素，你才能排序
  if (begin >= end) {
    return;
  }

  // 控制冒泡趟数
  for (int i = begin; i < end; i ++) {

    int _flag = 1;

    // 一趟冒泡
    for (int j = begin; j < end - i; j ++) { // 3. end - i 是因为只需对还未排序的子序列进行排序
      // 1. 保障排序算法的稳定性
      if (arr[j] > arr[j + 1]) {
        _swap(arr, j, j + 1);
        _flag = 0;
      }
    }

    // 2. 如果在一趟冒泡中没有发生元素交换，说明已经排好序，结束即可
    if (_flag) {
      break;
    }

  }
}

int main() {
  int arr[] = { 2, 4, 1, 6, -1, 8, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  bubbleSort(arr, 0, arrLen - 1);
  _printArr(arr, 0, arrLen - 1);
  return 0;
}

/*-- Utils are under below. --*/

void _swap(int arr[], int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void _printArr(int arr[], int begin, int end) {
  for (int i = begin; i <= end; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
