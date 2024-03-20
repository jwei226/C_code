//德州扑克：写一个程序循环读取 5 张手牌(输入 0 结束程序)，然后把手中的牌分为下面某一类：
//1.同花顺 2.四张 3.葫芦(3 + 2) 4. 同花 5. 顺子 6.三张 7.两对 8. 一对 9.高牌。
//程序对话如下：
//
//Enter a card : 2s
//Enter a card : 5s
//Enter a card : 4s
//Enter a card : 3s
//Enter a card : 6s
//Straight flush
//
//Enter a card : 8c
//Enter a card : as
//Enter a card : 8c
//Duplicate card; ignored.
//Enter a card : 7c
//Enter a card : ad
//Enter a card : 3h
//Pair
//
//Enter a card : 6s
//Enter a card : d2
//Bad card; ignored.
//Enter a card : 2d
//Enter a card : 9c
//Enter a card : 4h
//Enter a card : ts
//High card
//
//Enter a card : 0

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//需要知道花色suit和点数rank有几张
int num_suit[4];
int num_rank[13];
void read_card(void) {
	for (int i = 0; i < 4; i++)
	{
		num_suit[i] = 0;
	}
	for (int i = 0; i < 13; i++)
	{
		num_rank[i] = 0;
	}
	//处理输入
	int card_read = 0;

	bool bad_card = false;//控制非法牌的布尔变量
	bool cards_in_hand[13][4] = { false };//判断牌是否重复，false表示没有重复
	while (card_read<5)
	{
		bad_card = 0;//防止上一次输入出现错误，影响下一次输入正确
		printf("Enter a card: ");

		//接受点数
		char c = getchar();
		int rank;
		switch (c)
		{
		case '0':exit(0);
		case'2':rank = 0; break;
		case'3':rank = 1; break;
		case'4':rank = 2; break;
		case'5':rank = 3; break;
		case'6':rank = 4; break;
		case'7':rank = 5; break;
		case'8':rank = 6; break;
		case'9':rank = 7; break;
		case't':case'T':rank = 8; break;
		case'j':case'J':rank = 9; break;
		case'q':case'Q':rank = 10; break;
		case'k':case'K':rank = 11; break;
		case'a':case'A':rank = 12; break;
		default:bad_card = true;
			break;
		}

		//接受花色
		c = getchar();
		int suit;
		switch (c)
		{
		case'd':suit = 0; break;
		case'h':suit = 1; break;
		case'c':suit = 2; break;
		case's':suit = 3; break;

		default:bad_card = true;
			break;
		}

		//输入结束，对剩余getchar()处理
		while ((c=getchar())!='\n')
		{
			if (c != ' ' || c != '\t')
			{
				bad_card = true;
			}
		}
		

		//排除非法牌，对正常读取的牌作以下处理：
		// 牌数card_read增加，手中牌cards_in_hand置真，对应点数和花色增加
		
		//Bad Card判断
		if (bad_card)//有Bad Card
		{
			printf("Bad Card; ignored.\n");
		}
		//Duplivate Card判断,定义一个已有牌数组cards_in_hand[]
		else if(cards_in_hand[rank][suit])//
		{
			printf("Duplicate Card; ignored.\n");
		}
		else
		{
			card_read++;
			cards_in_hand[rank][suit] = true;//更新手中牌
			num_rank[rank]++;//该点数
			num_suit[suit]++;//该花色

		}
	}
}

bool flush;//同花,五张同一花色的牌
bool straight;//顺子,五张顺连的牌
bool four;//四条：5张牌当中的4张数字一样
bool three;//3张数字一样
int pair;//对
void analyze_card(void) {
	flush = false; // 初始化为 false
	straight = false; // 初始化为 false
	four = false;
	three = false;
	pair = 0;

	int combo=0;//用来判断顺连牌的数量
	pair = 0;
	for (int i = 0; i < 13; i++) {
		if (num_rank[i]!=0)
		{
			combo++;
		}
	}
	if (combo == 5)
	{
		straight = true;
	}
	else if(combo == 4)
	{
		four = true;
	}
	else if (combo == 3) {
		three = true;
	}
	else if (combo == 2) {
		pair++;
	}

	int same_color=num_suit[0];//用来判断相同花色的数量
	int suit_pair = 0;
	for (int i = 0; i < 4; i++) {
		if (num_suit[i]> same_color)
		{
			same_color = num_suit[i];
		}
	}
	if (same_color == 5)
	{
		flush = true;
	}
	else if (same_color == 2)
	{
		pair++;
	}
}

void print_result(void) {
	if (flush && straight)//同花顺
	{
		printf("Straight flush\n");
	}
	else if(four)//四条
	{
		printf("Four of a Kind\n");
	}
	else if (three && pair == 1) {
		printf("Full House\n");//葫芦
	}
	else if (flush) {
		printf("Flush\n");//同花
	}
	else if (straight) {
		printf("Straight\n");//顺子
	}
	else if (three) {
		printf("Three\n");//三张
	}
	else if (pair == 2) {
		printf("Two Pairs\n");//两对
	}
	else if (pair == 1) {
		printf("One Pair\n");//一对
	}
	else
	{
		printf("High Card\n");//高牌
	}
}

int main() {
	for ( ;;)
	{
		read_card();
		analyze_card();
		print_result();
		

	}
	return 0;
}