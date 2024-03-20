//设计一个动态数组，当数组空间不够时，它可以自动扩容。
//
//typedef int E;
//
//typedef struct {
//    E* elements;   // 指向堆空间的数组
//    int size;	// 元素的个数
//    int capacity; // 数组的容量
//} Vector;
//
//// 请实现下面方法
//void push_back(Vector* v, E val);
//// 在数组最前面添加元素，所有元素依次后移
//void push_front(Vector* v, E val);
//// 删除最后一个元素, 并把最后一个元素返回
//E pop_back(Vector* v);
//// 删除第一个元素，并把第一个元素返回
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