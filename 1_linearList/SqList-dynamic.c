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

#define defaultSize 10
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

int main() {

  SqList list;
  InitList(&list);

  return 0;
}
