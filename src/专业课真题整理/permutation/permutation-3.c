/*
  增加一个难度：数组中有重复数字怎么办

  思路：如果要提到 begin 位置的数字已经在 begin 位置出现过，那就跳过这一次迭代
*/

#include <stdio.h>

void swap(int arr[], int i, int begin) {
  int tmp = arr[begin];
  arr[begin] = arr[i];
  arr[i] = tmp;
}

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void permutation(int arr[], int begin, int end) {

  if (begin > end) { return; }
  if (begin == end) { _printArr(arr, end + 1); return; }

  int _set[100] = { 0 }; // 用来记录数字是否已经在 begin 位置出现过

  for (int i = begin; i <= end; i ++) {

    if (_set[arr[i]] == 0) {
      _set[arr[i]] = 1;
    } else {
      continue;
    }

    swap(arr, i, begin);
    permutation(arr, begin + 1, end);
    swap(arr, i, begin);
  }

}

int main(void) {
  int arr[] = { 2, 2, 2, 3 },
      n = sizeof(arr) / sizeof(int);

  permutation(arr, 0, n - 1);
  return 0;
}
