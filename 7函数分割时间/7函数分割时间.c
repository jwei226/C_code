//��д������
//void split_time(long total_sec, int* hour, int* minute, int* second);
//total_sec ��ʾ����ҹ12 : 00 : 00��ʼ�����������
//�뽫 total_sec ת����ʱ(0 - 23)����(0 - 59)����(0 - 59)��ʾ��ʱ�䣬
//����ŵ������ⲿ��ָ�� hour, minute, second ָ��ı����С�
//�����ⲿ����ӡ����ǰ��ʱ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void split_time(long total_sec, int* hour, int* minute, int* second) {
	*hour = total_sec / 3600;
	*minute = (total_sec % 3600) / 60;
	*second = total_sec % 60;
}

int main() {
	//��������
	long total_sec;
	printf("Enter a total second: ");
	scanf("%lf", &total_sec);
	printf("\n");

	//�����ⲿ����
	int hour, minute, second;
	//���ú���
	split_time(total_sec, &hour, &minute, &second);
	printf("Equels to %d hour\n", hour);
	printf("Equels to %d minute\n", minute);
	printf("Equels ro %d second\n", second);
	return 0;
}