//用户输入初始金额，利率和投资年数，程序将打印一张表格。表格将显示输入的利率以及紧随其后 4 个更高利率下的总金额。程序的会话如下：
//
//Enter initial balance : 100
//Enter interest rate : 6
//Enter number of years : 5
//
//Years    6 % 7 % 8 % 9 % 10 %
//1    106.00 107.00 108.00 109.00 110.00
//2    112.36 114.49 116.64 118.81 121.00
//3    119.10 122.50 125.97 129.50 133.10
//4    126.25 131.08 136.05 141.16 146.41
//5    133.82 140.26 146.93 153.86 161.05

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	//解决输入
	printf("Enter initial balance: ");
	int init_balance;
	scanf("%d", &init_balance);
	printf("\n");

	printf("Enter interest rate: ");
	int init_rate;
	scanf("%d", &init_rate);
	printf("\n");

	printf("Enter number of years: ");
	int years;
	scanf("%d", &years);

	printf("Years  ");
	double balance[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%4d%%   ", init_rate);
		init_rate++;
		balance[i] = init_balance;

	}
	printf("\n");
	
	for (int i = 1; i <= years; i++)
	{
		printf("%3d    ", i);
		for (int row = 0; row < 5; row++)
		{
			balance[row] += balance[row]*((row + init_rate) / 100.0);
			printf("%7.2lf",balance[row]);
		}
		printf("\n");
	}
	return 0;
}