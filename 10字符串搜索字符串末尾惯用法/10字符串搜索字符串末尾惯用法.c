//编写下面的函数：
//
//void remove_filename(char* url);
//url 指向一个包含以文件名结尾的 URL 字符串，
//例如 "http://www.knking.com/index.html"。函数需要移除文件名和前面的斜杠。
//(在上面的例子中，结果为 "http://www.knking.com"）。
//	要求在函数中使用 "搜索字符串末尾" 的惯用法。
//
//	提示：把字符串中的最后一个斜杠替换为空字符。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void remove_filename(char* url) {
	char* p = url;//存储字符串头指针位置
	//惯用法：找到字符串末尾
	//while (url)//url != '0'
	//{
	//	url++;
	//}
	while (*url)
		url++;
	//移除文件名和斜杠
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