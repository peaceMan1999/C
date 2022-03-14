#pragma once

//引用头文件
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//定义全局变量
#define TRA  3 //transverse
#define POR  3 //portrait

//设置棋盘
void set_board(char board[TRA][POR], int tra, int pro);

//初始化棋盘
void init_board(char board[TRA][POR], int tra, int por);

//玩家下棋
void py_move(char board[TRA][POR], int tra, int por);

//判断
char judge(char board[TRA][POR], int tra, int por);

//电脑下棋
void com_move(char board[TRA][POR], int tra, int por);