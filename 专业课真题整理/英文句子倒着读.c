/*
  输入："one two  three"

  输出："three  two one"
*/

#include <stdio.h>
#include <string.h>

void reverseStr(char str[], int begin, int end) {
  if (begin >= end) {
    return;
  }

  while (begin < end) {
    char tmp = str[begin];
    str[begin] = str[end];
    str[end] = tmp;
    begin ++;
    end --;
  }
}

void reversePrint(char str[], int strLen) {

  if (strLen < 2) {
    return;
  }

  // 首先将整个字符串反过来
  reverseStr(str, 0, strLen - 1);

  // 然后将各个单词再反过来
  int slow = 0,
      quick = 0;

  for (int i = 0; i < strLen; i ++) {
    if ((i == 0 && str[i] != ' ') || (i != 0 && str[i] != ' ' && str[i - 1] == ' ')) {
      slow = i;
    }
    if (str[i] == ' ' && str[i - 1] != ' ') {
      quick = i - 1;
      reverseStr(str, slow, quick);
    }
    if (i == strLen - 1 && str[i] != ' ') {
      quick = i;
      reverseStr(str, slow, quick);
    }
  }

}

int main(void) {

  char str[] = "   one two  three ";

  reversePrint(str, strlen(str));

  printf("###%s###\n", str);

  return 0;
}

// // 以下为 JavaScript 的实现
// function reverseByWord(str = '') {
//   console.log(str.split(' '));
//   console.log(str.split(' ').reverse());
//   console.log(str.split(' ').reverse().join(' '));
// }
// reverseByWord('one two    three');
