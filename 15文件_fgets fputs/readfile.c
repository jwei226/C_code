//用户输入路径名，将整个文件的内容读入到字符数组中，
//并在后面添加空字符 '\0'
//
//char* readFile(const char* path);

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char* readFile(const char* path) {
	//打开文件
	FILE* main_stream = fopen(path, "rb");
	if (!main_stream) {
		fprintf(stderr, "Error: %s open failed.\n", path);
		exit(1);
	}
	//用文件位置API得文件大小
	fseek(main_stream, 0, SEEK_END);
	long int bytes = ftell(main_stream);
	//读写文件，并添加空字符
	rewind(main_stream);
	char* buff = malloc(bytes + 1);//留一个位给空字符
	int n;
	n = fread(buff, 1, bytes, main_stream);
	buff[n] = '\0';
	//关闭文件
	fclose(main_stream);
	return buff;
}

int main() {
	char* main_function = readFile("readfile.c");

	free(main_function);
	return 0;
}