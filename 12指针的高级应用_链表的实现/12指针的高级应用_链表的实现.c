//假设结点的定义如下，请实现下面功能：
//
//typedef struct node_s {
//    int data;
//    struct node_s* next;
//} Node;
//(a)采用头插法，在链表中插入元素
//
//void add_before_head(Node** plist, int val);
//(b)打印链表的所有结点的值。
//
//void display_list(Node* list);
//(c)查找链表中第一个与指定值相等的结点，若没有这样的结点，则返回NULL。
//
//Node* search_list(Node* list, int val);
//(d)写一个方法，释放链表中所有的结点。
//
//void free_list(Node* list);

#include<stdio.h>
#include<stdlib.h>
#define DEFAULT_SIZE 8

typedef struct node_s {
    int data;
    struct node_s* next;
} Node;

void add_before_head(Node** plist, int val) {
    //头插法，在链表中插入元素
    //在堆上申请一个存储链表结点的内存空间
    Node* newnode = malloc(sizeof(Node));
    if (! newnode)
    {//判断，动态申请内存不成功则报错
        printf("Error: malloc failed!\n");
        exit(1);
    }
    //初始化newnode
    newnode->data = val;
    newnode->next = *plist;
    //改变*plist的位置,指向新插入的newnode，即指向第一个结点
    *plist = newnode;
}



void display_list(Node* list) {
    //打印链表中的每一个结点的数据域
    printf("Current Linklist is: ");
    while (list != NULL)
    {
        printf("%d  ",list->data);
        list = list->next;
    }
    printf("\n");

}


Node* search_list(Node* list, int val) {
    //在链表中查找val，若找到返回该结点，无则返回空指针
    Node* target_node;//查找结束后，返回main函数的结点
    target_node = NULL;
    while (list != NULL)
    {//链表不为空时，可以打印链表
        if (list->data == val) {
            return list;
        }
        
        list = list->next;//没找到，向后移动
        
    }//此时必定没找到与搜索值val相等的结点
    
    return NULL;
}

//void free_list(Node* list) {
//    //释放堆上链表的内存空间
//    //引发了异常: 读取访问权限冲突。
//    //list 是 0xCCCCCCCC
//    //出现了悬空指针
//    Node* pscan;//用于暂存list结点当前指向，跑得没有list快
//    while (list != NULL){
//        pscan = list;//暂存
//        list = list->next;//list向后扫描
//        free(pscan);//释放pscan
//    }
//}

void free_list(Node* list) {
    
    while (list != NULL) {
        Node* temp = list;
        list = list->next;
        
        free(temp);
    }
}

int main() {
    Node* head=NULL;
    for (int i = 0; i < 10; i++)
    {
        add_before_head(&head, i);
    }
    display_list(head);
    printf("寻找数据域为6的结点：\n");
    int search_val=6;
    Node* search_back_node = search_list(head, search_val);
    if (search_back_node == NULL) {
        printf("Search failed.\n");
    }
    else
    {
        printf("Search success.\n");
    }
    
    free_list(head);
    /*free_list(head);*/
    return 0;
}