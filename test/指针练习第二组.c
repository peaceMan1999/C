#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

//看图请访问↓网站：
//https://blog.csdn.net/m0_64645696/article/details/122407612

//********************************
//第一题：
 
int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int* ptr1 = (int*)(&a + 1);
    //取出整个a数组的地址+1，指向'4'的后面，强制类型转换（int*），如图1-1；
    int* ptr2 = (int*)((int)a + 1);
    //a没有单独存放，也没有&，所以a表示首元素地址，强制类型转换（int），
    //比如说a的地址是0x12EEFF10(随机)，转换成int类型，就是整形0x12EEFF10，已经不是地址，
    //+1，就变成0x12EEFF11，再强制类型转换成（int*），中间差了1个地址，如图1-2；
    printf("%x,%x", ptr1[-1], *ptr2);
    //ptr1[-1]可以看作*(ptr1-1)，   
    //答案是 4，20000000；

    return 0;
}

//********************************
//第二题：

//int main()
//{
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    //逗号表达式显示的是后面的值，所以inta[3][2]={1,3,5};
//    int* p;
//    p = a[0];
//    //p取的是a第一行元素，因为a是二维数组，a[0]可以看作是一维数组的数组名；
//    printf("%d", p[0]);
//    //解引用p[0]->*(p+0)，就是a[0]首元素，
//    //答案是 1.
//    return 0;
//}

//********************************
//第三题：

//int main()
//{
//    int a[5][5];
//    int(*p)[4];
//    p = a;
//    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//    //低地址-高地址是负数，如图2-1；
//    //答案是 -4，-4；
//    return 0;
//}

//********************************
//第四题：

//int main()
//{
//    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int* ptr1 = (int*)(&aa + 1);
//    //取出整个二维数组的地址+1，跳整个数组，指向'10'的后面，强制类型转换成int*；
//    int* ptr2 = (int*)(*(aa + 1));
//    //aa没有单独存放，所以是首元素地址，就是第一行地址，+1就是第二行，
//    //解引用访问第二行5个元素，再强制类型转换，是'6'的地址；
//    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//    //因为现在是int*类型的指针，所以向前一个int*类型指针，
//    //答案是 5，10；
//    return 0;
//}

//********************************
//第五题：

//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	//char*a[]是一个char*类型的数组，是指针数组；
//	char** pa = a;
//	//char**pa是二级指针
//	pa++;
//	printf("%s\n", *pa);
//	//解引用a[1]
//	//答案是 at；
//	return 0;
//}

//********************************
//第六题：

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	//前置++，cpp指向char**cp[]首行，+1后指向第二行，解引用；
//	//如图5-1；
//	//答案是POINT；
//	printf("%s\n", *-- * ++cpp + 3);
//	//因为++过，所以cpp现指向c+2，(*--(*++cpp)+3),
//	//先++cpp，指向c+1，解引用得到c+1，再*--c+1,找到'ENTER',
//	//最后再+3，此时指针类型是char*，因为要以%s打印，
//	//如图5-2；
//	//答案是 ER；
//	printf("%s\n", *cpp[-2] + 3);
//	//*(cpp[-2])->*(*(cpp-2))，解引用访问c+3，再解引用访问'FIRST',再+3，
//	//如图5-3；
//	//答案是 ST；
//	printf("%s\n", cpp[-1][-1] + 1);
//	//cpp[-1][-1]->*(*(cpp-1)-1)，
//	//如图5-4；
//	//答案是 EW；
//
//	return 0;
//}
