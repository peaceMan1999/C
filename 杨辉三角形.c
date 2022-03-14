#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1
//1 5 10 10 5 1

#define N 100 
//因为二维数组里必须是常量值，所以定义一个常量N

int main()
{
	int n = 0;
	int arr[N][N] = { 0 };
	printf("输入行数:");
	scanf("%d", &n);
	int i = 0;
	int j = 0;


	for (i = 0; i < n; i++)
	{

		for (j = 0; j <= i; j++) //先把数组初始化
		{
			arr[i][j] = 1;
		}

	}

	for (i = 2; i < n; i++) //计算中间数
	{

		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}

	}


	for (i = 0; i < n; i++)  //打印数组
	{
		//打印每一行的空格
		for (j = n - i - 1; j > 0; j--)
		{
			printf(" ");
		}
		//打印每一行的数组
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}