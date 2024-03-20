//约瑟夫环：n 个人站成一圈，每 m 个人处决一个人。
//假设这 n 个人的编号为 1, 2, ..., n，并且从 1 开始数，
//问最终活下来的人编号是多少？(拓展题)

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int joseph(int n, int m) {
	if (n==1)
	{
		return 0;
	}
	else
	{
		 return (joseph(n - 1, m) + m) % n;

	}
}

int main() {
	//处理输入
	int n, m;
	printf("Enter n and m:\n");
	scanf("%d%d", &n, &m);
	int result;
	result = joseph(n, m)+1;
	
	printf("The survivior is %d\n", result);
	return 0;
}