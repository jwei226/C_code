//��д����ĺ�����
//
//void remove_filename(char* url);
//url ָ��һ���������ļ�����β�� URL �ַ�����
//���� "http://www.knking.com/index.html"��������Ҫ�Ƴ��ļ�����ǰ���б�ܡ�
//(������������У����Ϊ "http://www.knking.com"����
//	Ҫ���ں�����ʹ�� "�����ַ���ĩβ" �Ĺ��÷���
//
//	��ʾ�����ַ����е����һ��б���滻Ϊ���ַ���

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void remove_filename(char* url) {
	char* p = url;//�洢�ַ���ͷָ��λ��
	//���÷����ҵ��ַ���ĩβ
	//while (url)//url != '0'
	//{
	//	url++;
	//}
	while (*url)
		url++;
	//�Ƴ��ļ�����б��
	while (*url!='/')
	{
		*url = '\0';
		*url--;
	}
	*url = '\0';
	url = p;
	puts(url);
	
}

int main() {
	char message[] = "http://www.knking.com/index.html";
	remove_filename(message);
	
	return 0;
}