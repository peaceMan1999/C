#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////дһ���꣬���Խ�һ�������Ķ����Ƶ�����λ��ż��λ����
//
//#define CHANGE(x) (((x)&0xaaaaaaaa)>>1) + (((x)&0x55555555)<<1)
//
//int main()
//{
//	//10
//	int n = 11;
//	//00000000000000000000000000001011
//	//10101010101010101010101010101010 ��ż��λ 0xaaaaaaaa
//	//01010101010101010101010101010101 ������λ 0x55555555
//	int ret = CHANGE(n);
//	printf("%d", ret);
//
//	return 0;
//}

//***********************************************************

//дһ���꣬����ṹ���б��������׵�ַ��ƫ����--offsetof

//ԭ�� -- offsetof
//#include <stddef.h>
//
struct s
{
	char a;
	int b;
	short c;
	int d;
};
//
//int main()
//{
//	
//	printf("%d\n", (int)offsetof(struct s, a));
//	printf("%d\n", (int)offsetof(struct s, b));
//	printf("%d\n", (int)offsetof(struct s, c));
//	printf("%d\n", (int)offsetof(struct s, d));
//
//	return 0;
//}

//#define OFF(type, x) ((int)&(((type*)400)->x))-400
#define OFF(type, x) (int)&(((type*)0)->x)

//�����0��ַ������struct s���ͣ����ҵ���Ա->a/b/c/d
//��Ϊ��0 ���Բ���-��Ҫ-����-0������(type*)400����-400��
//&ȡ��ַ���ټ�ȥ��Ԫ�ص�ַ�����Ƕ�Ӧ��Ա����Ԫ�ص�ַ��ƫ����

int main()
{
		printf("%d\n", OFF(struct s, a));
		printf("%d\n", OFF(struct s, b));
		printf("%d\n", OFF(struct s, c));
		printf("%d\n", OFF(struct s, d));
	
		return 0;
}

