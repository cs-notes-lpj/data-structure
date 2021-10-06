/**
 * 顺序表
*/

#include <stdio.h>

#define maxSize 10
typedef struct {
  int data[maxSize];
  int length;
} SqList;

void InitList(SqList * list) {

  for (int i = 0; i < maxSize; i++) {
    list->data[i] = 0;
  }

  list->length = 0;

}

int main() {
  SqList list;
  InitList(&list);
  return 0;
}
