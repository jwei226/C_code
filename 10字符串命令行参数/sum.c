//��д��Ϊ sum.c �ĳ��������������в��������趼����������͡��������
//
//sum 8 24 62
//���г��򣬲��������ӦΪ
//
//Total : 94
//��ʾ���� sscanf �������в������ַ���ת����������ʽ��
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