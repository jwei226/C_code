//��a) ��д�����һ����Ϣ��Ȼ�������ӡ������Ϣ��
//
//Enter a message : Don't get mad, get even.
//Reversal is : .neve teg, dam teg t'noD
//��ʾ��һ�ζ�ȡ��Ϣ�е�һ���ַ�����getchar��������
//���Ұ���Щ��ĸ�洢�������У����������˻��߶����ַ� '\n' ʱֹͣ��������
//
//��b) �޸�����������ָ�������������������ĵ�ǰλ�á�

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
//��b) �޸�����������ָ�������������������ĵ�ǰλ�á�

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

	//��Ҫ��ʼ��������ʣ��Ԫ��
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