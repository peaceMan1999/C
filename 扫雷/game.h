#pragma once

//ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//�������
#define ROW 9   //��
#define COL 9   //��
#define ROWS ROW + 2   
#define COLS COL + 2  

#define count 79 //������

//��ʼ������
void init_board(char board[ROWS][COLS], int rows, int cols, char x);

//�����
void set_mine(char board[ROWS][COLS], int row, int col);

//��ӡ����
void print_board(char board[ROWS][COLS], int row, int col);

//ѡ��λ��
void choise(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

