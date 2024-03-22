#include"Queue.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define DEFAULT_CAPACITY 1024

Queue* queue_create(){
	//创建一个队列
	//动态分配内存空间
	Queue* q = malloc(sizeof(Queue));
	if (!q) {
		printf("Error: calloc failedn");
		exit(1);
	}
	q->elements = malloc(sizeof(E) * DEFAULT_CAPACITY);
	if (!q->elements)
	{
		printf("Error2: malloc failed,\n");
		free(q);//要释放q
		exit(1);
	}
	//初始化
	/*q->capacity = DEFAULT_CAPACITY;*/
	q->size = 0;
	q->front = 0;
	q->rear = -1;//指向下一个待插元素位置，留空位
	q->capacity = DEFAULT_CAPACITY;//
	return q;
}

void queue_destroy(Queue* q) {
	//销毁队列
	//先释放循环数组
	free(q->elements);
	//再释放q
	free(q);
}

void queue_expand_capacity(Queue* q) {
	//扩容
	//动态申请内存空间
	int new_capacity = 2 * q->capacity;
	E* new_store = calloc(new_capacity, sizeof(E));
	if (!new_store)
	{
		printf("Error: Calloc failed.\n");
		exit(1);
	}


	//复制原队中元素到新的内存空间
	for (int i = 0; i < q->size; i++) {
		new_store[i] = q->elements[(q->front + i) % q->capacity];
		q->front = 0;
		q->rear = q->size - 1;
	}
	//释放原内存
	free(q->elements);
	//更新整条队列
	q->elements = new_store;
	
	q->capacity = new_capacity;
}

void queue_push(Queue* q, E val) {
	//入队
	//先判空
	/*if (queue_empty(q)) {
		printf("Error: Queue is empty.\n");
		return NULL;
	}*/
	if (q->size==q->capacity)
	{//当队满时，要扩容
		queue_expand_capacity(q);
	}//队不满，正常新增元素
	//
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
}

E queue_pop(Queue* q) {
	//出队
	//先判空
	if (queue_empty(q)) {
		printf("Error: Queue is empty.\n");
		exit(1);
	}
	E pop = q->elements[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return pop;
}

E queue_peek(Queue* q) {
	//查看队头元素
	if (queue_empty(q)) {
		printf("Error: Queue is empty.\n");
		exit(1);
	}
	E peek = q->elements[q->front];
	return peek;
}

bool queue_empty(Queue* q) {
	if (q->size == 0) {
		return true;
	}else return false;	
}