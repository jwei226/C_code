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

//函数声明：要实现哪些单链表的哪些方法

//创建一个单向链表
List* list_create(void);

//释放链表和所有结点的内存空间
void list_destroy(List* list);

//头插
void add_before_head(List* list, E val);

//尾插
void add_behind_tail(List* list, E val);

//任意索引值处添加结点
void add_node(List* list, int index, E val);

//删除值为val的结点
void destroy_node(List* list, E val);

//按索引查找
Node* find_by_index(List* list, int idx);

//按值查找
Node* search_by_value(List* list, E val);

//求链表中间结点的值
int middleElement(Node* list);

//判断单链表是否有环?
bool hasCircle(Node* list);

//反转单链表
Node* reverse(Node* list);

//合并两条有序的单向链表，使得合并后的链表也是有序的 
//(要求: 不能额外申请堆内存空间)。
Node* mergeTwoLists(Node* list1, Node* list2);