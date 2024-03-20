//编写程序找出一组单词中最小单词和最大单词。
//当用户输入4个字母的单词时，程序停止读入。
//假设所有单词都不超过20个字母。程序会话如下：
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
//提示：使用两个名为 smallest_word 和 largest_word 的字符串
//来分别记录最小单词和最大单词。
//用户每输入一个新单词，都要用 strcmp 把它与 smallest_word 和 largest_word 进行比较。
//用 strlen 函数判断用户是否输入了 4 个字母的单词。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAXLINE 20

//void find_smallest_largest_words() {
//	char message[MAXLINE] ="";
//	char* smallest_word;
//	char* largest_word;
//	
//	//判断4个字母时停止读入
//	while (strlen(message)==4)
//	{
//		printf("Enter word: ");
//		fgets(message,MAXLINE-1,stdin);
//		smallest_word = message;
//		largest_word = message;
//		if (strcmp(smallest_word,message))
//		{//message比最小的单词还小
//			smallest_word = message;
//		}
//		else if (strcmp(message, largest_word)) {
//			//message比最大的单词还要大
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

	//初始化
	printf("Enter word: ");
	fgets(message, MAXLINE, stdin);
	/*scanf("%s", message);*/
	message[strcspn(message, "\n")] = '\0'; // 移除fgets读取的换行符
	strcpy(smallest_word, message);
	strcpy(largest_word, message);

	//判断4个字母时停止读入
	while (strlen(message) != 4)
	{
		printf("Enter word: ");
		fgets(message, MAXLINE, stdin);
		message[strcspn(message, "\n")] = '\0'; // 移除fgets读取的换行符
		
		if (strcmp(smallest_word, message))
		{//message比最小的单词还小
			strcpy(smallest_word, message);
		}
		else if (strcmp(message, largest_word)) {
			//message比最大的单词还要大
			strcpy(largest_word, message);
		}
		
	}
	printf("Smallest word: ");
	puts(smallest_word);
	printf("Largest word: ");
	puts(largest_word);
	return 0;

}

