//��д����ģ�������ӵ���Ϸ���������ӣ���ÿ����Ϸ�Ĺ������£�
//
//��һ������ʱ���� ������֮��Ϊ 7 �� 11 ���ʤ���������֮��Ϊ2��3��12����ܣ���������µĵ���֮�ͳ�Ϊ��Ŀ�ꡱ����Ϸ�������ں�����Ͷ���У��������ٴ�������Ŀ�ꡱ�������ʤ������7����ܣ�������������ԣ���Ϸ�������С�
//
//ÿ����Ϸ����ʱ������ѯ���û��Ƿ�����һ�Σ������ ������Ļش��� y �� Y ���������ʾʤ�ܵĴ���Ȼ����ֹ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

bool play_game() {
	int roll_result = roll_dice();
	if (roll_result == 7 || roll_result == 11) {
		printf("You win!\n");
		return true;
	}
	if (roll_result==2||roll_result==3||roll_result==12)
	{
		printf("You lose!\n");
		return false;
	}
	printf("Your point is %d\n", roll_result);
	for ( ;  ; )
	{
		int point = roll_dice();
		if (point==roll_result)
		{
			printf("You win!\n");
			return true;
		}
		if (point == 7) {
			printf("You lose!\n");
			return false;
		}
	}
}

int roll_dice() {
	int a = rand() % 6;
	int b = rand() % 6;
	printf("You rolled: %d\n", a + b);
	return a + b;
}
int main() {
	//�������
	printf("You rolled: %d\n",roll_dice());

	int wins=0;
	int loses=0;
	char answer;
	srand(time(NULL));
	do
	{
		play_game() ? wins++ : loses++;
		printf("Play again? ");
		answer = getchar();
		/*scanf("%c", &answer);
		while(getchar() != '\n');*/
	} while (answer == 'y' || answer == 'Y');
	printf("Wins: %d Losses: %d", wins, loses);
	
	return 0;
}