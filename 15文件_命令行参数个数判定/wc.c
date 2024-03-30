//'wc' (word count)��Unix�µ�һ������, 
//������ͳ��һ���ı��ļ����ַ��ĸ���
//(Ҳͳ�Ʋ��ɴ�ӡ�ַ��Ϳհ��ַ�)��
//���ʵĸ���(�����뵥��֮���Կհ��ַ��ָ�) �Լ�������
//��ʵ��һ�� 'wc' ���򣬵�����Ĳ�����������ʱ���������ʾ��Ϣ��
//
//// ʹ�÷�ʽ��./wc file
//// argc��ֵӦ��Ϊ2
//int main(int argc, char* argv[]);

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
	//�����ж�
	if (argc != 2) {
		fprintf(stderr, "Usage: wc %s", argv[1]);
		exit(1);
	}
	//���ļ�
	FILE* file = fopen(argv[1], "r");
	if (!file) {
		fprintf(stderr, "Error: %s open failed.\n", argv[1]);
		exit(1);
	}
	//ͳ���ַ�����������������
	int char_count = 0, word_count = 0, line_count = 0;
	char buf[4096];
	int n;
	while ((n = fgetc(file)) != EOF) {
		char_count++;
		if (isspace(n)) word_count++;
		if (n == '\n') line_count++;
	}	
	if (n != '\n') line_count++;
	printf("Word_count is %d.\n", word_count);
	printf("Line_count is %d.\n", line_count);
	printf("Char_count is %d.\n", char_count);

	return 0;
}