//��a) ��д�����һ����Ϣ��Ȼ����������Ϣ�Ƿ��ǻ���
//����Ϣ�������ҿ��ʹ���������һ���ģ���
//
//Enter a message : He lived as a devil, eh ?
//Palindrome
//
//Enter a message : Madam, I am Adam.
//Not a palindrome
//�������в�����ĸ���ַ��������������������е�λ�á�
//
//��b���޸���������ʹ��ָ��������������������е�λ�á�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>//tolower������ͷ
#define MAXSIZE 100

//�ж��Ƿ�����ĸ������������ַ�����ĸ���򷵻�1�����򷵻�0
int alphebat(char c) {
	return ((c >='a' && c <= 'z') || (c >='A' && c <= 'Z'));
}
int palindrome(char arr[]) {
	char* start = arr;
	int len = strlen(arr);
	char* end = arr + len - 1;
	//ָ��ֱ����������ɨ��
	while (start < end) {
		while (!alphebat(*start)) {
			start++;//��ͷָ��ָ����ַ�������ĸʱ�����Ƚϣ�ָ�����
		}
		while (!alphebat(*end)) {
			end--;//��βָ��ָ����ַ������ַ�ʱ�����Ƚϣ�ָ��ǰ��
		}
		if (tolower(*start)!=tolower(*end)) {
			//ͷָ���βָ��ָ�����ĸ����ͬ���ǻ���
			return 0;

		}
		start++;
		end--;
	}
	return 1;//���򣬻��ģ�����1
}
int main() {
	printf("Enter a message: ");
	char message[MAXSIZE];
	
	char ch;
	fgets(message,sizeof(message), stdin);//��ֹ���������
	//������Ϣ��������message
	//ֻҪ��ĸ���ж������ַ�
	if (palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}