//Լɪ�򻷣�n ����վ��һȦ��ÿ m ���˴���һ���ˡ�
//������ n ���˵ı��Ϊ 1, 2, ..., n�����Ҵ� 1 ��ʼ����
//�����ջ��������˱���Ƕ��٣�(��չ��)

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int joseph(int n, int m) {
	if (n==1)
	{
		return 0;
	}
	else
	{
		 return (joseph(n - 1, m) + m) % n;

	}
}

int main() {
	//��������
	int n, m;
	printf("Enter n and m:\n");
	scanf("%d%d", &n, &m);
	int result;
	result = joseph(n, m)+1;
	
	printf("The survivior is %d\n", result);
	return 0;
}