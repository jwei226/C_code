#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int E;

typedef struct node {
	E data;
	struct node* next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
	int size;
}List;

//����������Ҫʵ����Щ���������Щ����

//����һ����������
List* list_create(void);

//�ͷ���������н����ڴ�ռ�
void list_destroy(List* list);

//ͷ��
void add_before_head(List* list, E val);

//β��
void add_behind_tail(List* list, E val);

//��������ֵ����ӽ��
void add_node(List* list, int index, E val);

//ɾ��ֵΪval�Ľ��
void destroy_node(List* list, E val);

//����������
Node* find_by_index(List* list, int idx);

//��ֵ����
Node* search_by_value(List* list, E val);

//�������м����ֵ
int middleElement(Node* list);

//�жϵ������Ƿ��л�?
bool hasCircle(Node* list);

//��ת������
Node* reverse(Node* list);

//�ϲ���������ĵ�������ʹ�úϲ��������Ҳ������� 
//(Ҫ��: ���ܶ���������ڴ�ռ�)��
Node* mergeTwoLists(Node* list1, Node* list2);