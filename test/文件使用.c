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
//	//д�ļ�
//
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//�������
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
//	//д�ļ�
//	//fputs("abcdef\n", pf);
//	//fputs("uzi\n", pf);
//	
//	//���ļ�
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	//д�ļ�
//	/*int ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret); 
//	ret = fgetc(pf);
//	printf("%c\n", ret);*/
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//��д�ṹ��
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
//	//д�ļ�
//	//fprintf(pf, "%s %d %f", s.arr, s.sz, s.f);
//
//	////���ļ�
//	//fscanf(pf, "%s %d %f", s.arr, &(s.sz), &(s.f));
//
//	//printf("%s %d %f\n", s.arr, s.sz, s.f);
//
//	//д�ļ�
//	//fwrite(&s, sizeof(sn), 1, pf);
//
//	//���ļ�
//	fread(&s, sizeof(sn), 1, pf);
//	
//	printf("%s %d %f\n", s.arr, s.sz, s.f);
//
//	//�ر��ļ�
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
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//����ָ��λ��
//	fseek(pf, -2, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//����ָ��λ��
//	int set = ftell(pf);
//	printf("%d ", set);
//
//	//ָ��ص�ԭλ
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


