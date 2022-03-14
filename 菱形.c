#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{

	int n = 0;    //高度
	printf("多高:");
	scanf("%d", &n);
	int i = 0;
	int j = 0;

	for (i = 1; i < n; i++)    //打印上半部分
	{
		for (j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = 0; i < 2 * n - 1; i++)  //打印中间一行
	{
		printf("*");
	}printf("\n");

	for (i = 0; i < n; i++)      //打印下半部分
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 2 * (n - i) - 1; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}