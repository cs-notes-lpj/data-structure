/**
 * 顺序表( 动态分配方式 )
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int * dataPtr;
  int curSize;
  int length;
} SqList;

#define defaultSize 5
#define defaultLen 0
SqList * InitList(SqList * list) {

  // 无论如何看见野指针赶紧置 NULL
  list->dataPtr = NULL;

  int * tmp = (int *)malloc(defaultSize * sizeof(int));
  if (tmp == NULL) {
    return NULL;
  }

  list->dataPtr = tmp;
  list->curSize = defaultSize;
  list->length = defaultLen;

  for (int i = 0; i < defaultSize; i ++) {
    list->dataPtr[i] = 0;
  }

  return list;

}

typedef enum { false = 0, true } bool;
// 按位序插入新结点
bool InsertList(SqList * list, int idx, int elem) {
  if (list->length == list->curSize) {
    return false;
  }

  if (idx < 1 || idx > list->length + 1) {
    return false;
  }

  for (int i = list->length; i >= idx; i --) { // 这里 i 指位序
    list->dataPtr[i] = list->dataPtr[i - 1];
  }

  list->dataPtr[idx - 1] = elem;
  (list->length)++;
  return true;

}

void PrintList(SqList list) {
  if (list.length == 0) {
    return;
  }

  for (int i = 0; i < list.length; i ++) { // 这里 i 指数组下标
    printf("%d\n", list.dataPtr[i]);
  }
}

int main() {

  SqList list;
  InitList(&list);


  // 插入 5 个新结点，每个结点存储的数据为( 位序 + 100 )
  for (int i = 1; i < 6; i ++) {
    InsertList(&list, i, i + 100);
  }
  PrintList(list);

  int newElem = 999;
  if (InsertList(&list, 3, newElem)) {
    PrintList(list);
  } else {
    printf("插入 %d 失败，因顺序表满，正尝试扩容并插入...", newElem);
    
  }

  return 0;
}
