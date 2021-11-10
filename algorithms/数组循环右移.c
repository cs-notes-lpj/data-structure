/**
 * 数组循环右移
 * [1 2 3 4 5] =循环右移 3 位=> [3 4 5 1 2]
 * 每个元素被翻转两次，一共 n 个元素，因此总时间复杂度为 O(2n)=O(n)
 * 空间复杂度：O(1)
 * 
 * https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
 */

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void _swap(int * a, int * b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * 反转数组
 * 支持数组的部分反转
 * eg: [1, 2, 3, 4] => low = 2 & high = 3 => [1, 2, 4, 3]
 */
void _reverseArr(int arr[], int arrLen, int low, int high) {
  if (arrLen < 2 || low < 0 || high > arrLen - 1) {
    return;
  }

  while (low < high) {
    _swap(&arr[low], &arr[high]);
    low++;
    high--;
  }
}

/**
 * 数组循环右移 step 位
 */
void arrXunHuanYouYi(int arr[], int arrLen, int step) {
  if (arrLen < 2 || step < 1) {
    return;
  }

  // 将整个数组 reverse
  _reverseArr(arr, arrLen, 0, arrLen - 1);

  // 将前 step 位 reverse
  _reverseArr(arr, arrLen, 0, step - 1);

  // 将后 arrLen - step 位 reverse
  _reverseArr(arr, arrLen, step, arrLen - 1);

}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 },
      arrLen = sizeof(arr) / sizeof(int);

  arrXunHuanYouYi(arr, arrLen, 3);
  _printArr(arr, arrLen);

  return 0;
}