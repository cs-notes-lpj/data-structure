/**
 * 二分查找，仅适用于有序的顺序表
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

/**
 * 判断整数数组是否为有序的
 * @param {intArray} arr 整数数组
 * @param {int} arrLen 数组长度
 * - 有序：则返回 true
 * - 无序：则返回 false
*/
bool isArrOrdered(int arr[], int arrLen) {
  if (arrLen <= 0) { return false; }
  if (arrLen == 1) { printf("数组有序，且数组长度为 1\n"); return true; }

  int i = 0;
  while (arr[i] == arr[i + 1]) {
    i++;
    if (i + 1 >= arrLen) {
      printf("数组有序，且每个元素都是一样的\n");
      return true;
    }
  }

  if (arr[i] < arr[i + 1]) { // 数组不能降序

    for (int idx = i + 1; idx < arrLen - 1; idx ++) {
      if (arr[idx] > arr[idx + 1]) {
        return false;
      }
    }

    printf("数组有序，且为从小到大排\n");
    return true;
   
  } else { // 数组不能升序

    for (int idx = i + 1; idx < arrLen - 1; idx ++) {
      if (arr[idx] < arr[idx + 1]) {
        return false;
      }
    }

    printf("数组有序，且为从大到小排\n");
    return true;

  }
}

/**
 * 二分查找( 核心思想代码：[75, 77] & [83, 90] )
 * @param {intArray} arr 有序数组
 * @param {int} arrLen 数组长度
 * @param {int} dest 希望查找的元素
 * - 找到：则返回数组下标
 * - 未找到：则返回 -1
 */
int erFenChaZhao(int arr[], int arrLen, int dest) {
  if (arrLen <= 0) { return -1; }
  if (arrLen == 1) {
    return (dest == arr[0] ? 0 : -1);
  }

  if (!isArrOrdered(arr, arrLen)) {
    printf("本函数仅适用于有序的顺序表\n");
    return -1;
  }

  // 先只写升序数组的二分查找吧
  if (arr[0] <= arr[arrLen - 1]) {

    int low = 0,
        high = arrLen - 1,
        mid = (low + high) / 2;

    if (dest < arr[low] || dest > arr[high]) { return -1; }
    if (dest == arr[low]) { return low; }
    if (dest == arr[high]) { return high; }

    // 正式开始二分查找
    while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] == dest) { return mid; }
      if (arr[mid] < dest) { low = mid + 1; }
      if (arr[mid] > dest) { high = mid - 1; }
    }
    return -1;

  } else {
    printf("你传的是降序数组，和升序数组道理一样，就先不实现了（逃）\n");
    return 88888;
  }

}

int main() {

  int arr[] = { 1, 4, 6, 7, 9, 16, 22, 35, 87 },
      len = sizeof(arr) / sizeof(int),
      res = erFenChaZhao(arr, len, 22);

  if (res == -1) {
    printf("没找到...\n");
  } else {
    printf("查找成功，数组下标为：%d\n", res);
  }

/* 测试 isArrOrdered 函数的代码
  // success
  int testArr[] = { 1 },
      testArr2[] = { 1, 1, 1 },
      testArr3[] = { 1, 1, 2, 2, 3, 4, 4, 5 },
      testArr4[] = { 5, 5, 5, 4, 3, 3, 3, 2 };

  // failure
  int testArr5[] = { 1, 1, 1, 5, 4, 3, 2, 1 },
      testArr6[] = { 5, 5, 5, 4, 6, 3, 2, 1 };

  if (!isArrOrdered(testArr6, sizeof(testArr6) / sizeof(int))) {
    printf("无序\n");
  }
*/

  return 0;
}