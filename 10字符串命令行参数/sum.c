//编写名为 sum.c 的程序，用来对命令行参数（假设都是整数）求和。如果键入
//
//sum 8 24 62
//运行程序，产生的输出应为
//
//Total : 94
//提示：用 sscanf 把命令行参数从字符串转换成整数格式。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main(int argc, char *argv[]) {
	int sum = 0;
	
	for (int i = 1; i < argc; i++)
	{
		int n;
		sscanf(argv[i], "%d", &n);
		sum = sum + n;
	}
	printf("Total: %d",sum);
}