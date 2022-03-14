#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	int n = 1;  //高
//	while (n)
//	{
//		printf("输入高度:>");
//		scanf("%d", &n);
//		if (n == EOF)
//			return 1;
//		int i = 0;
//		int j = 0;
//		int left = 0;
//		int right = n;
//
//		for (i = 0; i < n; i++)
//		{
//
//			for (j = 0; j < n; j++)
//			{
//				if (j == left || j == right - 1)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//			left++;
//			right--;
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int year = 0;
//	int month = 0;
//
//	printf("输入年份和月:>");
//	scanf("%d %d", &year, &month);
//  if (year && month)== EOF
//		return 1;
//
//	if (month <= 7 && month != 2)
//	{
//		if (month % 2 == 0)
//			printf("30\n");
//		else
//			printf("31\n");
//	}
//	else if (month > 7 && month < 13)
//	{
//		if (month % 2 == 0)
//			printf("31\n");
//		else
//			printf("30\n");
//	}
//	else if (month == 2)
//	{
//		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
//			printf("29\n");
//		else
//			printf("28\n");
//	}
//	else
//		printf("输入错误\n");
//
//
//	return 0;
//}

//int main()
//{
//	int arr[7] = { 0 };
//	printf("输入7个数:>");
//	scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]);
//	if ((arr[0] && arr[1] && arr[2] && arr[3] && arr[4] && arr[5] && arr[6]) == NULL)
//		return 1;
//	int min = arr[0];
//	int max = arr[0];
//	int i = 0;
//	float sum = 0;
//
//	for (i = 0; i < 7; i++)
//	{
//		if (arr[i] < min)
//			min = arr[i];
//		else if (arr[i] > max)
//			max = arr[i];
//		sum += arr[i];
//	}
//
//	printf("%.2lf\n", (sum - min - max) / 5);
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	int min = 100;
//	int max = 0;
//	int i = 0;
//	int sum = 0;
//
//	for (i = 0; i < 7; i++)
//	{
//		printf("输入数值:>");
//		scanf("%d", &num);
//		sum += num;
//		if (num < min)
//			min = num;
//		if (num > max)
//			max = num;
//	}
//
//	printf("%.2f\n", (sum - min - max) / 5.0);
//
//	return 0;
//}

//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	printf("输入年份和月:>");
//
//	while (scanf("%d %d", &year, &month))
//	{
//		int d = day[month];
//		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
//			d += 1;
//		printf("%d\n", d);
//	
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[51] = { 0 };
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &num);
//		arr[i] = num;
//	}
//	int new = 0;
//	scanf("%d", &new);
//	arr[n] = new;
//	int count = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				count = 1;
//			}
//
//		}
//		if (0 == count)
//		{
//			printf("没有可变的了\n");
//			break;
//		}
//	}
//
//	for (i = 0; i < n+1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[51] = { 0 };
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num = 0;
	scanf("%d", &num);

	for (i = n - 1; i >= 0; i--)
	{
		if (num < arr[i])
		{
			arr[i + 1] = arr[i];
		}
		else
		{
			arr[i + 1] = num;
			break;
		}

	}	

	for (i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}



