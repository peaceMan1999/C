#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//atoi����--�ַ���ת��Ϊ����

//int main()
//{
//	char *p= "0123";
//	int ret = atoi(p);
//	printf("%d", ret);
//
//	return 0;
//}

//my_atoi����
//1.�������ַ���
//2.�ո񡢿��ַ���
//3.������
//4.������Χ

//enum judgement
//{
//	incorrect,  //0
//	correct		//1
//};
//
//enum judgement judge = incorrect;
//
//int my_atoi(const char* ps)
//{	
//	if (NULL == ps)  //�жϿ�ָ��
//		return 0;
//
//	if ('\0' == *ps) //�жϿ��ַ���
//		return 0;
//
//	while (isspace(*ps))  //�жϿո�
//	{
//		ps++;
//	}
//
//	int flag = 1;		//�ж�����
//	if (*ps == '-')    
//		flag = -1;
//	ps++;
//	int num = 0;        //�ж��Ƿ�����
//	while (*ps)
//	{
//		if (isdigit(*ps))
//		{
//			num = num * 10 + flag * (*ps - '0');
//			ps++;
//		}
//		else
//			return num;
//
//	}
//	judge = correct;
//	return num;
//}
//
//int main()
//{
//	char* p = "    -1234a";
//	int ret = my_atoi(p);
//	if (judge == correct)
//	{
//		printf("��ȷ��ʾ: %d\n", ret);
//	}
//	else if (judge == incorrect)
//	{
//		printf("������ʾ: %d\n", ret);
//	}
//
//	return 0;
//}
//
