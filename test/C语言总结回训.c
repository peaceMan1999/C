#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	printf("\\q");
//	return 0;
//}
//
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("输入:>");
//	scanf("%d %d", &x, &y);
//	printf("最大值是: %d\n", Max(x, y));
//
//	return 0;
//}

//排序
//写代码将三个整数数按从大到小输出。
//例如：
//输入：2 3 1
//输出：3 2 1

//int main()
//{
//	int x, y, z;
//	printf("输入3个数:>");
//	scanf("%d %d %d", &x, &y, &z);
//	
//	if (x < y)
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	}
//	if (y < z)
//	{
//		int tmp = y;
//		y = z;
//		z = tmp;
//	}
//	if (x < y)
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	}
//
//	printf("%d %d %d\n", x, y, z);
//
//	return 0;
//}


//写一个代码：打印100~200之间的素数

//int main()
//{
//	int  i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if ((i % j) == 0)
//			{
//				int num = i;
//				printf("%d ", num);
//				break;
//			}
//		}
//	}
//
//
//	return 0;
//}


//
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//最大公约数

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = (a > b) ? a : b;
//	int i = 0;
//	int num = 0;
//	for (i = 1; i <= ret; i++)
//	{
//		if ((a % i) == 0 && (b % i) == 0)
//			num = i;
//	}
//	printf("%d ", num);
//	return 0;
//}

//编写程序数一下 1到 100 的所有整数中出现多少个数字9

//int main()
//{
//	int i = 0;
//	int count = 0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("%d ", count);
//
//	return 0;
//}

//在屏幕上输出9*9乘法口诀表

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d * %2d = %2d ",j, i, j * i);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//完成上课的猜数字游戏
//#include <stdlib.h>
//#include <time.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	srand((unsigned)time(NULL));
//	int x = rand() % 100;
//	if (x == num)
//		printf("yes\n");
//	else
//		puts("no\n");
//
//	return 0;
//}

//二分查找

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz;
	int num = 0;
	scanf("%d", &num);
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (num == mid)
		{
			printf("%d", mid - 1);
			break;
		}
		else if (num > mid)
			left = mid + 1;
		else if (num < mid)
			right = mid - 1;
		else
			puts("err");
	}

	return 0;
}



