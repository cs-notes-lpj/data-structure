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

bool IncreaseSize(SqList * list, int growth) {

  int newSize = list->curSize + growth;

  int * tmp = (int *)malloc(sizeof(int) * (newSize));
  if (tmp == NULL) {
    return false;
  }

  int * oldData = list->dataPtr;

  list->dataPtr = tmp;
  list->curSize = newSize;
  for (int i = 0; i < list->curSize; i ++) {
    list->dataPtr[i] = 0;
  }

  for (int i = 0; i < list->length; i ++) {
    list->dataPtr[i] = oldData[i];
  }

  free(oldData);

  return true;

}

int main() {

  SqList list;
  InitList(&list);


  // 插入 5 个新结点，每个结点存储的数据为( 位序 + 100 )
  for (int i = 1; i < 6; i ++) {
    InsertList(&list, i, i + 100);
  }
  PrintList(list);


  // 新结点将要存储的数据元素，和将要插入的位序
  int newElem = 999, idx = 3;
  if (InsertList(&list, idx, newElem)) {
    PrintList(list);
  } else {

    printf("插入 %d 失败，因顺序表满，正尝试扩容并插入...\n", newElem);

    // 尝试将容量增至自身当前容量的 2 倍
    if (IncreaseSize(&list, list.curSize)) {

      // 扩容成功，再尝试插入新结点，插入成功则打印输出
      if (InsertList(&list, idx, newElem)) {
        printf("成功将 %d 插入到位序 %d\n", newElem, idx);
        PrintList(list);
      } else {
        printf("扩容成功，但 %d 插入位序 %d 失败...\n", newElem, idx);
      }

    } else {
      printf("扩容失败...\n");
    }

  }

  return 0;
}
