/*
  输入一串字符，要求找出其中的连续数字并输出

  比如
    输入：ab123cd4f56
    输出：123456
*/

#include <stdio.h>
#include <string.h>

int isNum(char n) {

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

int main(void) {

  printf("请输入一串字符，按回车确认："); char arr[50]; scanf("%49s", arr);

  for (int i = 0; i < strlen(arr); i ++) {
    if (isNum(arr[i])) {
      printf("%c", arr[i]);
    }
  }

  printf("\n");
  return 0;
}