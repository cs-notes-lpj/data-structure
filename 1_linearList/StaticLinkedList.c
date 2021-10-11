/**
 * 静态链表
 * 静态<=>数组，容量固定不可变
*/

#include <stdio.h>

struct Node {
  int data;
  int next;
};

#define maxSize 10
typedef struct Node SLinkedList[maxSize];

int main() {

  SLinkedList slist;
  printf("%d\n", sizeof(slist));

  return 0;
}