//编写程序对用户输入的一系列单词排序：
//
//Enter word : foo
//Enter word : bar
//Enter word : baz
//Enter word : quux
//Enter word :
//
//In sorted order : bar baz foo quux
//假设每个单词不超过20个字符，字符串个数不会超过100。
//当用户输入空单词（即敲击回车键而没有录入任何单词）时停止读入。
//把每个单词存储在一个动态分配的字符串中，然后用一个指针数组来跟踪这些字符串。
//读完所有的单词后对数组排序（可以使用 qsort），然后依次输出每个单词。

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
	//定义一个字符串指针数组words[]跟踪堆上存储的单词
	char* words[MAX_WORDS_NUM];
	//定义一个字符串数组word[]暂时存储单词
	char word[MAX_WORD_LENGTH];
	int num_current = 0;//当前单词数量

	//初始化
	printf("Enter word: ");
	/*word[0] = fgets(word, MAX_WORD_LENGTH, stdin);*/
	/*while ((word[0] != NULL) && (word[0] != '\n')) {*///发生访问冲突
	while ((fgets(word, MAX_WORD_LENGTH, stdin)) && (word[0] != '\n')) {
		//临界条件：输入空单词停止读入
		//堆上初始化动态分配的字符串数组，再把输入的单词复制到堆上
		words[num_current] = malloc(strlen(word) + 1);
		strcpy(words[num_current], word);
		num_current++;

		if (num_current > MAX_WORDS_NUM)
		{//字符串个数不会超过100
			break;
		}
		printf("Enter word: ");
	}
	
	//调用qsort()对字符串数组排序数组
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