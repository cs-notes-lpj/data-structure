/*
  给定一个 n 个元素的整数数组 A，A 中连续的相等元素所形成的数据区域称为 「块」

  请设计算法，求 A 中最大块的长度
*/

#include <stdio.h>

int countMaxBlockLength(int arr[], int arrLen) {

  if ( arrLen < 1 ) { return 0; }

  int maxBlockLen = 1,
      key = arr[0],
      count = 1;

  for (int i = 1; i < arrLen; i ++) {
    if (arr[i] == key) {
      count++;
    } else {
      if (count > maxBlockLen) { maxBlockLen = count; }
      key = arr[i];
      count = 1;
    }
  }

  return maxBlockLen;

}

int main(void) {

  printf("请输入 n 的值，按回车确认："); int n; scanf("%d", &n); int arr[n];

  for (int i = 0; i < n; i ++) {
    scanf("%d", &arr[i]);
  }

  printf("最大块长度为：%d\n", countMaxBlockLength(arr, sizeof(arr) / sizeof(int)));

  return 0;
}
