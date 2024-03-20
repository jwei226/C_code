//���һ����̬���飬������ռ䲻��ʱ���������Զ����ݡ�
//
//typedef int E;
//
//typedef struct {
//    E* elements;   // ָ��ѿռ������
//    int size;	// Ԫ�صĸ���
//    int capacity; // ���������
//} Vector;
//
//// ��ʵ�����淽��
//void push_back(Vector* v, E val);
//// ��������ǰ�����Ԫ�أ�����Ԫ�����κ���
//void push_front(Vector* v, E val);
//// ɾ�����һ��Ԫ��, �������һ��Ԫ�ط���
//E pop_back(Vector* v);
//// ɾ����һ��Ԫ�أ����ѵ�һ��Ԫ�ط���
//E pop_front(Vector* v);

#include"Vector.h"
#include<stdio.h>
#include<stdlib.h>

void vector_print(Vector* v) {
	for (int i = 0; i < v->size; i++)
	{
		printf("%d  ",v->elements[i]);
		
	}
	printf("\n---------------------------------------------\n");
}
int main() {
	Vector* v = vector_create();
	for (int i = 0; i < 10; i++) {
		push_back(v, i);
	}
	vector_print(v);
	push_front(v, 666);
	vector_print(v);
	pop_back(v);
	pop_front(v);
	vector_print(v);
	vector_destroy(v);
	return 0;

}