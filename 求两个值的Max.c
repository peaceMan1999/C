#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
//第一种方法：
int main()
{
	int x = 0;				//先设变量
	int y = 0;
	scanf("%d %d", &x, &y); //记得include <string.h>
	if (x > y)				//if判断
	{
		printf("%d\n", x);
	}
	else
	{
		printf("%d\n", y);
	}
	return 0;
}

//第二种方法：
int Max(int x,int y)        //创建函数
{
	if (x > y)
		return x;			//return值写变量，返回Max的值
	else
		return y;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int number = Max(a, b); //用函数的方式解决 用number定义Max值
	printf("%d", number);

	return 0;
}




