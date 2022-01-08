// 递归解

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

  for (int i = begin; i <= end; i ++) {
    swap(arr, i, begin);
    permutation(arr, begin + 1, end);
    swap(arr, i, begin);
  }

}

int main(void) {
  printf("请从 [3, 8] 中挑选一个数字："); int n; scanf("%d", &n);
  printf("数字 %d 的全排列如下：\n", n); int arr[n]; for (int i = 0; i < n; i ++) { arr[i] = i + 1; }
  permutation(arr, 0, n - 1);
  return 0;
}
