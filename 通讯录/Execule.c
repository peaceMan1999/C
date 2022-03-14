#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//动态内存初始化
void Init_con(contact* pc)
{
	pc->data = (Infor*)malloc(MAX_STRUCT * sizeof(Infor));

	//内存设置
	pc->sz = 0;
	pc->capacity = MAX_STRUCT;

	if (pc->data == NULL)
	{
		perror("calloc");
		return;
	}

}

//打印全部信息的函数（与单个打印 Little_print 不同）
void Print_con(contact* pc)
{
	int i = 0;
	//添加列表
	printf("|%-3s\t|%-4s\t|%-7s\t|%-3s\t|%-13s\t|%-30s\n", "序号", "姓名", "性别", "年龄", "电话", "地址");

	for (i = 0; i < pc->sz; i++)
	{
		printf("|%-3d\t|%-4s\t|%-7s\t|%-3d\t|%-13s\t|%-30s\n", 
									pc->data[i].Sort,
									pc->data[i].Name,
									pc->data[i].Sex,
									pc->data[i].Age,
									pc->data[i].Tele,
									pc->data[i].Addr  );

	}
}

//增加信息
void ADD_con(contact* pc)
{

	if (pc->sz == pc->capacity)
	{
		Infor* ptr = (Infor*)realloc(pc->data, (pc->capacity + MAX_SZ) * sizeof(Infor));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += MAX_SZ;
			printf("扩容成功\n");
		}
		else
		{
			perror("ADD_con");
			printf("扩容失败\n");
			return;
		}

	}

	//添加信息
	printf("姓名:>");
	scanf("%s", pc->data[pc->sz].Name); //因为name是数组首元素地址，所以不用&
	printf("性别:>");
	scanf("%s", pc->data[pc->sz].Sex); 
	printf("年龄:>");
	scanf("%d", &pc->data[pc->sz].Age); //Age是int类型，要&
	printf("电话:>");
	scanf("%s", pc->data[pc->sz].Tele);
	printf("地址:>");
	scanf("%s", pc->data[pc->sz].Addr);
	pc->data[pc->sz].Sort = pc->sz+1;

	pc->sz++;  //容量+1
	printf("添加成功！\n");	
	
}

//方便打印单个 i 的函数
static void Little_print(contact* pc, int i)
{
	printf("|%-3s\t|%-4s\t|%-7s\t|%-3s\t|%-13s\t|%-30s\n", "序号", "姓名", "性别", "年龄", "电话", "地址");

	printf("|%-3d\t|%-4s\t|%-7s\t|%-3d\t|%-13s\t|%-30s\n",
		pc->data[i].Sort,
		pc->data[i].Name,
		pc->data[i].Sex,
		pc->data[i].Age,
		pc->data[i].Tele,
		pc->data[i].Addr);

}

//查找名字
static int Find_name(contact* pc, char name[])
{
	int i = 0;
	int count = 0;  //根据count是否发生变化来查找信息
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].Name) == 0)
		{
			Little_print(pc, i); //打印单个的函数
			count= 1;
		}
	}
	if (0 == count)
	{
		printf("没有此人信息\n");
		return 0;
	}
	return 1;
}

//查找信息
void Search_con(contact* pc)
{

	char name[MAX_NAME] = { 0 };
	printf("输入要查找的名字:>\n");
	scanf("%s", name);
	//查找名字
	Find_name(pc, name);

}

//动态p内存 -- 删除模块
static int* P_MAX(int* p, int sz)
{
	int count = 1;  //基数

	if (*(p+sz-1) != '\0')
	{
		int*ptr = (int*)realloc(p, (MAX_STRUCT + count * MAX_SZ) * sizeof(int));
		if (ptr != NULL)
		{
			p = ptr;
			printf("扩容成功\n");
			count++;
		}
		else
		{
			perror("int* P_MAX()");
			printf("扩容失败\n");
			return;
		}
	}

}

//删除模块专用函数 -- 判断后储存
static int* Judge_num(contact*pc, char *name) 
{
	int p[MAX_STRUCT] = { 0 };
	int i = 0;
	int num = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].Name) == 0)
		{
			//相同就储存在数组中
			p[num] = pc->data[i].Sort;
			//判断有无满载
			int sz = sizeof(p) / sizeof(p[0]);
			P_MAX(p, sz, pc);
		}
	}
	return p;
}

//删除模块专用函数 -- 判断judge储存后的数值与选择的序号是否相等
static int compare_num(int* p, int num)
{
	while (*p)
	{
		if (num == *p)
			return 1;
		p++;
	}
	return 0;

}

//删除信息
void Delete_con(contact* pc)
{
	//判断有没有信息
	if (pc->sz == 0)
	{
		printf("没有可删除的信息了~\n");
		return;
	}

	//输入删除者的名字
	char name[MAX_NAME] = { 0 };
	printf("输入删除的名字:>");
	scanf("%s", name);

	//找出名字
	int ret = Find_name(pc, name);
	if (0 == ret)
		return;

	//选择删除编号
	int num = 0;
	printf("选择要删除的编号:>");
	scanf("%d", &num);
	int* p = Judge_num(pc, name); //用Judge_num储存判断好的数以数组指针的形式返回
	int tmp = compare_num(p, num); 
	if (0 == tmp)
	{
		printf("输入错误\n");
		return;
	}

	if (num<0 || num>pc->sz)
	{
		printf("输入错误\n");
		return;
	}

	//判断选择编号
	if (pc->data[num - 1].Sort != num)
	{
		printf("输入编号不符~\n");
		return;
	}

	//调整序列
	int i = 0;
	for (i = num - 1; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
		pc->data[i].Sort = pc->data[i].Sort - 1;  //为了让序列衔接上，要减去1
	}

	pc->sz--;
	printf("删除成功！\n");


}

//修改信息
void Recise_con(contact* pc)
{
	if (pc->sz == 0)
	{
		printf("没有可修改的信息了~\n");
		return;
	}

	//选择要修改的序号
	int num = 0;
	printf("输入修改的序号:>");
	scanf("%d", &num);

	//显示一下
	Little_print(pc, num-1);
	
	//修改元素
	char element[5] = { 0 };
	printf("输入修改的元素:>");
	scanf("%s", element);

	char value[MAX_ADDR] = { 0 };  //用最大的住址信息来存放，就不用每一个变量都创建了
	int age = 0;

	if (strcmp(element, "姓名") == 0)
	{
		printf("输入修改的值:>\n");
		scanf("%s", pc->data[num - 1].Name);
	}
	else if (strcmp(element, "性别") == 0)
	{
		printf("输入修改的值:>\n");
		scanf("%s", pc->data[num - 1].Sex);
	}
	else if (strcmp(element, "年龄") == 0)
	{
		printf("输入修改的值:>\n");
		scanf("%d", &pc->data[num - 1].Age);
	}
	else if (strcmp(element, "电话") == 0)
	{
		printf("输入修改的值:>\n");
		scanf("%s", pc->data[num - 1].Tele);
	}
	else if (strcmp(element, "地址") == 0)
	{
		printf("输入修改的值:>\n");
		scanf("%s", pc->data[num - 1].Addr);
	}
	else
		printf("错误\n");
	printf("修改成功\n");
	//打印一下
	Little_print(pc, num - 1);
}

//排序信息
void Sort_con(contact* pc)
{
	int i = 0;
	int j = 0;

	//冒泡排序法
	for (i = 0; i < pc->sz; i++)
	{
		int count = 0;

		for (j = 0; j < pc->sz - i - 1; j++)
		{
			if (strcmp(pc->data[j].Name,pc->data[j+1].Name) > 0)
			{
				Infor tmp = pc->data[j];    //这里的tmp用Infor类型，因为我们要存储的值的Infor结构体
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				pc->data[j + 1].Sort = pc->data[j + 1].Sort + 1;  //序号改一下
				pc->data[j].Sort = pc->data[j].Sort - 1;

				count = 1;  //如果有交换动作，就改变count
			}

		}
		if (0 == count)  //如果count为0，说明没有可交换的值，跳出
			break;
		
	}
	printf("顺序已排好！\n");
	Print_con(pc);
}

//清空所有的个人信息
void Empty_con(contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz+1; i++)
	{
		pc->sz--;   //减少下标相当于删除，只是隐藏起来了
		if (0 == pc->sz--)
		{
			break;
		}
	}
}

//释放内存
void Destroyed(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz;
	pc->capacity;
	printf("释放成功\n");
}
