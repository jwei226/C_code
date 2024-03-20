//������Ķ������£���ʵ�����湦�ܣ�
//
//typedef struct node_s {
//    int data;
//    struct node_s* next;
//} Node;
//(a)����ͷ�巨���������в���Ԫ��
//
//void add_before_head(Node** plist, int val);
//(b)��ӡ��������н���ֵ��
//
//void display_list(Node* list);
//(c)���������е�һ����ָ��ֵ��ȵĽ�㣬��û�������Ľ�㣬�򷵻�NULL��
//
//Node* search_list(Node* list, int val);
//(d)дһ���������ͷ����������еĽ�㡣
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
    //ͷ�巨���������в���Ԫ��
    //�ڶ�������һ���洢��������ڴ�ռ�
    Node* newnode = malloc(sizeof(Node));
    if (! newnode)
    {//�жϣ���̬�����ڴ治�ɹ��򱨴�
        printf("Error: malloc failed!\n");
        exit(1);
    }
    //��ʼ��newnode
    newnode->data = val;
    newnode->next = *plist;
    //�ı�*plist��λ��,ָ���²����newnode����ָ���һ�����
    *plist = newnode;
}



void display_list(Node* list) {
    //��ӡ�����е�ÿһ������������
    printf("Current Linklist is: ");
    while (list != NULL)
    {
        printf("%d  ",list->data);
        list = list->next;
    }
    printf("\n");

}


Node* search_list(Node* list, int val) {
    //�������в���val�����ҵ����ظý�㣬���򷵻ؿ�ָ��
    Node* target_node;//���ҽ����󣬷���main�����Ľ��
    target_node = NULL;
    while (list != NULL)
    {//����Ϊ��ʱ�����Դ�ӡ����
        if (list->data == val) {
            return list;
        }
        
        list = list->next;//û�ҵ�������ƶ�
        
    }//��ʱ�ض�û�ҵ�������ֵval��ȵĽ��
    
    return NULL;
}

//void free_list(Node* list) {
//    //�ͷŶ���������ڴ�ռ�
//    //�������쳣: ��ȡ����Ȩ�޳�ͻ��
//    //list �� 0xCCCCCCCC
//    //����������ָ��
//    Node* pscan;//�����ݴ�list��㵱ǰָ���ܵ�û��list��
//    while (list != NULL){
//        pscan = list;//�ݴ�
//        list = list->next;//list���ɨ��
//        free(pscan);//�ͷ�pscan
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
    printf("Ѱ��������Ϊ6�Ľ�㣺\n");
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