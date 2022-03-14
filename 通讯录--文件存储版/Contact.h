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


//����ͨѶ¼
typedef struct PeoInformation
{
	int Sort;
	char Name[MAX_NAME];
	char Sex[MAX_SEX];
	int Age;
	char Tele[MAX_TELE];
	char Addr[MAX_ADDR];
}Infor;


//��̬�ڴ�
typedef struct contact
{
	Infor* data;   //ָ��̬�ڴ�
	int sz;        //��Ϣ����
	int capacity;  //��ǰ�ڴ��������
}contact;


//��ʼ��ͨѶ¼
void Init_con(contact* pc);

//������Ϣ
void ADD_con(contact*pc);

//��ӡ��Ϣ
void Print_con(contact* pc);

//������Ϣ
void Search_con(contact* pc);

//ɾ����Ϣ
void Delete_con(contact* pc);

//�޸���Ϣ
void Recise_con(contact* pc);

//������Ϣ
void Sort_con(contact* pc);

//������еĸ�����Ϣ
void Empty_con(contact* pc);

//�ͷ��ڴ�free
void Destroyed(contact* pc);

//�����ڴ�
void save_con(contact* pc);

//��д�ڴ�
void read_con(contact* pc);

//����ڴ�
void check_con(contact* pc);
