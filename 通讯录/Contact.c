#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu(void)
{
	printf("************************************\n");
	printf("****  1.增加信息   2.删除信息   ****\n");
	printf("****  3.查找信息   4.修改信息   ****\n");
	printf("****  5.排序       6.清空信息   ****\n");
	printf("****  7.打印       8.清空页面   ****\n");
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
};//枚举方便查看

int main()
{
	int input = 0;
	//创建通讯录
	contact con;
	//初始化通讯录
	Init_con(&con);

	do
	{
		menu(); //创建目录
		printf("选择功能:>");
		scanf("%d", &input);
		
		switch (input)
		{
		case ADD:
			ADD_con(&con);    //增加信息
			break;
		case DEL:
			Delete_con(&con); //删除信息
			break;
		case SEARCH:
			Search_con(&con); //查找信息
			break;
		case REVISE:
			Recise_con(&con); //修改信息
			break;
		case SORT:
			Sort_con(&con);   //排序信息--按姓名排序
			break;
		case EMPTY:
			Empty_con(&con);   //清空所有的个人信息
			printf("清空完毕！\n");
			break;
		case PRINT:
			Print_con(&con);  //打印通讯录
			break;
		case CLEAN:
			perror("CLEAN");
			system("cls");    //清空页面
			printf("清理成功！\n");
			break;
		case EXIT:
			Destroyed(&con);
			printf("再见！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}

	} while (input);

	return 0;
}



