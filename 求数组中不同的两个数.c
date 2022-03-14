#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//һ��������ֻ����������ͬ��������дһ�������ҳ���
// 1 2 3 4 5 6 1 2 3 4

void Find_dif(const int* p, int sz, int* x, int* y)
{
	int i = 0;
	int n = *p;

	for (i = 1; i < sz; i++)     //ȫ�������
	{							 //����������1 2 3 4 5 6 1 2 3 4
		n = n ^ *(p + i);        //��ôn = 5^6 = 3;
	}							 //3�Ķ�������0011����Ϊ���1��ָ������λ��ͬ
								 //���԰�1����
	int pos = 0;
	for (i = 0; i < 32; i++)     //����ǵڼ���λ��ͬ
	{
		if (((n >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)     //���ಢ����ǣ�����������ǲ�ͬ����
	{
		if (((*(p + i) >> pos) & 1) == 1)
		{
			num1 ^= *(p + i);
		}
		else if (((*(p + i) >> pos) & 1) == 0)
		{
			num2 ^= *(p + i);
		}
	}
	*x = num1;    //�õ�ַ����ȥ
	*y = num2;

	return 0;
}

int main()
{
	int arr[] = { 2,6,7,8,2,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	Find_dif(arr, sz, &x, &y);
	printf("%d %d\n", x, y);

	return 0;
}