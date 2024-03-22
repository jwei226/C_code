#include "List.h"
#include <stdio.h>

int main() {
	//定义一个单向链表
	List* list;
	list = list_create();

	//for (int i = 0; i < 6; i++)
	//{
	//	add_before_head(list, i);
	//}// 5 --> 4 --> 3 --> 2 --> 1 --> 0 

	for (int i = 0; i < 6; i++) {
		add_behind_tail(list, i);
	}// 0 --> 1 --> 2 --> 3 --> 4 --> 5


	
	return 0;
}