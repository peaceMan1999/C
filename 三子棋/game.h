#pragma once

//����ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//����ȫ�ֱ���
#define TRA  3 //transverse
#define POR  3 //portrait

//��������
void set_board(char board[TRA][POR], int tra, int pro);

//��ʼ������
void init_board(char board[TRA][POR], int tra, int por);

//�������
void py_move(char board[TRA][POR], int tra, int por);

//�ж�
char judge(char board[TRA][POR], int tra, int por);

//��������
void com_move(char board[TRA][POR], int tra, int por);