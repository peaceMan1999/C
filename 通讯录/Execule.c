#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//��̬�ڴ��ʼ��
void Init_con(contact* pc)
{
	pc->data = (Infor*)malloc(MAX_STRUCT * sizeof(Infor));

	//�ڴ�����
	pc->sz = 0;
	pc->capacity = MAX_STRUCT;

	if (pc->data == NULL)
	{
		perror("calloc");
		return;
	}

}

//��ӡȫ����Ϣ�ĺ������뵥����ӡ Little_print ��ͬ��
void Print_con(contact* pc)
{
	int i = 0;
	//����б�
	printf("|%-3s\t|%-4s\t|%-7s\t|%-3s\t|%-13s\t|%-30s\n", "���", "����", "�Ա�", "����", "�绰", "��ַ");

	for (i = 0; i < pc->sz; i++)
	{
		printf("|%-3d\t|%-4s\t|%-7s\t|%-3d\t|%-13s\t|%-30s\n", 
									pc->data[i].Sort,
									pc->data[i].Name,
									pc->data[i].Sex,
									pc->data[i].Age,
									pc->data[i].Tele,
									pc->data[i].Addr  );

	}
}

//������Ϣ
void ADD_con(contact* pc)
{

	if (pc->sz == pc->capacity)
	{
		Infor* ptr = (Infor*)realloc(pc->data, (pc->capacity + MAX_SZ) * sizeof(Infor));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += MAX_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("ADD_con");
			printf("����ʧ��\n");
			return;
		}

	}

	//�����Ϣ
	printf("����:>");
	scanf("%s", pc->data[pc->sz].Name); //��Ϊname��������Ԫ�ص�ַ�����Բ���&
	printf("�Ա�:>");
	scanf("%s", pc->data[pc->sz].Sex); 
	printf("����:>");
	scanf("%d", &pc->data[pc->sz].Age); //Age��int���ͣ�Ҫ&
	printf("�绰:>");
	scanf("%s", pc->data[pc->sz].Tele);
	printf("��ַ:>");
	scanf("%s", pc->data[pc->sz].Addr);
	pc->data[pc->sz].Sort = pc->sz+1;

	pc->sz++;  //����+1
	printf("��ӳɹ���\n");	
	
}

//�����ӡ���� i �ĺ���
static void Little_print(contact* pc, int i)
{
	printf("|%-3s\t|%-4s\t|%-7s\t|%-3s\t|%-13s\t|%-30s\n", "���", "����", "�Ա�", "����", "�绰", "��ַ");

	printf("|%-3d\t|%-4s\t|%-7s\t|%-3d\t|%-13s\t|%-30s\n",
		pc->data[i].Sort,
		pc->data[i].Name,
		pc->data[i].Sex,
		pc->data[i].Age,
		pc->data[i].Tele,
		pc->data[i].Addr);

}

//��������
static int Find_name(contact* pc, char name[])
{
	int i = 0;
	int count = 0;  //����count�Ƿ����仯��������Ϣ
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].Name) == 0)
		{
			Little_print(pc, i); //��ӡ�����ĺ���
			count= 1;
		}
	}
	if (0 == count)
	{
		printf("û�д�����Ϣ\n");
		return 0;
	}
	return 1;
}

//������Ϣ
void Search_con(contact* pc)
{

	char name[MAX_NAME] = { 0 };
	printf("����Ҫ���ҵ�����:>\n");
	scanf("%s", name);
	//��������
	Find_name(pc, name);

}

//��̬p�ڴ� -- ɾ��ģ��
static int* P_MAX(int* p, int sz)
{
	int count = 1;  //����

	if (*(p+sz-1) != '\0')
	{
		int*ptr = (int*)realloc(p, (MAX_STRUCT + count * MAX_SZ) * sizeof(int));
		if (ptr != NULL)
		{
			p = ptr;
			printf("���ݳɹ�\n");
			count++;
		}
		else
		{
			perror("int* P_MAX()");
			printf("����ʧ��\n");
			return;
		}
	}

}

//ɾ��ģ��ר�ú��� -- �жϺ󴢴�
static int* Judge_num(contact*pc, char *name) 
{
	int p[MAX_STRUCT] = { 0 };
	int i = 0;
	int num = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].Name) == 0)
		{
			//��ͬ�ʹ�����������
			p[num] = pc->data[i].Sort;
			//�ж���������
			int sz = sizeof(p) / sizeof(p[0]);
			P_MAX(p, sz, pc);
		}
	}
	return p;
}

//ɾ��ģ��ר�ú��� -- �ж�judge��������ֵ��ѡ�������Ƿ����
static int compare_num(int* p, int num)
{
	while (*p)
	{
		if (num == *p)
			return 1;
		p++;
	}
	return 0;

}

//ɾ����Ϣ
void Delete_con(contact* pc)
{
	//�ж���û����Ϣ
	if (pc->sz == 0)
	{
		printf("û�п�ɾ������Ϣ��~\n");
		return;
	}

	//����ɾ���ߵ�����
	char name[MAX_NAME] = { 0 };
	printf("����ɾ��������:>");
	scanf("%s", name);

	//�ҳ�����
	int ret = Find_name(pc, name);
	if (0 == ret)
		return;

	//ѡ��ɾ�����
	int num = 0;
	printf("ѡ��Ҫɾ���ı��:>");
	scanf("%d", &num);
	int* p = Judge_num(pc, name); //��Judge_num�����жϺõ���������ָ�����ʽ����
	int tmp = compare_num(p, num); 
	if (0 == tmp)
	{
		printf("�������\n");
		return;
	}

	if (num<0 || num>pc->sz)
	{
		printf("�������\n");
		return;
	}

	//�ж�ѡ����
	if (pc->data[num - 1].Sort != num)
	{
		printf("�����Ų���~\n");
		return;
	}

	//��������
	int i = 0;
	for (i = num - 1; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
		pc->data[i].Sort = pc->data[i].Sort - 1;  //Ϊ���������ν��ϣ�Ҫ��ȥ1
	}

	pc->sz--;
	printf("ɾ���ɹ���\n");


}

//�޸���Ϣ
void Recise_con(contact* pc)
{
	if (pc->sz == 0)
	{
		printf("û�п��޸ĵ���Ϣ��~\n");
		return;
	}

	//ѡ��Ҫ�޸ĵ����
	int num = 0;
	printf("�����޸ĵ����:>");
	scanf("%d", &num);

	//��ʾһ��
	Little_print(pc, num-1);
	
	//�޸�Ԫ��
	char element[5] = { 0 };
	printf("�����޸ĵ�Ԫ��:>");
	scanf("%s", element);

	char value[MAX_ADDR] = { 0 };  //������סַ��Ϣ����ţ��Ͳ���ÿһ��������������
	int age = 0;

	if (strcmp(element, "����") == 0)
	{
		printf("�����޸ĵ�ֵ:>\n");
		scanf("%s", pc->data[num - 1].Name);
	}
	else if (strcmp(element, "�Ա�") == 0)
	{
		printf("�����޸ĵ�ֵ:>\n");
		scanf("%s", pc->data[num - 1].Sex);
	}
	else if (strcmp(element, "����") == 0)
	{
		printf("�����޸ĵ�ֵ:>\n");
		scanf("%d", &pc->data[num - 1].Age);
	}
	else if (strcmp(element, "�绰") == 0)
	{
		printf("�����޸ĵ�ֵ:>\n");
		scanf("%s", pc->data[num - 1].Tele);
	}
	else if (strcmp(element, "��ַ") == 0)
	{
		printf("�����޸ĵ�ֵ:>\n");
		scanf("%s", pc->data[num - 1].Addr);
	}
	else
		printf("����\n");
	printf("�޸ĳɹ�\n");
	//��ӡһ��
	Little_print(pc, num - 1);
}

//������Ϣ
void Sort_con(contact* pc)
{
	int i = 0;
	int j = 0;

	//ð������
	for (i = 0; i < pc->sz; i++)
	{
		int count = 0;

		for (j = 0; j < pc->sz - i - 1; j++)
		{
			if (strcmp(pc->data[j].Name,pc->data[j+1].Name) > 0)
			{
				Infor tmp = pc->data[j];    //�����tmp��Infor���ͣ���Ϊ����Ҫ�洢��ֵ��Infor�ṹ��
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				pc->data[j + 1].Sort = pc->data[j + 1].Sort + 1;  //��Ÿ�һ��
				pc->data[j].Sort = pc->data[j].Sort - 1;

				count = 1;  //����н����������͸ı�count
			}

		}
		if (0 == count)  //���countΪ0��˵��û�пɽ�����ֵ������
			break;
		
	}
	printf("˳�����źã�\n");
	Print_con(pc);
}

//������еĸ�����Ϣ
void Empty_con(contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz+1; i++)
	{
		pc->sz--;   //�����±��൱��ɾ����ֻ������������
		if (0 == pc->sz--)
		{
			break;
		}
	}
}

//�ͷ��ڴ�
void Destroyed(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz;
	pc->capacity;
	printf("�ͷųɹ�\n");
}
