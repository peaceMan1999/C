#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("*********   1.开始   ********\n");
	printf("*********   0.结束   ********\n");
	printf("*****************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	
	//初始化棋盘
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	
	//假如第一个踩雷
	int err = 0; 
	
	//埋地雷
	set_mine(mine, ROW, COL,err);

	//打印棋盘
	//print_board(mine, ROW, COL);
	print_board(show, ROW, COL);
	
	//游戏主体--选择，判断
	choise(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	do   
	{
		srand((unsigned int)time(NULL));
		//目录
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		if (1 == input)
		{
			game();
		}
		else if (0 == input)
		{
			printf("结束游戏\n");
		}
		else
		{
			printf("请重新输入!\n");
		}

	} while (input);


	return 0;
}
