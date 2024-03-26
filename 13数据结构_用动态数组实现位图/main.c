#include"BitMap.h"
#include<stdio.h>
#include<stdlib.h>
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
	uint32_t array = 0;//初始化为0
	for (int i = 0; str[i]!='\0'; i++)
	{//遍历整条字符串
		int offset = str[i] - 'a';
		
		if (array & (0x1 << offset)) {
			//如果出现过该字符,即该位为1，则跳过
			continue;
		}//该字符没出现过，相应offset的位，置为1
		array |= (0x1 << offset);
	}//去重排序完毕
	
	for (int i = 0; i < 26; i++) {
		//遍历输出,如果为1则输出
		if (array | (0x1 << i)) {
			printf("%s",'a'+i);
		}
	}
}

int main() {
	/*int i = sizeof(uint32_t);
	printf("%d", i);*/
	BitMap* map = bitmap_create(100);

	bitmap_set(map, 9);//00 02
	bitmap_set(map, 5);//20 02
	bitmap_set(map, 2);//24 02
	bitmap_set(map, 7);//a4 02
	bitmap_set(map, 128);//扩容后第8个字为01

	bitmap_unset(map, 5);//84 02

	for (size_t i = 0; i < 10; i++) {
		if (bitmap_isset(map, i)) {
			printf("位 %zu 被设置为 1\n", i);
		}
		else {
			printf("位 %zu 被设置为 0\n", i);
		}
	}
	


	bitmap_clear(map);

	bitmap_destroy(map);
	return 0;
}