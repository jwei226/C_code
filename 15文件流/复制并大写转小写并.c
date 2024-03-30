#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
	//1.�ļ��Ĵ�
	FILE* file1 = fopen("file1.txt", "r");
	if (!file1) {
		fprintf(stderr, "Error: fopen failed.\n");
		exit(1);
	}
	FILE* dst = fopen("file1_copy.txt", "w");
	if (!dst) {
		fprintf(stderr, "Error: fopen failed.\n");
		exit(1);
	}
	//2.�ļ��Ķ�д����ǰ��file1.txt������
	//2.1.fgetc,fputc
	int c;
	while ((c=fgetc(file1)) != EOF) {
		if (isalpha(c)) {
			fputc(tolower(c), dst);
		}
		else {
			fputc(c, dst);
		}
	}
	//3.�ļ��Ĺر�
	fclose(file1);

	return 0;
}