#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//���������и�һ���滰��һ��ٻ�
//A˵:B NO.1,A NO.3;
//B˵:B NO.2,E NO.4;
//C˵:C NO.1,D NO.2;
//D˵:C NO.5,D NO.3;
//E˵:E NO.4,A NO.1;

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;

	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{

						if ((B == 1 || A == 3)
							&& (B == 2 || E == 4)
							&& (C == 1 || D == 2)
							&& (C == 5 || D == 3)
							&& (E == 4 || A == 1) == 1)
						{
							if (A * B * C * D * E == 120)
							{
								printf("A��%d B��%d C��%d D��%d E��%d\n", A, B, C, D, E);
							}
						}//end of if

					}
				}
			}
		}

	}//end of for



	return 0;
}