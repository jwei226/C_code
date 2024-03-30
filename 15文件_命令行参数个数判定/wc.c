//'wc' (word count)是Unix下的一个工具, 
//它可以统计一个文本文件中字符的个数
//(也统计不可打印字符和空白字符)，
//单词的个数(单词与单词之间以空白字符分隔) 以及行数。
//请实现一个 'wc' 程序，当传入的参数个数不对时，请给出提示信息。
//
//// 使用方式：./wc file
//// argc的值应该为2
//int main(int argc, char* argv[]);

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
	//参数判断
	if (argc != 2) {
		fprintf(stderr, "Usage: wc %s", argv[1]);
		exit(1);
	}
	//打开文件
	FILE* file = fopen(argv[1], "r");
	if (!file) {
		fprintf(stderr, "Error: %s open failed.\n", argv[1]);
		exit(1);
	}
	//统计字符数，单词数，行数
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