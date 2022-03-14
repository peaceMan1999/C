#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

int find_number(int arr[3][3], int r, int c, int k)
{
	int x = 0;
	int y = c - 1;    //我们要检查x轴表示最右边的数

	while (x < r && y >= 0)
	{
		if (arr[x][y] < k)  //最右边的数<k，说明不在此行
		{
			x++;
		}
		else if (arr[x][y] > k)  //最右边的数>k，说明不在此列
		{
			y--;
		}
		else if (k == arr[x][y])
		{
			printf("%d %d\n", x, y);
			return 1;  //找到返回1，并且打印坐标
		}
		else
		{
			return 0;  //没找到返回0；
		}
	}
}

int main()
{

	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	printf("要找的整数:");
	scanf("%d", &k);

	int ret = find_number(arr, 3, 3, k);
	
	if (1 == ret)
	{
		printf("找到啦！\n");
	}
	else
	{
		printf("没找到~\n");
	}

	return 0;
}


