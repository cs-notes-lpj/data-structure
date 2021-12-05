/*
概述：
  有两个日期，求两个日期之间的天数，如果两个日期是连续的，则规定它们之间的天数为两天。
问题：
  输入格式：
    有多组数据，每组数据有两行，分别表示两个日期，形式为 YYYYMMDD
  输出格式：
    每组数据输出一行，即日期差值
样例：
  输入样例：
  20130101
  20130105
  输出样例：
  5
*/

// 思路：令日期不断加 1 天，直到第一个日期等于第二个日期为止，即可统计出答案。
//      如果当加了一天之后天数 d 等于当前月份 m 所拥有的天数加 1，那么就令月份 m 加 1，同时置天数 d 为 1 号
//      如果此时月份变为了 13，那么就令年份 y 加 1，同时置月份 m 为 1 月

#include <stdio.h>

// 平年 2 月 28 天，平年一年 365 天；闰年 2 月 29 天，闰年一年 366 天
int month[12][2] = {{31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

// 判断闰年
int isLeapYear(int year) {
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int main(void) {

  int time1, time2; scanf("%d", &time1); scanf("%d", &time2);

  if (time1 == time2) { printf("两个日期相同\n"); return 0; }
  if (time1 > time2) { int tmp = time1; time1 = time2; time2 = tmp; }

  int y1, m1, d1, y2, m2, d2;
  y1 = time1 / 10000; m1 = time1 % 10000 / 100; d1 = time1 % 100;
  y2 = time2 / 10000; m2 = time2 % 10000 / 100; d2 = time2 % 100;

  int res = 1;

  while (y2 - y1 > 1) {
    res += (isLeapYear(y1) ? 366 : 365);
    y1 ++;
  }

  // 逐天累加
  while (!(y1 == y2 && m1 == m2 && d1 == d2)) {
    d1++;
    if (d1 == month[m1 - 1][isLeapYear(y1)] + 1) {
      m1++; d1 = 1;
    }
    if (m1 == 13) {
      y1++; m1 = 1;
    }
    res++;
  }

  printf("%d\n", res);
  return 0;
}
