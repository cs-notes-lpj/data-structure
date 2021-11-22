/*
  学生成绩根据不同的分数段可以对应不同的分数等级

  如：

    90～100 ：A
    80～89 ：B
    70～79 ：C
    60～69 ：D
    < 60 ：E

  要求输入成绩，输出对应的分数等级
*/

#include <stdio.h>

int main(void) {

  printf("请输入学生成绩（百分制），按回车确认："); int score; scanf("%d", &score);

  if (score < 0 || score > 100) { return 0; }

  char tab[] = { 'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A' };

  printf("%c\n", tab[score / 10]);

  return 0;
}
