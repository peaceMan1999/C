#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
//��һ�ַ�����
int main()
{
	int x = 0;				//�������
	int y = 0;
	scanf("%d %d", &x, &y); //�ǵ�include <string.h>
	if (x > y)				//if�ж�
	{
		printf("%d\n", x);
	}
	else
	{
		printf("%d\n", y);
	}
	return 0;
}

//�ڶ��ַ�����
int Max(int x,int y)        //��������
{
	if (x > y)
		return x;			//returnֵд����������Max��ֵ
	else
		return y;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int number = Max(a, b); //�ú����ķ�ʽ��� ��number����Maxֵ
	printf("%d", number);

	return 0;
}




