#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////写一个宏，可以将一个整数的二进制的奇数位和偶数位交换
//
//#define CHANGE(x) (((x)&0xaaaaaaaa)>>1) + (((x)&0x55555555)<<1)
//
//int main()
//{
//	//10
//	int n = 11;
//	//00000000000000000000000000001011
//	//10101010101010101010101010101010 求偶数位 0xaaaaaaaa
//	//01010101010101010101010101010101 求奇数位 0x55555555
//	int ret = CHANGE(n);
//	printf("%d", ret);
//
//	return 0;
//}

//***********************************************************

//写一个宏，计算结构体中变量距离首地址的偏移量--offsetof

//原型 -- offsetof
//#include <stddef.h>
//
struct s
{
	char a;
	int b;
	short c;
	int d;
};
//
//int main()
//{
//	
//	printf("%d\n", (int)offsetof(struct s, a));
//	printf("%d\n", (int)offsetof(struct s, b));
//	printf("%d\n", (int)offsetof(struct s, c));
//	printf("%d\n", (int)offsetof(struct s, d));
//
//	return 0;
//}

//#define OFF(type, x) ((int)&(((type*)400)->x))-400
#define OFF(type, x) (int)&(((type*)0)->x)

//假设把0地址处看作struct s类型，查找到组员->a/b/c/d
//因为是0 所以不用-，要-就是-0，例如(type*)400最后就-400；
//&取地址后再减去首元素地址，就是对应成员距首元素地址的偏移量

int main()
{
		printf("%d\n", OFF(struct s, a));
		printf("%d\n", OFF(struct s, b));
		printf("%d\n", OFF(struct s, c));
		printf("%d\n", OFF(struct s, d));
	
		return 0;
}

