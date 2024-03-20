//（a) 编写程序读一条消息，然后逆序打印这条消息：
//
//Enter a message : Don't get mad, get even.
//Reversal is : .neve teg, dam teg t'noD
//提示：一次读取消息中的一个字符（用getchar函数），
//并且把这些字母存储在数组中，当数组满了或者读到字符 '\n' 时停止读操作。
//
//（b) 修改上述程序，用指针代替整数来跟踪数组的当前位置。

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#define MAXSIZE 200
//
//int main() {
//	printf("Enter a massage: ");
//	int arr[MAXSIZE];
//	int p = 0;
//	char ch = getchar();
//	while ((ch=getchar())!='\n'&&p<MAXSIZE)
//	{
//		arr[p] = ch;
//		p++;
//	}
//	printf("Reverse is: ");
//	for (int i = p-1; i >=0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}
//（b) 修改上述程序，用指针代替整数来跟踪数组的当前位置。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAXSIZE 200

int main() {
	printf("Enter a message: ");
	char arr[MAXSIZE];
	char* p = arr;
	char ch ;
	while ((ch=getchar())!='\n'&& p<arr+MAXSIZE)
	{
		*p=ch;
		p++;
	}

	//需要初始化数组中剩余元素
	/*for (; p < arr + MAXSIZE; p++) {
		p = '\0';
		
	}*/
	printf("Reverse is: ");
	/*p--;*/
	while (p>=arr)
	{
		/*if (*p!='\0')
		{*/
			printf("%c", *p);
		/*}*/
		
		p--;

	}
	return 0;
}