#include"List.h"
#include <stdio.h>
#include <stdlib.h>

List* list_create(void) {
	//����һ����������
	return calloc(1, sizeof(List));
}

//�ͷ���������н����ڴ�ռ�
void list_destroy(List* list) {
	//���ͷ����н�㣬��������
	Node* current;
	current = list->head;
	while (current)
	{
		//����һ��next�洢Ҫ�ͷŽ�����һ�����
		Node* next;
		next = current->next;
		free(current);
		/*current = current->next;����ʹ��δ��ʼ�����ڴ�current*/
		current = next;
	}
	//�ͷ�����
	free(list);

}

//ͷ��
void add_before_head(List* list, E val) {
	//��̬�����ڴ�ռ�
	Node* newnode = malloc(sizeof(Node));
	if (!newnode)
	{
		printf("Error: malloc failed.\n");
		exit(1);
	}
	//��ʼ���½��
	newnode->data = val;
	newnode->next = list->head;
	//�ı����������ָ��
	list->head = newnode;
	if (list->tail==NULL)
	{//����tailָ��
		list->tail = newnode;
	}
	list->size++;
}

//β��
void add_behind_tail(List* list, E val) {
	//��̬�����ڴ�ռ�
	Node* newnode = malloc(sizeof(Node));
	if (!newnode)
	{
		printf("Error: malloc failed.\n");
		exit(1);
	}
	//��ʼ���½��
	newnode->data = val;
	newnode->next = NULL;
	//��Ϊ����ĵ�һ�����
	if (list->tail==NULL)
	{
		list->head = newnode;
		list->tail = newnode;
		list->size++;
	}//tail��ָ��һ�������㣬��Ϊ��
	else
	{//����������
		/*newnode->next = list->tail->next;*/
		list->tail->next = newnode;
		list->tail = newnode;
		list->size++;
	}
}

//��������ֵ����ӽ��
void add_node(List* list, int index, E val) {
	//˳�������������
	Node* current;
	current = list->head;
	//��Ҫ�ҵ�����ֵΪindex-1�Ľ�㣬���
	for (int i = 0; i < index-1; i++)
	{

	}

}

//ɾ��ֵΪval�Ľ��
void destroy_node(List* list, E val);

//����������
Node* find_by_index(List* list, int idx);

//��ֵ����
Node* search_by_value(List* list, E val);

//�������м����ֵ
int middleElement(Node* list) {
	//����ָ�������һ������ָ��list���ÿ���ָ��
	Node* fast = list;
	Node* slow = list;
	while ((fast != NULL) || ((fast->next) != NULL)) {
		//ż�����������ָ��Ϊ�գ��������������ָ��Ϊ���һ�����
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//�жϵ������Ƿ��л�?
bool hasCircle(Node* list) {
	//�ܵ�����������ָ��������һ�����ͬʱɨ��
	Node* slow = list;
	Node* fast = list;
	while ((fast != NULL) && ((fast->next) != NULL)) {
		//��ָ��������������н��
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}//����ָ�벻����������û�л�
	return false;
	
}

//��ת������
Node* reverse(Node* list) {
	//ѭ�������Ƶ�����ͷ�巨
	if ((list != NULL) || ((list->next) != NULL)) {
		return list;
	}
	Node* prev = NULL;//��ת����ĵ�һ�����
	Node* current = list;//ָ��ǰ����ת�Ľ��
	Node* next = NULL;//�洢����ת������һ������ַ����ʼ��ΪNULL
	//ѭ��
	while (current != NULL) {
		//��������Ϊ����ȫ����ת��û�д���ת�Ľ��
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;//���ط�ת�������
	
}

//��ת������
//Node* reverse(Node* list) {
//	//�ݹ�
//	
//	if (list == NULL || list->next == NULL) return list;
//	Node* prev = reverse(list->next);
//	list->next->next = list;
//	list->next = NULL;
//	return prev;
//}

//�ϲ���������ĵ�������ʹ�úϲ��������Ҳ������� 
//(Ҫ��: ���ܶ���������ڴ�ռ�)��
Node* mergeTwoLists(Node* list1, Node* list2) {
	//ѭ�������Ƶ��������β�巨
	if (list1 == NULL) return list2;
	if (list2 == NULL) return list1;
	/*Node* head = (list1->data) > (list2->data) ? list2 : list1;*/
	Node* head;//ָ���������ϲ������н�С�ĵ�һ�����
	if (list1->data < list2->data) {
		head = list1;
		list1 = list1->next;
	}
	else {
		head = list2;
		list2 = list2->next;
	}
	Node* tail = head;//ָ����һ����������
	
	
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

////�ϲ���������ĵ�������ʹ�úϲ��������Ҳ������� 
////(Ҫ��: ���ܶ���������ڴ�ռ�)��
//Node* mergeTwoLists(Node* list1, Node* list2) {
//	//�ݹ鷨
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