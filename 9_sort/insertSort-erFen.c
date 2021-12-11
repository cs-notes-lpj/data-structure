/**
 * 折半插入排序（类比摸扑克牌的思想~）
 */
#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 折半插入排序
void insertSort_erFen(int arr[], int arrLen) {

  if (arrLen < 2) { return; }

  for (int i = 1; i < arrLen; i ++) {

    // 摸一张牌
    int tmp = arr[i];

    // 折半查找要插入的位置
    int low = 0,
        high = i - 1;

    for (int mid = (low + high) / 2; low <= high; mid = (low + high) / 2) {
      // 如果想让排序算法是稳定的，那么 arr[mid] == tmp 时，应继续在 mid 位置的右边寻找要插入的位置
      if (arr[mid] <= tmp) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    // 腾位置
    for (int j = i - 1; j >= low; j--) {
      arr[j + 1] = arr[j];
    }

    // 插入
    arr[low] = tmp;

  }
}

int main() {
  int arr[] = { 2, 4, 1, 6, -1, 8, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  insertSort_erFen(arr, arrLen);
  _printArr(arr, arrLen);

  return 0;
}
