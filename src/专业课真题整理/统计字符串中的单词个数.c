/*
  输入一个长度小于 100 的字符串，输出它的单词个数
*/

#include <stdio.h>
#include <string.h>

int cntWords(char str[]) {
  int cnt = 0,
      flag = 0; // 不是字符

  int strLen = strlen(str);

  for (int i = 0; i < strLen; i ++)  {
    if (str[i] != ' ' && flag == 0) { cnt++; flag = 1; }
    if (str[i] == ' ') { flag = 0; }
  }

  return cnt;
}

int main(void) {

  // char str[100]; cin.getline(str, 100);
  char str[100] = "  asd aqwd  qwf   grwe a rr.";
  printf("单词个数为：%d\n", cntWords(str));

  return 0;
}
