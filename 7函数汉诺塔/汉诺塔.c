//����������A��B��C��A������ N ��(N > 1) ����Բ�̣��̵ĳߴ����µ������α�С��Ҫ�����й�������Բ������ C �ˣ�
//
//1. ÿ��ֻ���ƶ�һ��Բ��;
//2. ���̲��ܵ���С�����档
//
//��ʾ���ɽ�Բ����ʱ���� B �ˣ�Ҳ�ɽ��� A ���Ƴ���Բ�������ƻ� A �ˣ�����������ѭ������������
//
//�ʣ�������Ҫ�ƶ����ٴΣ�����ƣ�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int hanoi(char start, char middle, char target, int n) {
	//�߽�����
	if (n == 1) {
		printf("%c --> %c\n", start, target);
		return;
	}
	//�ݹ鹫ʽ
	hanoi(start, target, middle, n - 1);
	printf("%c --> %c\n", start, target);
	hanoi(middle, start, target, n - 1);
}
int main() {
	int n;
	printf("n = " );
	scanf("%d", &n);
	hanoi('A', 'B', 'C', n);
	printf("total steps: %d\n", (1 << n) - 1);
	return 0;

}