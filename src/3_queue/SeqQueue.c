/**
 * 使用顺序存储的方式
 * 实现逻辑上的循环队列
 */
#include <stdio.h>
typedef enum { false = 0, true } bool;

/*-- 顺序存储定义的数据结构：「队列」 --*/
#define maxSize 10 // 本实现由于判队满的方式，最多存 maxSize - 1 个数据元素
typedef struct {
  int data[maxSize];
  int front; // 队头指针
  int rear;  // 队尾指针，本实现中规定队尾指针指向下一个入队元素将要存放的位置
} SeqQueue;
/*-- 顺序存储定义的数据结构：「队列」 --*/

// 初始化队列
bool InitSeqQueue(SeqQueue * sq) {
  sq->front = 0;
  sq->rear = 0;

  // 看见静态数组就擦洗内存，清空脏数据
  for (int i = 0; i < maxSize; i ++) {
    sq->data[i] = 0;
  }
  return true;
}

// 队列判空
bool IsQueueEmpty(SeqQueue sq) {
  return (sq.front == sq.rear);
}

// 队列判满
bool IsQueueFull(SeqQueue sq) {
  return ((sq.rear + 1) % maxSize == sq.front);
}

// 入队
bool EnQueue(SeqQueue * sq, int num) {
  // 队满，则拒绝入队
  if (IsQueueFull(*sq)) {
    printf("队满，拒绝入队...\n");
    return false;
  }

  // 从队尾入队 + 修改队尾指针
  sq->data[sq->rear] = num;
  sq->rear = (sq->rear + 1) % maxSize; // 逻辑上的循环队列！
  return true;
}

// 计算队列长度
int getQueueLen(SeqQueue sq) {
  if (IsQueueEmpty(sq)) {
    return 0;
  }

  return ((sq.rear - sq.front + maxSize) % maxSize);
}

// 出队
int DeQueue(SeqQueue * sq) {
  // 队空，则拒绝出队
  if (IsQueueEmpty(*sq)) {
    return false;
  }

  // 从队头出队 + 修改队头指针
  int res = sq->data[sq->front];
  sq->front = (sq->front + 1) % maxSize; // 逻辑上的循环队列！
  return res;
}

int main() {

  SeqQueue sq;
  if (InitSeqQueue(&sq) && IsQueueEmpty(sq)) {
    printf("恭喜！成功定义并初始化了一个空队列\n");
  }

  for (int i = 0; i < 12; i ++) {
    EnQueue(&sq, i);
  }

  for (int i = 0; i < 6; i ++) {
    DeQueue(&sq);
  }

  for (int i = 0; i < 5; i ++) {
    EnQueue(&sq, i);
  }

  for (int i = 0; i < 6; i ++) {
    DeQueue(&sq);
  }

  printf("队列此时的长度为：%d\n", getQueueLen(sq));

  while (!IsQueueEmpty(sq)) {
    printf("%d ", DeQueue(&sq));
  }
  printf("\n");

  return 0;
}