#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 10
#define MAX_TELE 13
#define MAX_ADDR 30
#define MAX_SEX 7
#define MAX_STRUCT 3
#define MAX_SZ 2


//创建通讯录
typedef struct PeoInformation
{
	int Sort;
	char Name[MAX_NAME];
	char Sex[MAX_SEX];
	int Age;
	char Tele[MAX_TELE];
	char Addr[MAX_ADDR];
}Infor;


//动态内存
typedef struct contact
{
	Infor* data;   //指向动态内存
	int sz;        //信息个数
	int capacity;  //当前内存最大容量
}contact;


//初始化通讯录
void Init_con(contact* pc);

//增加信息
void ADD_con(contact*pc);

//打印信息
void Print_con(contact* pc);

//查找信息
void Search_con(contact* pc);

//删除信息
void Delete_con(contact* pc);

//修改信息
void Recise_con(contact* pc);

//排序信息
void Sort_con(contact* pc);

//清空所有的个人信息
void Empty_con(contact* pc);

//释放内存free
void Destroyed(contact* pc);

//保存内存
void save_con(contact* pc);

//读写内存
void read_con(contact* pc);

//检查内存
void check_con(contact* pc);
