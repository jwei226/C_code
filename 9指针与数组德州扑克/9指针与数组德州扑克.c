//�����˿ˣ�дһ������ѭ����ȡ 5 ������(���� 0 ��������)��Ȼ������е��Ʒ�Ϊ����ĳһ�ࣺ
//1.ͬ��˳ 2.���� 3.��«(3 + 2) 4. ͬ�� 5. ˳�� 6.���� 7.���� 8. һ�� 9.���ơ�
//����Ի����£�
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

//��Ҫ֪����ɫsuit�͵���rank�м���
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
	//��������
	int card_read = 0;

	bool bad_card = false;//���ƷǷ��ƵĲ�������
	bool cards_in_hand[13][4] = { false };//�ж����Ƿ��ظ���false��ʾû���ظ�
	while (card_read<5)
	{
		bad_card = 0;//��ֹ��һ��������ִ���Ӱ����һ��������ȷ
		printf("Enter a card: ");

		//���ܵ���
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

		//���ܻ�ɫ
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

		//�����������ʣ��getchar()����
		while ((c=getchar())!='\n')
		{
			if (c != ' ' || c != '\t')
			{
				bad_card = true;
			}
		}
		

		//�ų��Ƿ��ƣ���������ȡ���������´���
		// ����card_read���ӣ�������cards_in_hand���棬��Ӧ�����ͻ�ɫ����
		
		//Bad Card�ж�
		if (bad_card)//��Bad Card
		{
			printf("Bad Card; ignored.\n");
		}
		//Duplivate Card�ж�,����һ������������cards_in_hand[]
		else if(cards_in_hand[rank][suit])//
		{
			printf("Duplicate Card; ignored.\n");
		}
		else
		{
			card_read++;
			cards_in_hand[rank][suit] = true;//����������
			num_rank[rank]++;//�õ���
			num_suit[suit]++;//�û�ɫ

		}
	}
}

bool flush;//ͬ��,����ͬһ��ɫ����
bool straight;//˳��,����˳������
bool four;//������5���Ƶ��е�4������һ��
bool three;//3������һ��
int pair;//��
void analyze_card(void) {
	flush = false; // ��ʼ��Ϊ false
	straight = false; // ��ʼ��Ϊ false
	four = false;
	three = false;
	pair = 0;

	int combo=0;//�����ж�˳���Ƶ�����
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

	int same_color=num_suit[0];//�����ж���ͬ��ɫ������
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
	if (flush && straight)//ͬ��˳
	{
		printf("Straight flush\n");
	}
	else if(four)//����
	{
		printf("Four of a Kind\n");
	}
	else if (three && pair == 1) {
		printf("Full House\n");//��«
	}
	else if (flush) {
		printf("Flush\n");//ͬ��
	}
	else if (straight) {
		printf("Straight\n");//˳��
	}
	else if (three) {
		printf("Three\n");//����
	}
	else if (pair == 2) {
		printf("Two Pairs\n");//����
	}
	else if (pair == 1) {
		printf("One Pair\n");//һ��
	}
	else
	{
		printf("High Card\n");//����
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