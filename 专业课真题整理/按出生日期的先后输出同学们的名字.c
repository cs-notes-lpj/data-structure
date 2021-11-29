/*
  依次输入 5 名同学的出生年月日

  按出生日期输出他们的名字
*/

#include <stdio.h>
#define maxNameLen 10
#define stuNum 5

typedef struct {
  char name[maxNameLen];
  char birthday[11]; // eg: 2000-12-04
} Student;

// 简易版的字符串比较，因为本题规定了生日字符串的格式，故生日字符串一定等长
int _compareBirth(char birth_1[], char birth_2[]) {
  while (*birth_1 && *birth_2) {
    if (*birth_1 == *birth_2) {
      birth_1++;
      birth_2++;
    } else {
      return *birth_1 - *birth_2;
    }
  }

  return 0;
}

int _partition(Student stu[], int begin, int end) {
  Student pivot = stu[begin];

  while (begin < end) {
    while (_compareBirth(stu[end].birthday, pivot.birthday) >= 0 && begin < end) { end--; }
    stu[begin] = stu[end];
    while (_compareBirth(stu[begin].birthday, pivot.birthday) < 0 && begin < end) { begin++; }
    stu[end] = stu[begin];
  }

  stu[begin] = pivot;
  return begin;
}

void quickSortByBirth(Student stu[], int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pos = _partition(stu, begin, end);
  quickSortByBirth(stu, 0, pos - 1);
  quickSortByBirth(stu, pos + 1, end);
}

int main(void) {

  printf("请逐个输入学生的生日，输入格式为：YYYY-MM-dd，每输入一个学生的生日就按一次回车...\n");
  Student stu[stuNum];

  for (int i = 0; i < stuNum; i ++) {
    printf("第 %d 位学生的名字是：", i + 1); scanf("%s", stu[i].name);
    printf("「%s」的生日为：", stu[i].name); scanf("%s", stu[i].birthday);
  }

  quickSortByBirth(stu, 0, stuNum - 1);

  for (int i = 0; i < stuNum; i ++) {
    printf("%s : %s\n", stu[i].name, stu[i].birthday);
  }

  return 0;
}
