//�û�����·�������������ļ������ݶ��뵽�ַ������У�
//���ں�����ӿ��ַ� '\0'
//
//char* readFile(const char* path);

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char* readFile(const char* path) {
	//���ļ�
	FILE* main_stream = fopen(path, "rb");
	if (!main_stream) {
		fprintf(stderr, "Error: %s open failed.\n", path);
		exit(1);
	}
	//���ļ�λ��API���ļ���С
	fseek(main_stream, 0, SEEK_END);
	long int bytes = ftell(main_stream);
	//��д�ļ�������ӿ��ַ�
	rewind(main_stream);
	char* buff = malloc(bytes + 1);//��һ��λ�����ַ�
	int n;
	n = fread(buff, 1, bytes, main_stream);
	buff[n] = '\0';
	//�ر��ļ�
	fclose(main_stream);
	return buff;
}

int main() {
	char* main_function = readFile("readfile.c");

	free(main_function);
	return 0;
}