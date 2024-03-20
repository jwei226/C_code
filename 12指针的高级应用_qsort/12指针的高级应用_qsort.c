//��д������û������һϵ�е�������
//
//Enter word : foo
//Enter word : bar
//Enter word : baz
//Enter word : quux
//Enter word :
//
//In sorted order : bar baz foo quux
//����ÿ�����ʲ�����20���ַ����ַ����������ᳬ��100��
//���û�����յ��ʣ����û��س�����û��¼���κε��ʣ�ʱֹͣ���롣
//��ÿ�����ʴ洢��һ����̬������ַ����У�Ȼ����һ��ָ��������������Щ�ַ�����
//�������еĵ��ʺ���������򣨿���ʹ�� qsort����Ȼ���������ÿ�����ʡ�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_WORD_LENGTH 21
#define MAX_WORDS_NUM 100


int cmp(const void* a, const void* b) {
	return strcmp((const char*) a, (const char*) b);
}
int main() {
	//����һ���ַ���ָ������words[]���ٶ��ϴ洢�ĵ���
	char* words[MAX_WORDS_NUM];
	//����һ���ַ�������word[]��ʱ�洢����
	char word[MAX_WORD_LENGTH];
	int num_current = 0;//��ǰ��������

	//��ʼ��
	printf("Enter word: ");
	/*word[0] = fgets(word, MAX_WORD_LENGTH, stdin);*/
	/*while ((word[0] != NULL) && (word[0] != '\n')) {*///�������ʳ�ͻ
	while ((fgets(word, MAX_WORD_LENGTH, stdin)) && (word[0] != '\n')) {
		//�ٽ�����������յ���ֹͣ����
		//���ϳ�ʼ����̬������ַ������飬�ٰ�����ĵ��ʸ��Ƶ�����
		words[num_current] = malloc(strlen(word) + 1);
		strcpy(words[num_current], word);
		num_current++;

		if (num_current > MAX_WORDS_NUM)
		{//�ַ����������ᳬ��100
			break;
		}
		printf("Enter word: ");
	}
	
	//����qsort()���ַ���������������
	qsort(words, num_current, sizeof(char*), cmp);
	printf("\nIn sorted order: ");
	for (int i = 0; i < num_current; i++)
	{
		printf("%s   ", words[i]);
		free(words[i]);
	}
	printf("\n");
	return 0;
}