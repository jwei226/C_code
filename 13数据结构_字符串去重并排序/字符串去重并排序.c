/*给定一个仅包含小写字母的字符串，
请去除字符串中的重复字母，
使得每个字母只出现一次。
并按字母从小到大输出。

示例：
输入："bcabc"
输出："abc"*/

// 在字符串上修改
#include <stdio.h>
#include<string.h>
#include<stdint.h>

void remove_duplicate_and_sort(char* str) {
	/*给定一个仅包含小写字母的字符串，
	请去除字符串中的重复字母，
	使得每个字母只出现一次。
	并按字母从小到大输出。

	示例：
	输入："bcabc"
	输出："abc"*/

	// 在字符串上修改	
	unsigned int array = 0;//初始化为0
	for (int i = 0; str[i] != '\0'; i++)
	{//遍历整条字符串
		int offset = str[i] - 'a';

		if (array & (1 << offset)) {
			//如果出现过该字符,即该位为1，则跳过
			continue;
		}//该字符没出现过，相应offset的位，置为1
		array |= (1 << offset);
	}//去重排序完毕

	for (int i = 0; i < 26; i++) {
		//遍历输出,如果为1则输出
		if (array & (1 << i)) {
			printf("%c", 'a' + i);
		}
	}
}


int main() {
	printf("Enter a string: \n");
	char str[] = "bcabc";
	remove_duplicate_and_sort(str);

	return 0;

}