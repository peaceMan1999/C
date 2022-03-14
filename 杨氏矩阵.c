#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

int find_number(int arr[3][3], int r, int c, int k)
{
	int x = 0;
	int y = c - 1;    //����Ҫ���x���ʾ���ұߵ���

	while (x < r && y >= 0)
	{
		if (arr[x][y] < k)  //���ұߵ���<k��˵�����ڴ���
		{
			x++;
		}
		else if (arr[x][y] > k)  //���ұߵ���>k��˵�����ڴ���
		{
			y--;
		}
		else if (k == arr[x][y])
		{
			printf("%d %d\n", x, y);
			return 1;  //�ҵ�����1�����Ҵ�ӡ����
		}
		else
		{
			return 0;  //û�ҵ�����0��
		}
	}
}

int main()
{

	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	printf("Ҫ�ҵ�����:");
	scanf("%d", &k);

	int ret = find_number(arr, 3, 3, k);
	
	if (1 == ret)
	{
		printf("�ҵ�����\n");
	}
	else
	{
		printf("û�ҵ�~\n");
	}

	return 0;
}


