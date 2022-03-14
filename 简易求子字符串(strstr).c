#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>


int is_string_rotation(char* str1, char* str2)
{
	assert(str1 && str2);

	int len = strlen(str1);
	strncat(str1, str1, len);
	//追加函数，让str1="ABCDEFABCDEF"，这样"CDEAB"就方便找到，不用一个一个旋转来判断
	char* p = strstr(str1, str2);
	//strstr函数判断str2是否是str1的子字符串；

	return (p =! NULL); 
	//p =! NULL 真返回1，假返回0；

}

int main()
{

	char str1[20] = "ABCDE";
	char str2[20] = "CDEAB";

	int ret = is_string_rotation(str1, str2);

	//判断yes / on;
	if (1 == ret)
	{
		puts("yes！");
	}
	else
	{
		puts("no");
	}


	return 0;
}


