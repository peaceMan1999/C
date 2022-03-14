#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
	double x = 3.6;
	double y = 1.1;

	if (fabs((x - y) - 2.5) < DBL_EPSILON)
		printf("yes\n");
	else
		printf("err\n");

	
	/*printf("%.50f\n", x);
	printf("%.50f\n", y);
	printf("%.50f\n", x - y);*/

	return 0;
}


