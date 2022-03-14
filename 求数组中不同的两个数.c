#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//一个数组中只有两个不相同的数，编写一个函数找出来
// 1 2 3 4 5 6 1 2 3 4

void Find_dif(const int* p, int sz, int* x, int* y)
{
	int i = 0;
	int n = *p;

	for (i = 1; i < sz; i++)     //全部异或上
	{							 //假设数组是1 2 3 4 5 6 1 2 3 4
		n = n ^ *(p + i);        //那么n = 5^6 = 3;
	}							 //3的二进制是0011，因为异或1是指二进制位不同
								 //所以按1分类
	int pos = 0;
	for (i = 0; i < 32; i++)     //求出是第几个位不同
	{
		if (((n >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)     //分类并异或是，异或后的数就是不同的数
	{
		if (((*(p + i) >> pos) & 1) == 1)
		{
			num1 ^= *(p + i);
		}
		else if (((*(p + i) >> pos) & 1) == 0)
		{
			num2 ^= *(p + i);
		}
	}
	*x = num1;    //用地址传出去
	*y = num2;

	return 0;
}

int main()
{
	int arr[] = { 2,6,7,8,2,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	Find_dif(arr, sz, &x, &y);
	printf("%d %d\n", x, y);

	return 0;
}