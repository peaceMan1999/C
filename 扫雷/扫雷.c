#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("*********   1.��ʼ   ********\n");
	printf("*********   0.����   ********\n");
	printf("*****************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	
	//��ʼ������
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	
	//�����һ������
	int err = 0; 
	
	//�����
	set_mine(mine, ROW, COL,err);

	//��ӡ����
	//print_board(mine, ROW, COL);
	print_board(show, ROW, COL);
	
	//��Ϸ����--ѡ���ж�
	choise(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	do   
	{
		srand((unsigned int)time(NULL));
		//Ŀ¼
		menu();
		printf("������:>");
		scanf("%d", &input);
		if (1 == input)
		{
			game();
		}
		else if (0 == input)
		{
			printf("������Ϸ\n");
		}
		else
		{
			printf("����������!\n");
		}

	} while (input);


	return 0;
}
