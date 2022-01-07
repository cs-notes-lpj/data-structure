// 注意：结点元素起始位序为 1,为方便写代码，顺序存储也是从数组下标为 1 的位置开始存

#include <stdio.h>
#define Empty -9999

void _print(int arr[], int maxIdx) {
  for (int i = 1; i <= maxIdx; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 下坠函数
void _adjust(int arr[], int idx, int maxIdx) {

  // 拿住
  arr[0] = arr[idx];

  // 一趟趟下坠
  for (int i = idx * 2; i <= maxIdx; idx = i, i = idx * 2) {

    // 找大孩
    if (i < maxIdx && arr[i + 1] > arr[i]) { i++; }

    // 出口
    if (arr[i] <= arr[idx]) { return; }

    // 下坠一级
    arr[idx] = arr[i];
    arr[i] = arr[0];

  }

}

// 将完全二叉树自底向上调整为大根堆
void buildMaxHeap(int arr[], int maxIdx) {
  for (int i = maxIdx / 2; i >= 1; i --) {
    _adjust(arr, i, maxIdx);
  }
}

void maxHeapSort(int arr[], int maxIdx) {

  buildMaxHeap(arr, maxIdx);
  printf("大根堆："); _print(arr, maxIdx);

  while (maxIdx > 1) {

    arr[0] = arr[1];
    arr[1] = arr[maxIdx];
    arr[maxIdx] = arr[0];

    maxIdx--;
    _adjust(arr, 1, maxIdx);

  }
}

int main(void) {
  int arr[] = { Empty, 53, 45, 87, 32, 17, 65, 78, 9 },
      arrLen = sizeof(arr) / sizeof(int),
      maxIdx = arrLen - 1;

  maxHeapSort(arr, maxIdx);
  printf("升序排："); _print(arr, maxIdx);

  return 0;
}
