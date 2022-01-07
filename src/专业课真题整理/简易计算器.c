/*
  编写一个简易计算器

  要求具备加减乘除和退出的功能
*/

#include <stdio.h>

void _prompt() {
  printf("=========欢迎使用简易计算器=========\n");
  printf("0 ----> exit\n");
  printf("1 ----> +\n");
  printf("2 ----> -\n");
  printf("3 ----> *\n");
  printf("4 ----> /\n");
}

void count(int curOp, float num1, float num2) {
  float res = 0.0;
  switch (curOp) {
    case 1: res = num1 + num2; break;
    case 2: res = num1 - num2; break;
    case 3: res = num1 * num2; break;
    case 4: res = num1 / num2; break;
    default: break;
  }
  printf("result=%f\n", res);
}

int main(void) {
  _prompt();

  int curOp;
  float num1 = 0.0,
        num2 = 0.0;

  while (1) {
    printf("请选择你想进行的操作：");
    scanf("%d", &curOp);
    if (curOp == 0) {
      break;
    }

    printf("请输入两个操作数，用逗号分隔，按回车确认：");
    scanf("%f,%f", &num1, &num2);
    count(curOp, num1, num2);
  }

  printf("Bye~\n");
  return 0;
}
