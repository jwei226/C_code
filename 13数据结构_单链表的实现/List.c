#include"List.h"
#include <stdio.h>
#include <stdlib.h>

List* list_create(void) {
	//创建一个单向链表
	return calloc(1, sizeof(List));
}

//释放链表和所有结点的内存空间
void list_destroy(List* list) {
	//先释放所有结点，遍历链表
	Node* current;
	current = list->head;
	while (current)
	{
		//定义一个next存储要释放结点的下一个结点
		Node* next;
		next = current->next;
		free(current);
		/*current = current->next;警告使用未初始化的内存current*/
		current = next;
	}
	//释放链表
	free(list);

}

//头插
void add_before_head(List* list, E val) {
	//动态申请内存空间
	Node* newnode = malloc(sizeof(Node));
	if (!newnode)
	{
		printf("Error: malloc failed.\n");
		exit(1);
	}
	//初始化新结点
	newnode->data = val;
	newnode->next = list->head;
	//改变整条链表的指向
	list->head = newnode;
	if (list->tail==NULL)
	{//处理tail指向
		list->tail = newnode;
	}
	list->size++;
}

//尾插
void add_behind_tail(List* list, E val) {
	//动态分配内存空间
	Node* newnode = malloc(sizeof(Node));
	if (!newnode)
	{
		printf("Error: malloc failed.\n");
		exit(1);
	}
	//初始化新结点
	newnode->data = val;
	newnode->next = NULL;
	//若为插入的第一个结点
	if (list->tail==NULL)
	{
		list->head = newnode;
		list->tail = newnode;
		list->size++;
	}//tail必指向一个具体结点，不为空
	else
	{//正常插入结点
		/*newnode->next = list->tail->next;*/
		list->tail->next = newnode;
		list->tail = newnode;
		list->size++;
	}
}

//任意索引值处添加结点
void add_node(List* list, int index, E val) {
	//顺序遍历整个链表
	Node* current;
	current = list->head;
	//先要找到索引值为index-1的结点，后插
	for (int i = 0; i < index-1; i++)
	{

	}

}

//删除值为val的结点
void destroy_node(List* list, E val);

//按索引查找
Node* find_by_index(List* list, int idx);

//按值查找
Node* search_by_value(List* list, E val);

//求链表中间结点的值
int middleElement(Node* list) {
	//传入指向链表第一个结点的指针list，用快慢指针
	Node* fast = list;
	Node* slow = list;
	while ((fast != NULL) || ((fast->next) != NULL)) {
		//偶数个结点最后快指针为空，奇数个结点最后快指针为最后一个结点
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//判断单链表是否有环?
bool hasCircle(Node* list) {
	//跑道：两个快慢指针从链表第一个结点同时扫描
	Node* slow = list;
	Node* fast = list;
	while ((fast != NULL) && ((fast->next) != NULL)) {
		//快指针遍历完链表所有结点
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}//快慢指针不相遇，链表没有环
	return false;
	
}

//反转单链表
Node* reverse(Node* list) {
	//循环，类似单链表头插法
	if ((list != NULL) || ((list->next) != NULL)) {
		return list;
	}
	Node* prev = NULL;//反转链表的第一个结点
	Node* current = list;//指向当前待反转的结点
	Node* next = NULL;//存储待反转结点的下一个结点地址，初始化为NULL
	//循环
	while (current != NULL) {
		//结束条件为链表全部反转，没有待反转的结点
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;//返回反转后的链表
	
}

//反转单链表
//Node* reverse(Node* list) {
//	//递归
//	
//	if (list == NULL || list->next == NULL) return list;
//	Node* prev = reverse(list->next);
//	list->next->next = list;
//	list->next = NULL;
//	return prev;
//}

//合并两条有序的单向链表，使得合并后的链表也是有序的 
//(要求: 不能额外申请堆内存空间)。
Node* mergeTwoLists(Node* list1, Node* list2) {
	//循环，类似单向链表的尾插法
	if (list1 == NULL) return list2;
	if (list2 == NULL) return list1;
	/*Node* head = (list1->data) > (list2->data) ? list2 : list1;*/
	Node* head;//指向两个待合并链表中较小的第一个结点
	if (list1->data < list2->data) {
		head = list1;
		list1 = list1->next;
	}
	else {
		head = list2;
		list2 = list2->next;
	}
	Node* tail = head;//指向下一个待插入结点
	
	
	while ((list1 != NULL) && (list2 != NULL)) {
		if ((list1->data <(list2->data)) ){
			tail->next = list1;
			list1 = list1->next;
			
		}
		else {
			tail->data = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	/*if ((list1 == NULL)&&(list2 != NULL)) {
		tail->next = list2;
	}
	else if ((list2 == NULL)&&(list1 != NULL)) {
		tail->next = list1;
	}*/
	tail->next = list1 != NULL ? list1 : list2;
	return head;
}

////合并两条有序的单向链表，使得合并后的链表也是有序的 
////(要求: 不能额外申请堆内存空间)。
//Node* mergeTwoLists(Node* list1, Node* list2) {
//	//递归法
//	if (list1 == NULL) return list2;
//	if (list2 == NULL) return list1;
//
//	Node* head = list1->data < list2->data ? list1 : list2;
//	if (list1->data < list2->data) {
//		head = list1;
//		head->next = mergeTwoLists(list1->next, list2);
//	}
//	else
//	{
//		head = list2;
//		head->next = mergeTwoLists(list1, list2->next);
//	}
//	return head;
//}