#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//用 fread / fwrite 实现文件的复制。
// copyFile.c
//int main(int argc, char* argv[]);
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // 参数校验，cp source destination 需要三个参数
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src dst", argv[0]);
        exit(1);
    }
    //打开文件，以二进制文本形式
    FILE* mm = fopen(argv[1], "rb");
    if (!mm) {
        fprintf(stderr, "Error: %s open failed.\n", argv[1]);
        exit(1);
    }
    FILE* ss = fopen(argv[2], "wb");
    if (!ss) {
        fprintf(stderr, "Error: %s open failed.\n", argv[2]);
        exit(1);
    }
    //复制fread fwrite
    int n;
    char buffer[4096];//一页4K 4096bytes
    while ((n = fread(buffer, 1, 4096, mm))) {//从流mm中读取1*4096个字节存放到buffer数组中
        fwrite(buffer, 1, n, ss);//从buffer中buffer数组中1*n字节写入到流ss中
    }
    //关闭文件
    fclose(mm);
    fclose(ss);
    return 0;
}
