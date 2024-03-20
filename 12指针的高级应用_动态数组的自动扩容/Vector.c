#include"Vector.h"
#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_CAPACITY 8//默认的elements指向的内存容量大小
#define MAX_PRE_ALLOC 1024//扩容时判断的临界内存大小
Vector* vector_create(void) {
	//分配一个Vector内存空间
	Vector* v = malloc(sizeof(Vector));
	if (v == NULL) {
		//是否分配成功
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
	//用realloc函数扩容
	int new_capacity;
	//和MAX_PRE_ALLOC比较，小的扩双倍，大的扩MAX_PRE_ALLOC字节的容
	/*if (v->capacity < MAX_PRE_ALLOC) {
		new_capacity = 2 * v->capacity;
	}
	else {
		new_capacity = v->capacity + MAX_PRE_ALLOC;
	}*/
	new_capacity = v->capacity > MAX_PRE_ALLOC ? v->capacity + MAX_PRE_ALLOC : 2 * v->capacity;

	//扩容
	E* ptr = realloc(v->elements, new_capacity * sizeof(v->elements));
	if (!ptr)
	{
		//判断是否扩容成功
		printf("Error3:realloc failed.\n");
		exit(1);
	}
	v->elements = ptr;//指向新分配的内存区域
	v->capacity = new_capacity;//新分配的内存块数量
}


void push_back(Vector* v, E val) {
	//尾插
	if (v->size == v->capacity)
	{
		expand_capacity(v);
	}
	v->elements[v->size++] = val;
}

void push_front(Vector* v, E val) {
	//头插
	if (v->size == v->capacity) {
		//如果容量已满，扩容
		expand_capacity(v);
	}
	v->elements[0] = val;
	v->size++;
}


E pop_back(Vector* v) {
	//删除最后一个元素，返回最后一个元素
	E back_element = v->elements[v->size - 1];
	/*free(v->elements[v->size - 1]);*/
	v->size--;
	return back_element;
}

E pop_front(Vector* v) {
	//删除第一个元素，返回第一个元素
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