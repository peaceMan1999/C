#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


int is_string_rotation(char* str1, char* str2)
{
	assert(str1 && str2);

	int len = strlen(str1);
	strncat(str1, str1, len);
	//׷�Ӻ�������str1="ABCDEFABCDEF"������"CDEAB"�ͷ����ҵ�������һ��һ����ת���ж�
	char* p = strstr(str1, str2);
	//strstr�����ж�str2�Ƿ���str1�����ַ�����

	return (p =! NULL); 
	//p =! NULL �淵��1���ٷ���0��

}

int main()
{

	char str1[20] = "ABCDE";
	char str2[20] = "CDEAB";

	int ret = is_string_rotation(str1, str2);

	//�ж�yes / on;
	if (1 == ret)
	{
		puts("yes��");
	}
	else
	{
		puts("no");
	}


	return 0;
}


