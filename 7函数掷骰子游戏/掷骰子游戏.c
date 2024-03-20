//编写程序模拟掷骰子的游戏（两个骰子）。每局游戏的规则如下：
//
//第一次掷的时候，如 果点数之和为 7 或 11 则获胜；如果点数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，其他情况都忽略，游戏继续进行。
//
//每局游戏结束时，程序询问用户是否再玩一次，如果用 户输入的回答不是 y 或 Y ，程序会显示胜败的次数然后终止。

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
	//解决输入
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