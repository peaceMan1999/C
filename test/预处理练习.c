#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//拷贝一份文件

//int main()
//{
//	FILE* pfread = fopen("test.txt","r");
//	if (NULL == pfread)
//	{
//		perror("pfread");
//		return 1;
//	}
//
//	FILE* pfwrite = fopen("test2.txt", "w");
//	if (NULL == pfwrite)
//	{
//		perror("pfwrite");
//		fclose(pfread);
//		pfread = NULL;
//		return 1;
//	}
//
//	//读写文件
//	int ch = 0;
//	while ((ch = fgetc(pfread)) != EOF)
//	{
//		fputc(ch, pfwrite);
//	}
//	if (ferror(pfread))
//		puts("read");
//	else if (feof(pfread))
//		puts("end");
//
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	fclose(pfwrite);
//	pfwrite = NULL;
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int c = 0;
//	//while ((c = fgetc(pf)) != EOF)
//	//{
//	//	putchar(c);
//	//}
//	if (ferror(pf))
//		puts("read");
//	else if (feof(pf))
//		puts("end");
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <windows.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("uziyyds", pf);
//
//	printf("休眠10s\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);
//	printf("再次睡眠\n");
//	Sleep(10000);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//extern int add(int x, int y);
//int main()
//{
//	int a = 3;
//	int b = 9;
//	int ret = add(a, b);
//	printf("%d", ret);
//	
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "a+");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf, "\n%s\n %d\n %s\n %s\n ", __FILE__, __LINE__, __DATE__, __TIME__);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#define add(x) ((x)+(x))
//
//int main()
//{
//
//	printf("%d", 10*add(5));
//
//	return 0;
//}
//#define PRINT(x,TYPE) printf(#x" = "#TYPE"\n",x)
//
//int main()
//{
//
//	int a = 10;
//	PRINT(a,%d);
//
//	float b = 20;
//	PRINT(b,%f);
//
//	int c = 30;
//	PRINT(c,%d);
//
//	return 0;
//}

//#define ARR(X,Y) X##Y
//
//int main()
//{
//	int number100 = 21;
//	printf("%d", ARR(number, 100));
//
//	return 0;
//}
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 5;
//	int b = 8;
//	int m = MAX(a, b);
//	printf("%d", m);
//
//	return 0;
//}

//#define M 100
//
//int main()
//{
//	int a = M;
//#undef M
//
//	printf("%d", M);
//
//	return 0;
//}

//#define PRINT
//
//int main()
//{
//#if !defined (PRINT)
//
//	printf("hello\n");
//#endif
//	//printf("hihi\n");
//	return 0;
//}

//int main()
//{
//#if 1==2
//	puts("1");
//#elif 2==1
//	puts("2");
//#else
//	puts("3");
//#endif
//
//	return 0;
//}


