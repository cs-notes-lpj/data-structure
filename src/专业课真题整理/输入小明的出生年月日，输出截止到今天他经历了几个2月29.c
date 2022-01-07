/*
  输入小刘同学的出生年月日

  输出截止到今天他经历了几个 2 月 29
*/

#include <stdio.h>

int _isLeapYear(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int cnt_2_29_num(int year, int month, int day, int thisYear, int thisMonth) {

  int cnt = 0;

  for (int i = year; i < thisYear; i ++) {
    if (_isLeapYear(i)) {
      printf("%d\n", i);
      cnt++;
    }
  }

  if (_isLeapYear(thisYear) && thisMonth > 2) {
    cnt++;
  }

  return cnt;

}

int main(void) {

  int y,
      m,
      d;

  char author[] = "小刘同学"; 

  printf("请输入%s的生日，输入格式为 YYYY-MM-DD，按回车确认：", author); char birthday[11]; scanf("%s", birthday);

  sscanf(birthday, "%d-%d-%d", &y, &m, &d); printf("%d 年 %d 月 %d 日，%s破壳而出啦~\n", y, m, d, author);

  printf("%s迄今为止经历了 %d 个 2 月 29.\n", author, cnt_2_29_num(y, m, d, 2021, 11));

  return 0;
}