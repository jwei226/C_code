/*����һ��������Сд��ĸ���ַ�����
��ȥ���ַ����е��ظ���ĸ��
ʹ��ÿ����ĸֻ����һ�Ρ�
������ĸ��С���������

ʾ����
���룺"bcabc"
�����"abc"*/

// ���ַ������޸�
#include <stdio.h>
#include<string.h>
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
	unsigned int array = 0;//��ʼ��Ϊ0
	for (int i = 0; str[i] != '\0'; i++)
	{//���������ַ���
		int offset = str[i] - 'a';

		if (array & (1 << offset)) {
			//������ֹ����ַ�,����λΪ1��������
			continue;
		}//���ַ�û���ֹ�����Ӧoffset��λ����Ϊ1
		array |= (1 << offset);
	}//ȥ���������

	for (int i = 0; i < 26; i++) {
		//�������,���Ϊ1�����
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