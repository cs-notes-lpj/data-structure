/*
  输入一个字符串，内有数字和非数字字符，如 xy12ab93?5786$

  连续的数字成为一个整数，比如上述字符串中有 3 个整数：12、93、5786

  统计字符串中有多少个整数，并依次输出
*/

#include <stdio.h>
#include <string.h>

int isNum(int n) {
  switch (n) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return 1;
    default:
      return 0;
  }
}

int cntInt(char * str) {

  int cnt = 0,
      flag = 0;

  int len = strlen(str);

  for (int i = 0; i < len; i ++) {

    if (isNum(str[i])) {

      printf("%c", str[i]);

      if (flag == 0) { cnt++; flag = 1; }

    } else {

      if (flag) { printf(" "); flag = 0; }

    }
  }

  return cnt;

}

int main() {

  printf("请输入字符串，按回车确认："); char str[50]; scanf("%49s", str); 

  printf("整数个数：%d\n", cntInt(str));

  return 0;
}
