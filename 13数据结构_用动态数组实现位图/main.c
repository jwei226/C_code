#include"BitMap.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void remove_duplicate_and_sort(char* str) {
	/*����һ��������Сд��ĸ���ַ�����
	��ȥ���ַ����е��ظ���ĸ��
	ʹ��ÿ����ĸֻ����һ�Ρ�
	������ĸ��С���������

	ʾ����
	���룺"bcabc"
	�����"abc"*/

	// ���ַ������޸�	
	uint32_t array = 0;//��ʼ��Ϊ0
	for (int i = 0; str[i]!='\0'; i++)
	{//���������ַ���
		int offset = str[i] - 'a';
		
		if (array & (0x1 << offset)) {
			//������ֹ����ַ�,����λΪ1��������
			continue;
		}//���ַ�û���ֹ�����Ӧoffset��λ����Ϊ1
		array |= (0x1 << offset);
	}//ȥ���������
	
	for (int i = 0; i < 26; i++) {
		//�������,���Ϊ1�����
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
	bitmap_set(map, 128);//���ݺ��8����Ϊ01

	bitmap_unset(map, 5);//84 02

	for (size_t i = 0; i < 10; i++) {
		if (bitmap_isset(map, i)) {
			printf("λ %zu ������Ϊ 1\n", i);
		}
		else {
			printf("λ %zu ������Ϊ 0\n", i);
		}
	}
	


	bitmap_clear(map);

	bitmap_destroy(map);
	return 0;
}