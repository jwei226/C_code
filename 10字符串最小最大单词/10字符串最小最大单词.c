//��д�����ҳ�һ�鵥������С���ʺ���󵥴ʡ�
//���û�����4����ĸ�ĵ���ʱ������ֹͣ���롣
//�������е��ʶ�������20����ĸ������Ự���£�
//
//Enter word : dog
//Enter word : zebra
//Enter word : rabbit
//Enter word : catfish
//Enter word : walrus
//Enter word : cat
//Enter word : fish
//
//Smallest word : cat
//Largest word : zebra
//��ʾ��ʹ��������Ϊ smallest_word �� largest_word ���ַ���
//���ֱ��¼��С���ʺ���󵥴ʡ�
//�û�ÿ����һ���µ��ʣ���Ҫ�� strcmp ������ smallest_word �� largest_word ���бȽϡ�
//�� strlen �����ж��û��Ƿ������� 4 ����ĸ�ĵ��ʡ�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAXLINE 20

//void find_smallest_largest_words() {
//	char message[MAXLINE] ="";
//	char* smallest_word;
//	char* largest_word;
//	
//	//�ж�4����ĸʱֹͣ����
//	while (strlen(message)==4)
//	{
//		printf("Enter word: ");
//		fgets(message,MAXLINE-1,stdin);
//		smallest_word = message;
//		largest_word = message;
//		if (strcmp(smallest_word,message))
//		{//message����С�ĵ��ʻ�С
//			smallest_word = message;
//		}
//		else if (strcmp(message, largest_word)) {
//			//message�����ĵ��ʻ�Ҫ��
//			largest_word = message;
//		}
//		printf("Smallest word: ");
//		puts(smallest_word);
//		printf("Largest word: ");
//		puts(largest_word);
//	}
//}
int main() {
	/*find_smallest_largest_words();*/
	char message[MAXLINE+1] ;
	char smallest_word[MAXLINE+1] ;
	char largest_word[MAXLINE+1] ;

	//��ʼ��
	printf("Enter word: ");
	fgets(message, MAXLINE, stdin);
	/*scanf("%s", message);*/
	message[strcspn(message, "\n")] = '\0'; // �Ƴ�fgets��ȡ�Ļ��з�
	strcpy(smallest_word, message);
	strcpy(largest_word, message);

	//�ж�4����ĸʱֹͣ����
	while (strlen(message) != 4)
	{
		printf("Enter word: ");
		fgets(message, MAXLINE, stdin);
		message[strcspn(message, "\n")] = '\0'; // �Ƴ�fgets��ȡ�Ļ��з�
		
		if (strcmp(smallest_word, message))
		{//message����С�ĵ��ʻ�С
			strcpy(smallest_word, message);
		}
		else if (strcmp(message, largest_word)) {
			//message�����ĵ��ʻ�Ҫ��
			strcpy(largest_word, message);
		}
		
	}
	printf("Smallest word: ");
	puts(smallest_word);
	printf("Largest word: ");
	puts(largest_word);
	return 0;

}

