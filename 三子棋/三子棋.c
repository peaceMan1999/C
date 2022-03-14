#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("********  1.开始   ********\n");
	printf("********  0.结束   ********\n");
	printf("***************************\n");
}

void begin()
{
	int ret = 0;
	char board[TRA][POR];	
	init_board(board, TRA, POR);//初始化棋盘
	set_board(board, TRA, POR);//设置棋盘
	while (1)
	{
		py_move(board, TRA, POR);   //玩家下
		set_board(board, TRA, POR); //打印棋盘
		ret = judge(board, TRA, POR);//判断
		if (ret != 'C')
			break;
		printf("-----电脑下-----\n");
		
		com_move(board, TRA, POR);  //电脑下
		set_board(board, TRA, POR); //打印棋盘
		ret = judge(board, TRA, POR);
		if (ret != 'C')
			break;
		printf("-----玩家下-----\n");

	}
	if (ret == '*')
		printf("你赢了！\n");
	else if (ret == '#')
		printf("电脑赢了！\n");
	else if(ret == 'Q')
		printf("平局！\n");

}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//目录选择，开始，结束
	do
	{
		menu();
		printf("请输入:");
		scanf("%d", &input);
		//判断
		switch (input)
		{
			case(1):
				printf("开始游戏：\n");
				begin();
				break;
			case(0):
				printf("游戏结束！\n");
				break;
			default:
				printf("请重新输入！\n");
		}

	} while (input);

	return 0;
}