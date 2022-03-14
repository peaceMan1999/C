#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void init_board(char board[ROWS][COLS], int rows, int cols, char x)
{
	//填充mine,show
	int i = 0;
	int j = 0;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = x;
		}

	}//end of for 1

}

void print_board(char board[ROWS][COLS], int row, int col)
{
	//打印棋盘
	int i = 0;
	int j = 0;

	for (i = 0; i <= row; i++) //打印坐标
	{
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");
	}


}

void set_mine(char board[ROWS][COLS], int row, int col,int err)
{
	//设置地雷，如果踩雷了，减去雷的位置，随机再刷一个
	int set = count - err;
	
	while (set)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			set--;
		}		
	}

}


void  spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	show[x][y] = judge(mine, x, y); //本身
	//检查周围的老八

	if (mine[x - 1][y - 1] == '0')  //1
	{
		show[x - 1][y - 1] = judge(mine, x-1, y-1);

	}
	if (mine[x - 1][y] == '0')	    //2
	{
		show[x - 1][y] = judge(mine, x-1, y);

	}
	if (mine[x - 1][y + 1] == '0')  //3
	{
		show[x - 1][y + 1] = judge(mine, x-1, y+1);

	}
	if (mine[x][y + 1] == '0')      //4
	{
		show[x][y + 1] = judge(mine, x, y+1);

	}
	if (mine[x + 1][y + 1] == '0')  //5
	{
		show[x + 1][y + 1] = judge(mine, x+1, y+1);

	}
	if (mine[x + 1][y] == '0')      //6
	{
		show[x + 1][y] = judge(mine, x+1, y);

	}
	if (mine[x + 1][y - 1] == '0')  //7
	{
		show[x + 1][y - 1] = judge(mine, x+1, y-1);

	}
	if (mine[x][y - 1] == '0')      //8
	{
		show[x][y - 1] = judge(mine, x, y-1);

	}

}


static int judge(char mine[ROWS][COLS], int x, int y)
{
	//本来是8 *‘0’，但是后面还是要加‘0’所以7个就行
	return  mine[x-1][y-1]
			+ mine[x-1][y]
			+ mine[x-1][y+1]
			+ mine[x][y+1]
			+ mine[x+1][y+1]
			+ mine[x+1][y]
			+ mine[x+1][y-1]
			+ mine[x][y-1] - 7 * '0' ;
			
}

int iswin(char show[ROWS][COLS], int row, int col)
{
	//以show上面的‘*’判断是否胜利
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				num++;
		}

	}
	return num;
}

void choise(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int err = 0;  //第一次踩雷后+1，重新刷雷
	int first = 0; //判断是否第一次踩雷

	while (1)
	{
		int ret = iswin(show, row, col);  //判断输赢
		if (ret == count)
		{
			printf("恭喜你！你赢了！\n");
			break;
		}
		else
		{
			printf("格式为‘数字’空格‘数字’\n");
			printf("请输入你的下一步:>");
			scanf("%d %d", &x, &y);
			printf("\n");
			if (x <= row && x >= 1 && y <= col && y >= 1)
			{
				if (mine[x][y] == '1' && 0 == first) //只能踩雷一次
				{
					mine[x][y] = '0';
					err = count - 1;   //刷新雷
					set_mine(mine, row, col,err);   //埋雷
					spread(mine, show, row, col, x, y);   //扩散
					system("cls");     //清屏
					print_board(show, row, col);  //打印棋盘
					first++;  //只踩一次第一雷

				}
				else if (mine[x][y] == '0')
				{
					spread(mine, show, row, col, x, y);
					system("cls");
					print_board(show, row, col);	

				}
				else
				{
					system("cls");
					printf("你被炸死啦！\n");
					print_board(mine, row, col);
					break;
				}
			}//end of if
			else
			{
				printf("请重新输入！");
			}
		}
		
	}//end of while

}
