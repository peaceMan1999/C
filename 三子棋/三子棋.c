#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("********  1.��ʼ   ********\n");
	printf("********  0.����   ********\n");
	printf("***************************\n");
}

void begin()
{
	int ret = 0;
	char board[TRA][POR];	
	init_board(board, TRA, POR);//��ʼ������
	set_board(board, TRA, POR);//��������
	while (1)
	{
		py_move(board, TRA, POR);   //�����
		set_board(board, TRA, POR); //��ӡ����
		ret = judge(board, TRA, POR);//�ж�
		if (ret != 'C')
			break;
		printf("-----������-----\n");
		
		com_move(board, TRA, POR);  //������
		set_board(board, TRA, POR); //��ӡ����
		ret = judge(board, TRA, POR);
		if (ret != 'C')
			break;
		printf("-----�����-----\n");

	}
	if (ret == '*')
		printf("��Ӯ�ˣ�\n");
	else if (ret == '#')
		printf("����Ӯ�ˣ�\n");
	else if(ret == 'Q')
		printf("ƽ�֣�\n");

}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//Ŀ¼ѡ�񣬿�ʼ������
	do
	{
		menu();
		printf("������:");
		scanf("%d", &input);
		//�ж�
		switch (input)
		{
			case(1):
				printf("��ʼ��Ϸ��\n");
				begin();
				break;
			case(0):
				printf("��Ϸ������\n");
				break;
			default:
				printf("���������룡\n");
		}

	} while (input);

	return 0;
}