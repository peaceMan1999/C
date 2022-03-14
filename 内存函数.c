#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//memcpy -- 内存拷贝函数

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* p = (char*)dest;

	while (num--)
	{
		*(char*)dest = *(char*)src;
		src = (char*)src + 1;
		dest = (char*)dest + 1;
	}
	return p;
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };

	//memcpy(arr2, arr1, 45);
	my_memcpy(arr2, arr1, 20);

	return 0;
}

//memmove -- 处理内存重叠的情况(建议)

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* p = dest;
//
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else if (dest > src)
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	//memmove(arr1 + 2, arr1, 20);
//	my_memmove(arr1 , arr1+4, 20);
//
//	return 0;
//}

