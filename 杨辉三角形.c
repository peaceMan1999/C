#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1
//1 5 10 10 5 1

#define N 100 
//��Ϊ��ά����������ǳ���ֵ�����Զ���һ������N

int main()
{
	int n = 0;
	int arr[N][N] = { 0 };
	printf("��������:");
	scanf("%d", &n);
	int i = 0;
	int j = 0;


	for (i = 0; i < n; i++)
	{

		for (j = 0; j <= i; j++) //�Ȱ������ʼ��
		{
			arr[i][j] = 1;
		}

	}

	for (i = 2; i < n; i++) //�����м���
	{

		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}

	}


	for (i = 0; i < n; i++)  //��ӡ����
	{
		//��ӡÿһ�еĿո�
		for (j = n - i - 1; j > 0; j--)
		{
			printf(" ");
		}
		//��ӡÿһ�е�����
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}