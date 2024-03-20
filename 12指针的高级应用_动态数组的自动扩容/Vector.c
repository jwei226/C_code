#include"Vector.h"
#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_CAPACITY 8//Ĭ�ϵ�elementsָ����ڴ�������С
#define MAX_PRE_ALLOC 1024//����ʱ�жϵ��ٽ��ڴ��С
Vector* vector_create(void) {
	//����һ��Vector�ڴ�ռ�
	Vector* v = malloc(sizeof(Vector));
	if (v == NULL) {
		//�Ƿ����ɹ�
		printf("Error1:malloc failed.\n");
		exit(1);
	}

	v->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
	if (v->elements == NULL)
	{
		printf("Error2:malloc failed.\n");
		exit(1);
	}

	v->size = 0;
	v->capacity = DEFAULT_CAPACITY;

}

void expand_capacity(Vector* v) {
	//��realloc��������
	int new_capacity;
	//��MAX_PRE_ALLOC�Ƚϣ�С����˫���������MAX_PRE_ALLOC�ֽڵ���
	/*if (v->capacity < MAX_PRE_ALLOC) {
		new_capacity = 2 * v->capacity;
	}
	else {
		new_capacity = v->capacity + MAX_PRE_ALLOC;
	}*/
	new_capacity = v->capacity > MAX_PRE_ALLOC ? v->capacity + MAX_PRE_ALLOC : 2 * v->capacity;

	//����
	E* ptr = realloc(v->elements, new_capacity * sizeof(v->elements));
	if (!ptr)
	{
		//�ж��Ƿ����ݳɹ�
		printf("Error3:realloc failed.\n");
		exit(1);
	}
	v->elements = ptr;//ָ���·�����ڴ�����
	v->capacity = new_capacity;//�·�����ڴ������
}


void push_back(Vector* v, E val) {
	//β��
	if (v->size == v->capacity)
	{
		expand_capacity(v);
	}
	v->elements[v->size++] = val;
}

void push_front(Vector* v, E val) {
	//ͷ��
	if (v->size == v->capacity) {
		//�����������������
		expand_capacity(v);
	}
	v->elements[0] = val;
	v->size++;
}


E pop_back(Vector* v) {
	//ɾ�����һ��Ԫ�أ��������һ��Ԫ��
	E back_element = v->elements[v->size - 1];
	/*free(v->elements[v->size - 1]);*/
	v->size--;
	return back_element;
}

E pop_front(Vector* v) {
	//ɾ����һ��Ԫ�أ����ص�һ��Ԫ��
	E front_element = v->elements[0];
	/*free(v->elements[0]);*/
	for (int i = 1; i < v->size-1; i++) {
		v->elements[i] = v->elements[i+1];
	}
	v->size--;
	return front_element;
}

void vector_destroy(Vector* v) {
	free(v->elements);
	free(v);
}