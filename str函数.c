#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcpy函数

char* my_copy(char* arr2, const char* arr1)
{
	assert(arr1 && arr2);
	char* start = arr2;
	
	while (*arr2++ = *arr1++)
	{
		;
	}

	return start;
}

int main()
{
 
	char arr1[] = "hello";
	char arr2[20] = "##################";

	printf("%s\n", my_copy(arr2, arr1));
	//strcpy(arr2, arr1);
	//puts(arr2);

	return 0;
}

//strncpy函数(n)

//char* my_strncpy(char* str2, const char* str1, int num)
//{
//	assert(str1 && str2);
//	char* start = str2;
//
//	while (num && (*str2++ = *str1++) != '\0')
//	{
//		num--;
//	}
//	if (num)
//	{
//		while (--num)
//			*str2++ = '\0';
//	}
//
//	return start;
//}
//
//int main()
//{
//
//	char arr1[] = "hello";
//	char arr2[20] = "abcdefghi";
//
//	my_strncpy(arr2, arr1, 7);
//	puts(arr2);
//
//	return 0;
//}

//strcat追加函数

//char* my_strcat(char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	char* start = arr1;
//
//	while (*arr1 != '\0')
//	{
//		arr1++;
//	}
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return start;
//}
//
//int main()
//{
//
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//
//	//strcat(arr1, arr2);
//	//puts(arr1);
//
//	return 0;
//}

//strncat 追加函数(n)

//char* my_strncat(char* str1, const char* str2, int num)
//{
//	assert(str1 && str2);
//	char* p = str1;
//	
//	if (0 == num)
//		return p;
//	while (*str1++)
//		;
//	str1--;
//
//	while (*str2 && num--)
//	{
//		if (0 == (*str1++ = *str2++))
//			return p;
//	}
//	*str1 = '\0';
//
//	return p;
//}
//
//int main()
//{
//
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	
//	my_strncat(arr1, arr2, 3);
//	puts(arr1);
//
//	return 0;
//}

//strcmp 字符串比较函数

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1, str2);
//	while (*++str1 == *++str2)
//		;
//	if (*str1 && *str2 == '\0')
//		return 0;
//	else
//		return (*str1 - *str2);
//}
//
//int main()
//{
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcj";
//	//int ret = strcmp(arr1, arr2);
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		puts("arr1大");
//	}
//	else if (ret < 0)
//	{
//		puts("arr2大");
//	}
//	else
//		puts("一样");
//
//	return 0;
//}

//strcmp 字符串比较函数

//int my_strncmp(const char* str1, const char* str2, int num)
//{
//	assert(str1 && str2);
//	
//	while (num-- && *++str1 == *++str2)
//		;
//	if (num)
//	{
//		return (*str1 - *str2);
//	}
//	return 0;
//}
//
//int main()
//{
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcj";
//	int ret = my_strncmp(arr1, arr2, 4);
//
//	if (ret > 0)
//	{
//		puts("arr1大");
//	}
//	else if (ret < 0)
//	{
//		puts("arr2大");
//	}
//	else
//		puts("一样");
//
//	return 0;
//}

//strstr函数 -- 查子字符串

// 1.
//const char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1, str2);
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//
//	while (*str1 && *str2)
//	{
//		while (*str1 != *str2)
//			str1++;
//		s1 = str1;
//		s2 = str2;
//		while (*str1++ == *str2++)
//		{
//			if ('\0' == * str2)
//				return (char*)s1;
//		}
//		str1 = s1+1;
//		str2 = s2;
//	}
//	return NULL;
//}

//2.
//const char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1, str2);
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	char* p = str1;
//
//	if (*str2 == '\0')
//	{
//		return (char*)p;
//	}
//
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if ('\0' == *s2)
//		{
//			return (char*)p;
//		}
//		p++;
//	}
//	return NULL;
//}
//
//int main()
//{
//
//	char arr1[] = "abbbccd";
//	char arr2[] = "bbc";
//
//	//char* p = strstr(arr1, arr2);
//	char* p = my_strstr(arr1, arr2);
//
//	if (p != NULL)
//		puts("存在");
//	else
//		puts("no");
//
//	return 0;
//}

//strtok函数 -- 分割字符串

//int main()
//{
//	char arr[] = "12345@qq.com";
//	char *p = "@.";
//	char tmp[30] = { 0 };
//	strcpy(tmp, arr);
//
//	char* ret = NULL;
//
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		puts(ret);
//	}
//
//	//char* ret = strtok(tmp, p);
//	//puts(ret);
//
//	//ret = strtok(NULL, p);
//	//puts(ret);
//
//	//ret = strtok(NULL, p);
//	//puts(ret);
//
//	return 0;
//}

//strerror函数 -- 告知错误信息函数
//#include <errno.h>
//
//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//}

//perror函数 -- 与strerror相同，不过更优化

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//}



