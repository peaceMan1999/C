#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[TRA][POR], int tra, int por)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < tra; i++)
	{
		for (j = 0; j < por; j++)
		{
			board[i][j] = ' ';			
		}	
	}
}

void set_board(char board[TRA][POR], int tra, int por)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < tra; i++)
	{
		for (j = 0; j < por; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < por - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < tra; j++)
		{
			
			if (i < por - 1)
			{
				printf("---");
				if (j < tra - 1)
					printf("|");
			}
		}
		printf("\n");
	}

}

void py_move(char board[TRA][POR], int tra, int por)
{
	
	while (1)
	{
		printf("请落子(例如‘1’空格‘1’):>");
		scanf("%d %d", &tra, &por);
		if (tra <= TRA && tra > 0 && por <= POR && por > 0)
		{
			if (board[tra - 1][por - 1] != '*' && board[tra - 1][por - 1] != '#')
			{
				board[tra - 1][por - 1] = '*';
				break;
			}
			else
				printf("请重新输入!!!!!!\n");
		}
		else
			printf("请重新输入!!!!!!\n");

	}
	
}


int is_full(char board[TRA][POR], int tra, int por)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < tra; i++)
	{
		for (j = 0; j < por; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char judge(char board[TRA][POR], int tra, int por)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < tra; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < tra; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int full = is_full(board, TRA, POR);
	if (full == 1)
	{
		return 'Q';
	}
	
	return 'C';
}



void com_move(char board[TRA][POR], int tra, int por)
{
	
	while(1)
	{
		tra = rand() % 3;
		por = rand() % 3;
		if (board[tra][por] == ' ')
		{
			board[tra][por] = '#';
			break;
		}
	}
}