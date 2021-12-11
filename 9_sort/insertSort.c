/**
 * 直接插入排序（类比摸扑克牌的思想~）
 */
#include <stdio.h>
#define Empty -9999 // 1. 使数组下标和元素位序保持一致 2. 可被用作数据缓存空间

void _printArr(int arr[], int arrLen) {
  for (int i = 1; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 注意：本算法 arr[0] 是个空位置
void insertSort(int arr[], int arrLen) {

  if (arrLen < 3) { return; }

  // 将待排序元素插入有序子序列中
  for (int i = 2; i < arrLen; i ++) {

    // 摸一张牌
    arr[0] = arr[i];

    // 从后往前一张张比大小，找要插入的位置
    int j;
    for (j = i - 1; j >= 1; j --) {
      if (arr[0] < arr[j]) {
        arr[j + 1] = arr[j];
      } else {
        break;
      }
    }

    // 插入
    arr[j + 1] = arr[0];

  }
}

int main() {
  int arr[] = { Empty, 2, 4, 1, 6, -1, 7, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  insertSort(arr, arrLen);
  _printArr(arr, arrLen);

  return 0;
}
