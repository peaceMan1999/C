#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu(void)
{
	printf("************************************\n");
	printf("****  1.������Ϣ   2.ɾ����Ϣ   ****\n");
	printf("****  3.������Ϣ   4.�޸���Ϣ   ****\n");
	printf("****  5.����       6.�����Ϣ   ****\n");
	printf("****  7.��ӡ       8.���ҳ��   ****\n");
	printf("****         0.EXIT              ***\n");
	printf("************************************\n");

}

enum Choise
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	REVISE,
	SORT,
	EMPTY,
	PRINT,
	CLEAN
};//ö�ٷ���鿴

int main()
{
	int input = 0;
	//����ͨѶ¼
	contact con;
	//��ʼ��ͨѶ¼
	Init_con(&con);

	do
	{
		menu(); //����Ŀ¼
		printf("ѡ����:>");
		scanf("%d", &input);
		
		switch (input)
		{
		case ADD:
			ADD_con(&con);    //������Ϣ
			break;
		case DEL:
			Delete_con(&con); //ɾ����Ϣ
			break;
		case SEARCH:
			Search_con(&con); //������Ϣ
			break;
		case REVISE:
			Recise_con(&con); //�޸���Ϣ
			break;
		case SORT:
			Sort_con(&con);   //������Ϣ--����������
			break;
		case EMPTY:
			Empty_con(&con);   //������еĸ�����Ϣ
			printf("�����ϣ�\n");
			break;
		case PRINT:
			Print_con(&con);  //��ӡͨѶ¼
			break;
		case CLEAN:
			perror("CLEAN");
			system("cls");    //���ҳ��
			printf("����ɹ���\n");
			break;
		case EXIT:
			Destroyed(&con);
			printf("�ټ���\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}

	} while (input);

	return 0;
}



