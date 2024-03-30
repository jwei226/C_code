#include<stdio.h>
#include<stdlib.h>

//用 fread / fwrite 实现文件的复制。
//// copyFile.c
//int main(int argc, char* argv[]);



int main(const int argc, const char* argv[]) {
	/*char path = argv[1];*/
	//参数校验，cp source destination 需要三个参数
	if (argc != 3) {
		fprintf(stderr, "Usage: %s src dst", argv[0]);
		exit(1);
	}

	return 0;
}​