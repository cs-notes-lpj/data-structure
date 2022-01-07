/**
 * 顺序表( 静态分配方式 )
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

#define maxSize 10
typedef struct {
  int data[maxSize];
  int length;
} SqList;

SqList * InitList(SqList * list) {

  for (int i = 0; i < maxSize; i++) {
    list->data[i] = 0;
  }

  list->length = 0;
  return list;
}

// 按位序插入新结点
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

void PrintList(SqList list) {
  if (list.length == 0) {
    return;
  }

  for (int i = 0; i < list.length; i ++) { // 这里 i 指数组下标
    printf("%d\n", list.data[i]);
  }
}

bool DeleteList(SqList * list, int idx, int * resNum) {
  if (idx < 1 || idx > list->length) {
    return false;
  }

  *resNum = list->data[idx - 1];

  for (int i = idx; i < list->length; i ++) {
    list->data[i - 1] = list->data[i];
  }
  (list->length)--;
  return true;
}

int GetItem(SqList list, int idx) {
  if (idx < 1 || idx > list.length) {
    return -1; // 这里将 -1 定义为没找到
  }

  return list.data[idx - 1];
}

int LocateElem(SqList list, int elem) {

  for (int i = 0; i < list.length; i ++) { // 这里 i 指数组下标
    if (list.data[i] == elem) {
      return i + 1;
    }
  }

  return -1; // 这里将 -1 定义为没找到

}

int main() {
  SqList list;
  InitList(&list);


  // 插入 5 个新结点，每个结点存储的数据为( 位序 + 100 )
  for (int i = 1; i < 6; i ++) {
    InsertList(&list, i, i + 100);
  }
  PrintList(list);


  // 删除位序为 3 的结点( 用 resNum 接被删结点的数据 )
  printf("--------------\n");
  int resNum = -1;
  if (DeleteList(&list, 3, &resNum)) {
    PrintList(list);
  }
  printf("被删结点存储的数据为：%d\n", resNum);


  // 查找位序为 2 的结点，返回其存储的数据
  printf("--------------\n");
  printf("%d\n", GetItem(list, 2));


  // 查找存储数据为 104 的结点，返回其位序
  printf("--------------\n");
  int tmp = 104;
  printf("%d 位续 => %d\n", tmp, LocateElem(list, tmp));


  return 0;
}
