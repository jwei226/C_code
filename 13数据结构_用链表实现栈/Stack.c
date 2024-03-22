#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

Stack* stack_create(void) {
	//����һ��ջ
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
	//����ջ
	//���ͷ�ջ�����н��
	Node* curr = s->top;
	if (s)
	{
		s->top = s->top->next;
		free(curr);
	}
	//���ͷ�ջ
	free(s);
}

void stack_push(Stack* s, E val) {
	//��ջ�����Ƶ������ͷ�巨
	//����ͳ�ʼ���½��
	Node* newnode = malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = NULL;
	
	s->top = newnode;
	s->size++;
}

E stack_pop(Stack* s) {
	//��ջ������ջ����һ�����
	Node* pop;
	while (s->top)
	{//��ջ��Ϊ��ʱ
		pop = s->top;
		s->size--;
		s->top = s->top->next;
		return pop;
	}//��ʱջΪ��
	pop = s->top;
	return pop;
}

E stack_peek(Stack* s) {
	//�鿴ջ����һ������ֵ
	Node* curr;
	while (s->top)
	{//��ջ�ǿգ�topָ��ָ��ջ����һ��Ԫ��ʱ
		curr = s->top;
		return curr->val;
	}
	return NULL;
}

bool stack_empty(Stack* s) {
	//ջ���пգ��շ���false��������true
	if (s->size) return true;
	else return false;
}