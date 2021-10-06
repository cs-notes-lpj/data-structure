/**
 * 顺序表
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

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

bool InsertList(SqList * list, int idx, int elem) {
  if (list->length == maxSize) {
    return false;
  }

  if (idx < 1 || idx > list->length + 1) {
    return false;
  }

  for (int i = list->length; i >= idx; i--) { // 这里 i 指位序，最小为 1
    list->data[i] = list->data[i - 1];
  }

  list->data[idx - 1] = elem;
  list->length++;
  return true;
}

void PrintList(SqList * list) {
  if (list->length == 0) {
    return;
  }

  for (int i = 0; i < list->length; i ++) { // 这里 i 指数组下标
    printf("位序：%d => %d\n", i + 1, list->data[i]);
  }
}

int main() {
  SqList list;
  InitList(&list);

  // 插入 5 个新结点，每个结点存储的数据为( 位序 + 100 )
  for (int i = 1; i < 6; i ++) {
    InsertList(&list, i, i + 100);
  }
  PrintList(&list);

  return 0;
}
