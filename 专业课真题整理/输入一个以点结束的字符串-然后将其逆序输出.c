#include <stdio.h>

int main() {

  printf("请输入你想创建的字符串的长度，按回车确认："); int strLen; scanf("%d", &strLen);

  char str[strLen + 1];

  printf("请输入长度为 %d 且以 . 为结尾的字符串，按回车确认：", strLen);

  

  printf("您创建的字符串为："); printf("%s\n", str);

  return 0;
}