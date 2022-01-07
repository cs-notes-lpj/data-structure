#include <stdio.h>
#include <string.h>

void reversePrint(const char * str, int strLen) {

  if (strLen <= 0) { return; }

  reversePrint(str + 1, strLen - 1);

  printf("%c", str[0]);

}

int main() {

  char str[] = "123456.";

  reversePrint(str, strlen(str));

  return 0;

}
