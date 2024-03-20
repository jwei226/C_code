#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


//int roll_card() {
//	
//}

int main() {
	//处理输入
	int cards;
	printf("Enter number of cards in hand: ");
	scanf("%d", &cards);

	//定义一套牌
	const char colors[4] = { 'h','d','c','s' };
	const char figures[13] = { '1','2','3','4','5','6','7','8',
		'9','t','j','q','k' };

	printf("You hand: ");
	for (int i = 1; i < 5; i++) {

	}

	//随机发牌
	srand(time(NULL));
	
	//避免重复
	bool in_hand[4][13] = { false };
	while (cards)
	{
		int color = rand() % 4;
		int figure = rand() % 13;
		if (!in_hand[color][figure]) {
			in_hand[color][figure] = true;
			printf("%c%c  ", colors[color], figures[figure]);
			cards--;
		}
	}
	

	return 0;
	
	
	
	
}