//（a) 编写程序读一条消息，然后检查这条消息是否是回文
//（消息从左往右看和从右往左看是一样的）：
//
//Enter a message : He lived as a devil, eh ?
//Palindrome
//
//Enter a message : Madam, I am Adam.
//Not a palindrome
//忽略所有不是字母的字符。用索引来跟踪数组中的位置。
//
//（b）修改上述程序，使用指针代替索引来跟踪数组中的位置。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>//tolower函数标头
#define MAXSIZE 100

//判断是否是字母，如果给定的字符是字母，则返回1，否则返回0
int alphebat(char c) {
	return ((c >='a' && c <= 'z') || (c >='A' && c <= 'Z'));
}
int palindrome(char arr[]) {
	char* start = arr;
	int len = strlen(arr);
	char* end = arr + len - 1;
	//指针分别从数组两端扫描
	while (start < end) {
		while (!alphebat(*start)) {
			start++;//当头指针指向的字符不是字母时，不比较，指针后移
		}
		while (!alphebat(*end)) {
			end--;//当尾指针指向的字符不是字符时，不比较，指针前移
		}
		if (tolower(*start)!=tolower(*end)) {
			//头指针和尾指针指向的字母不相同，非回文
			return 0;

		}
		start++;
		end--;
	}
	return 1;//否则，回文，返回1
}
int main() {
	printf("Enter a message: ");
	char message[MAXSIZE];
	
	char ch;
	fgets(message,sizeof(message), stdin);//防止缓冲区溢出
	//接受信息存入数组message
	//只要字母不判断其他字符
	if (palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}