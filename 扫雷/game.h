#pragma once

//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//定义变量
#define ROW 9   //行
#define COL 9   //列
#define ROWS ROW + 2   
#define COLS COL + 2  

#define count 79 //雷数量

//初始化棋盘
void init_board(char board[ROWS][COLS], int rows, int cols, char x);

//埋地雷
void set_mine(char board[ROWS][COLS], int row, int col);

//打印棋盘
void print_board(char board[ROWS][COLS], int row, int col);

//选择位置
void choise(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

