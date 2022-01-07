/*
  判断回文串

  读入一串字符，判断是否是 「回文串」

  「回文串」 指正读和反读都一样的字符串，比如 “level” 和 “noon” 就都是回文串

  输入格式：
    一行字符串，长度不超过 255
  输出格式：
    如果是“回文串”，输出“YES”，否则输出“NO”

  两种思路：
    双指针向中间夹
    或单指针遍历一半
*/

#include <stdio.h>
#include <string.h>

int isReverseStr(char str[], int strLen) {
  int left = 0,
      right = strLen - 1;

  while (left < right && str[left] == str[right]) {
    left ++;
    right --;
  }

  return left < right ? 0 : 1;

// ---------------------------------------

  // int left = 0,
  //     mid = strLen / 2;

  // int i;
  // for (i = 0; i < mid; i ++) {
  //   if (str[i] != str[strLen - 1 - i]) {
  //     break;
  //   }
  // }

  // return i < mid ? 0 : 1;
}

int main(void) {

  printf("请输入一个字符串："); char str[256]; scanf("%256s", str);

  if (isReverseStr(str, strlen(str))) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
