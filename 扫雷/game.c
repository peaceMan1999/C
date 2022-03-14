#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void init_board(char board[ROWS][COLS], int rows, int cols, char x)
{
	//���mine,show
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
	//��ӡ����
	int i = 0;
	int j = 0;

	for (i = 0; i <= row; i++) //��ӡ����
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
	//���õ��ף���������ˣ���ȥ�׵�λ�ã������ˢһ��
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
	show[x][y] = judge(mine, x, y); //����
	//�����Χ���ϰ�

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
	//������8 *��0�������Ǻ��滹��Ҫ�ӡ�0������7������
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
	//��show����ġ�*���ж��Ƿ�ʤ��
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
	int err = 0;  //��һ�β��׺�+1������ˢ��
	int first = 0; //�ж��Ƿ��һ�β���

	while (1)
	{
		int ret = iswin(show, row, col);  //�ж���Ӯ
		if (ret == count)
		{
			printf("��ϲ�㣡��Ӯ�ˣ�\n");
			break;
		}
		else
		{
			printf("��ʽΪ�����֡��ո����֡�\n");
			printf("�����������һ��:>");
			scanf("%d %d", &x, &y);
			printf("\n");
			if (x <= row && x >= 1 && y <= col && y >= 1)
			{
				if (mine[x][y] == '1' && 0 == first) //ֻ�ܲ���һ��
				{
					mine[x][y] = '0';
					err = count - 1;   //ˢ����
					set_mine(mine, row, col,err);   //����
					spread(mine, show, row, col, x, y);   //��ɢ
					system("cls");     //����
					print_board(show, row, col);  //��ӡ����
					first++;  //ֻ��һ�ε�һ��

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
					printf("�㱻ը������\n");
					print_board(mine, row, col);
					break;
				}
			}//end of if
			else
			{
				printf("���������룡");
			}
		}
		
	}//end of while

}
