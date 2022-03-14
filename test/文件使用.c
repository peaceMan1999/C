#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//输出到流
//int main()
//{
//	fputc('u', stdout);
//	fputc('z', stdout);
//	fputc('i', stdout);
//
//	return 0;
//}

//fgetc
//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	//fputs("abcdef\n", pf);
//	//fputs("uzi\n", pf);
//	
//	//读文件
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	//写文件
//	/*int ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret); 
//	ret = fgetc(pf);
//	printf("%c\n", ret);*/
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//读写结构体
//typedef struct s
//{
//	char arr[10];
//	int sz;
//	float f;
//}sn;
//
//int main()
//{
//	sn s = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	//fprintf(pf, "%s %d %f", s.arr, s.sz, s.f);
//
//	////读文件
//	//fscanf(pf, "%s %d %f", s.arr, &(s.sz), &(s.f));
//
//	//printf("%s %d %f\n", s.arr, s.sz, s.f);
//
//	//写文件
//	//fwrite(&s, sizeof(sn), 1, pf);
//
//	//读文件
//	fread(&s, sizeof(sn), 1, pf);
//	
//	printf("%s %d %f\n", s.arr, s.sz, s.f);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//typedef struct s
//{
//	char arr[10];
//	int sz;
//	float f;
//}sn;
//
//int main()
//{
//	sn s = { "hello",5,6.1 };
//	sn tmp = { 0 };
//	char buf[100] = { 0 };
//
//	//sprintf
//	sprintf(buf, "%s %d %2f", s.arr, s.sz, s.f);
//	printf("%s\n", buf);
//
//	//sscanf
//	sscanf(buf, "%s %d %2f", tmp.arr, &tmp.sz, &tmp.f);
//	printf("%s %d %2f\n", tmp.arr, tmp.sz, tmp.f);
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
//
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//调整指针位置
//	fseek(pf, -2, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//告诉指针位置
//	int set = ftell(pf);
//	printf("%d ", set);
//
//	//指针回到原位
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


