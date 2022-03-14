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
	printf("*****1.加法  2.减法*****\n");
	printf("*****3.乘法  4.除法*****\n");
	printf("*****    0.退出   ******\n");
	printf("************************\n");
}

void Calc(int (*pf)(int, int)) //用函数指针接收
{
	int x = 0;
	int y = 0;
	printf("输入两个数:");
	scanf("%d %d", &x, &y);
	int ret = pf(x, y);
	printf("%d\n", ret);

}
//方法二函数：
//void Calc(int i, int (*calc[5])(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("输入两个数:");
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
	//方法二
	// 把函数地址存储在函数指针数组中；
	// 数组大小为5，前面初始化一个0，这样就能与input对上；
	//int (*calc[5])(int, int) = { 0,Add,Sub,Mul,Div };

	do
	{
		menu();
		printf("选择算法:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);          //方法一：把函数地址作为参数
			//Calc(input,calc);   //方法二：把input和cale函数指针数组作为参数
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
			puts("退出计算机：");
			break;
		default:
			puts("请重新输入：");
			break;
		}


	} while (input);



	return 0;
}

