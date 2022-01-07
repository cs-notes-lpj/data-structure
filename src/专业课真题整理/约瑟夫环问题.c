#include <stdio.h>

int main(void) {

  // 首先，准备一个能容纳 n 个人的桌子
  printf("这一桌有几个人？输入后按回车确认："); int n; scanf("%d", &n); int arr[n];

  // 游戏开始前，每个人都未出列
  for (int i = 0; i < n; i ++) {
    arr[i] = 0;
  }

  // 定一个关键字吧，报到关键字的人就出列
  printf("报到几就出列？输入后按回车确认："); int key; scanf("%d", &key);

  // 游戏从第几个人开始呢？
  printf("从第几个人开始？输入后按回车确认："); int idx; scanf("%d", &idx);
  idx = idx - 1;
  if (idx < 0 || idx > n - 1) {
    return 0;
  }

  // 游戏从 1 开始报数
  int curNum = 1;

  /*---------游戏开始---------*/

  // 实时记录有多少人还没出列
  int people = n;

  while (people) {

    // 出列了的人跳过
    if (arr[idx] == 1) {
      idx = (idx + 1) % n;
    }

    // 没出列的人继续游戏
    if (arr[idx] == 0) {

      if (curNum != key) {

        curNum++;
        idx = (idx + 1) % n;

      } else {

        // 出列
        arr[idx] = 1;
        people = people - 1;
        printf("%d 号出列\n", idx + 1);

        curNum = 1;
        idx = (idx + 1) % n;

      }

    }

  }

  return 0;
}
