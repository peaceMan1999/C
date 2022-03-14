#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//atoi函数--字符串转换为整型

//int main()
//{
//	char *p= "0123";
//	int ret = atoi(p);
//	printf("%d", ret);
//
//	return 0;
//}

//my_atoi函数
//1.非数字字符串
//2.空格、空字符串
//3.正负号
//4.超出范围

//enum judgement
//{
//	incorrect,  //0
//	correct		//1
//};
//
//enum judgement judge = incorrect;
//
//int my_atoi(const char* ps)
//{	
//	if (NULL == ps)  //判断空指针
//		return 0;
//
//	if ('\0' == *ps) //判断空字符串
//		return 0;
//
//	while (isspace(*ps))  //判断空格
//	{
//		ps++;
//	}
//
//	int flag = 1;		//判断正负
//	if (*ps == '-')    
//		flag = -1;
//	ps++;
//	int num = 0;        //判断是否数字
//	while (*ps)
//	{
//		if (isdigit(*ps))
//		{
//			num = num * 10 + flag * (*ps - '0');
//			ps++;
//		}
//		else
//			return num;
//
//	}
//	judge = correct;
//	return num;
//}
//
//int main()
//{
//	char* p = "    -1234a";
//	int ret = my_atoi(p);
//	if (judge == correct)
//	{
//		printf("正确显示: %d\n", ret);
//	}
//	else if (judge == incorrect)
//	{
//		printf("错误显示: %d\n", ret);
//	}
//
//	return 0;
//}
//
