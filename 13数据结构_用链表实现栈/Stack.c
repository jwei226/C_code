#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

Stack* stack_create(void) {
	//创建一个栈
	Stack* s= malloc(1, sizeof(Stack));
	if (!s)
	{
		printf("Error: malloc failed,\n");
		exit(1);
	}
	s->size = 0;
	s->top = NULL;
	return s;
}

void stack_destroy(Stack* s) {
	//销毁栈
	//先释放栈中所有结点
	Node* curr = s->top;
	if (s)
	{
		s->top = s->top->next;
		free(curr);
	}
	//再释放栈
	free(s);
}

void stack_push(Stack* s, E val) {
	//入栈，类似单链表的头插法
	//定义和初始化新结点
	Node* newnode = malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = NULL;
	
	s->top = newnode;
	s->size++;
}

E stack_pop(Stack* s) {
	//出栈，返回栈顶第一个结点
	Node* pop;
	while (s->top)
	{//当栈不为空时
		pop = s->top;
		s->size--;
		s->top = s->top->next;
		return pop;
	}//此时栈为空
	pop = s->top;
	return pop;
}

E stack_peek(Stack* s) {
	//查看栈顶第一个结点的值
	Node* curr;
	while (s->top)
	{//当栈非空，top指针指向栈顶第一个元素时
		curr = s->top;
		return curr->val;
	}
	return NULL;
}

bool stack_empty(Stack* s) {
	//栈的判空，空返回false，满返回true
	if (s->size) return true;
	else return false;
}