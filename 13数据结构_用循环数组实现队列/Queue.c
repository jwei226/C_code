#include"Queue.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define DEFAULT_CAPACITY 1024

Queue* queue_create(){
	//����һ������
	//��̬�����ڴ�ռ�
	Queue* q = malloc(sizeof(Queue));
	if (!q) {
		printf("Error: calloc failedn");
		exit(1);
	}
	q->elements = malloc(sizeof(E) * DEFAULT_CAPACITY);
	if (!q->elements)
	{
		printf("Error2: malloc failed,\n");
		free(q);//Ҫ�ͷ�q
		exit(1);
	}
	//��ʼ��
	/*q->capacity = DEFAULT_CAPACITY;*/
	q->size = 0;
	q->front = 0;
	q->rear = -1;//ָ����һ������Ԫ��λ�ã�����λ
	q->capacity = DEFAULT_CAPACITY;//
	return q;
}

void queue_destroy(Queue* q) {
	//���ٶ���
	//���ͷ�ѭ������
	free(q->elements);
	//���ͷ�q
	free(q);
}

void queue_expand_capacity(Queue* q) {
	//����
	//��̬�����ڴ�ռ�
	int new_capacity = 2 * q->capacity;
	E* new_store = calloc(new_capacity, sizeof(E));
	if (!new_store)
	{
		printf("Error: Calloc failed.\n");
		exit(1);
	}


	//����ԭ����Ԫ�ص��µ��ڴ�ռ�
	for (int i = 0; i < q->size; i++) {
		new_store[i] = q->elements[(q->front + i) % q->capacity];
		q->front = 0;
		q->rear = q->size - 1;
	}
	//�ͷ�ԭ�ڴ�
	free(q->elements);
	//������������
	q->elements = new_store;
	
	q->capacity = new_capacity;
}

void queue_push(Queue* q, E val) {
	//���
	//���п�
	/*if (queue_empty(q)) {
		printf("Error: Queue is empty.\n");
		return NULL;
	}*/
	if (q->size==q->capacity)
	{//������ʱ��Ҫ����
		queue_expand_capacity(q);
	}//�Ӳ�������������Ԫ��
	//
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
}

E queue_pop(Queue* q) {
	//����
	//���п�
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
	//�鿴��ͷԪ��
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