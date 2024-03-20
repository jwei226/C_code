//编写函数：
//void split_time(long total_sec, int* hour, int* minute, int* second);
//total_sec 表示从午夜12 : 00 : 00开始计算的秒数。
//请将 total_sec 转化以时(0 - 23)、分(0 - 59)、秒(0 - 59)表示的时间，
//并存放到函数外部由指针 hour, minute, second 指向的变量中。
//并在外部，打印出当前的时间

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void split_time(long total_sec, int* hour, int* minute, int* second) {
	*hour = total_sec / 3600;
	*minute = (total_sec % 3600) / 60;
	*second = total_sec % 60;
}

int main() {
	//处理输入
	long total_sec;
	printf("Enter a total second: ");
	scanf("%lf", &total_sec);
	printf("\n");

	//定义外部变量
	int hour, minute, second;
	//调用函数
	split_time(total_sec, &hour, &minute, &second);
	printf("Equels to %d hour\n", hour);
	printf("Equels to %d minute\n", minute);
	printf("Equels ro %d second\n", second);
	return 0;
}