#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("************************\n");
	printf("*****1.�ӷ�  2.����*****\n");
	printf("*****3.�˷�  4.����*****\n");
	printf("*****    0.�˳�   ******\n");
	printf("************************\n");
}

void Calc(int (*pf)(int, int)) //�ú���ָ�����
{
	int x = 0;
	int y = 0;
	printf("����������:");
	scanf("%d %d", &x, &y);
	int ret = pf(x, y);
	printf("%d\n", ret);

}
//������������
//void Calc(int i, int (*calc[5])(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("����������:");
//	scanf("%d %d", &x, &y);
//	int ret = (*calc[i])(x, y);
//	printf("%d\n", ret);
//
//}

int main()
{

	int input = 1;
	int x = 0;
	int y = 0;
	int ret = 0;
	//������
	// �Ѻ�����ַ�洢�ں���ָ�������У�
	// �����СΪ5��ǰ���ʼ��һ��0������������input���ϣ�
	//int (*calc[5])(int, int) = { 0,Add,Sub,Mul,Div };

	do
	{
		menu();
		printf("ѡ���㷨:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);          //����һ���Ѻ�����ַ��Ϊ����
			//Calc(input,calc);   //����������input��cale����ָ��������Ϊ����
			break;
		case 2:
			Calc(Sub);
			//Calc(input,calc);
			break;
		case 3:
			Calc(Mul);
			//Calc(input,calc);
			break;
		case 4:
			Calc(Div);
			//Calc(input,calc);
			break;
		case 0:
			puts("�˳��������");
			break;
		default:
			puts("���������룺");
			break;
		}


	} while (input);



	return 0;
}

