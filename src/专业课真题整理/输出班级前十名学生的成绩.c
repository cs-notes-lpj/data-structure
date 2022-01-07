/*
  输入学生成绩，并按照输入顺序编号

  再按成绩进行降序排序

  最后输出前十名学生的成绩，如果学生人数不足十人则只输出仅有的学生成绩

  eg：X 号 xx 分
*/

#include <stdio.h>

typedef struct {
  int score;
  int number;
} Student;

int _partition(Student stu[], int begin, int end) {
  Student pivot = stu[begin];

  while (begin < end) {
    while (stu[end].score <= pivot.score && begin < end) { end--; }
    stu[begin] = stu[end];

    while (stu[begin].score > pivot.score && begin < end) { begin++; }
    stu[end] = stu[begin];
  }

  stu[begin] = pivot;
  return begin;
}

// 按成绩 「降序」 排列（基于快速排序的思想）
void sortByScore(Student stu[], int begin, int end) {
  if (begin >= end) {
    return;
  }

  int pos = _partition(stu, begin, end);
  sortByScore(stu, 0, pos - 1);
  sortByScore(stu, pos + 1, end);
}

void printTop10(Student stu[], int num) {
  for (int i = 0; i < num; i ++) {
    printf("%d 号 %d 分\n", stu[i].number, stu[i].score);
  }
}

int main(void) {

  printf("请输入学生人数，按回车确认："); int num; scanf("%d", &num); Student stu[num];

  for (int i = 0; i < num; i ++) {
    stu[i].number = i + 1;
    printf("请输入 %d 号学生的成绩，按回车确认：", stu[i].number);
    scanf("%d", &stu[i].score);
  }

  sortByScore(stu, 0, num - 1);
  printTop10(stu, num < 10 ? num : 10);
  return 0;
}
