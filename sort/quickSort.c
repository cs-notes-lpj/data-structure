/**
 * 快速排序
 */

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int _partition(int arr[], int low, int high) {

  // 规定中枢元素
  int pivot = arr[low];

  // 进行一次划分（比中枢元素小的都放左边，比中枢元素大的都放右边，两端交替逼近法）
  while (low < high) {

    // 从右边搬一个小的，放左边
    while (arr[high] >= pivot && low < high) { high--; }
    arr[low] = arr[high];

    // 从左边搬一个大的，放右边
    while (arr[low] < pivot && low < high) { low++; }
    arr[high] = arr[low];

  }

  // low == high，完成本次划分，返回中枢元素的位置
  arr[low] = pivot;
  return low;

}

void quickSort(int arr[], int low, int high) {

  if (low >= high) {
    return;
  }

  // 进行一次划分，变成俩子表
  int pos = _partition(arr, low, high);

  // 对左右俩子表分别进行快速排序
  quickSort(arr, low, pos-1);
  quickSort(arr, pos+1, high);

}

int main() {
  int arr[] = { 4, -1, 7, 0, 6, 2, 8, -4, 0, 2, -1 },
      arrLen = sizeof(arr) / sizeof(int);

  quickSort(arr, 0, arrLen - 1);
  _printArr(arr, arrLen);

  return 0;
}