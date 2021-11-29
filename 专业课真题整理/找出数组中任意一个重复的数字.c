/*
  在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内

  数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次

  请找出数组中任意一个重复的数字

  输入：
    [2, 3, 1, 0, 2, 5, 3]
  输出：
    2 或 3
*/

#include <stdio.h>

int findOneDuplicatedNum(int arr[], int arrLen) {

  for (int i = 0; i < arrLen; i ++) {
    while (arr[i] != i) {
      int tmp = arr[i];
      if (arr[tmp] == tmp) {
        return tmp;
      } else {
        arr[i] = arr[tmp];
        arr[tmp] = tmp;
      }
    }
  }

  return -1;
  
}

int main(void) {

  int arr[] = { 2, 3, 1, 0, 2, 5, 3 },
      arrLen = sizeof(arr) / sizeof(int);

  printf("%d\n", findOneDuplicatedNum(arr, arrLen));

  return 0;
}