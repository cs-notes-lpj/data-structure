/**
 * 链队列（单链表的阉割版：只允许从队头删除，从队尾插入）
 * 无头结点
 */

#include <stdio.h>
#include <stdlib.h>
typedef enum { false = 0, true } bool;

/*-- 定义链式队列的结点 --*/
struct LinkNode {
  int data;
  struct LinkNode * next;
};

typedef struct LinkNode LinkNode;
/*-- 定义链式队列的结点 --*/

/*-- 定义链队列 --*/
typedef struct {
  LinkNode * front; // 队头指针
  LinkNode * rear;  // 队尾指针，本实现中 rear 始终指向队尾结点
} LinkedQueue;
/*-- 定义链队列 --*/

// 初始化队列
bool InitSeqQueue(LinkedQueue * lq) {
  lq->front = NULL;
  lq->rear = NULL;
  return true;
}

// 队列判空
bool IsQueueEmpty(LinkedQueue lq) {
  return (lq.front == NULL && lq.rear == NULL);
}

// 入队
bool EnQueue(LinkedQueue * lq, int num) {
  // 尝试为新结点申请内存
  LinkNode * tmp = (LinkNode *)malloc(sizeof(LinkNode));
  if (tmp == NULL) {
    return false;
  }

  tmp->data = num;
  tmp->next = NULL;

  if (IsQueueEmpty(*lq)) { // 当插入第一个数据元素时需要特殊处理
    lq->front = tmp;
    lq->rear = tmp;
  } else {
    // 队尾入队 + 更新队尾指针
    lq->rear->next = tmp;
    lq->rear = tmp;
  }
  
  return true;

}

// 出队
int DeQueue(LinkedQueue * lq) {
  // 队空，则拒绝出队
  if (IsQueueEmpty(*lq)) {
    printf("队空，拒绝出队...\n");
    return -99999;
  }

  // 首先缓存住待出队结点（因为要手动 free 它的内存）
  LinkNode * tmp = lq->front;
  int res = tmp->data;

  // 从队头出队（更新头结点的 next 指向）
  lq->front = tmp->next;

  // 如果此次是最后一个结点出队，则需要修改队尾指针
  if (tmp == lq->rear) {
    lq->rear = lq->front;
  }

  // 手动释放回收内存
  free(tmp);
  return res;
}

// 计算队列长度
int getQueueLen(LinkedQueue lq) {
  int res;
  LinkNode * ptr = lq.front;
  for (res = 0; ptr != NULL; ptr = ptr->next) {
    res++;
  }
  return res;
}

int main() {

  LinkedQueue lq;
  if (InitSeqQueue(&lq) && IsQueueEmpty(lq)) {
    printf("恭喜！成功定义并初始化了一个空的无头结点的链队列\n");
  }

  for (int i = 0; i < 12; i ++) {
    EnQueue(&lq, i);
  }

  for (int i = 0; i < 6; i ++) {
    DeQueue(&lq);
  }

  for (int i = 0; i < 5; i ++) {
    EnQueue(&lq, i);
  }

  for (int i = 0; i < 6; i ++) {
    DeQueue(&lq);
  }

  printf("队列此时的长度为：%d\n", getQueueLen(lq));

  while (!IsQueueEmpty(lq)) {
    printf("%d ", DeQueue(&lq));
  }
  printf("\n");

  return 0;
}