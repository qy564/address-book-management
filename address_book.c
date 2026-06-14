#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct
{
	char name[20];
	char tel[15];
} contact;

contact book[MAX];
int count = 0;

void menu()
{
	printf("\n通讯录\n");
	printf("1.添加联系人\n");
	printf("2.查看所有联系人\n");
	printf("3.拿名字找人\n");
	printf("4.删除联系人\n");
	printf("0.go out system\n");
	printf("输入相应编码：");
}

void add()
{
	if(count >= MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", book[count].name);
	printf("输入电话号码：");
	scanf("%s", book[count].tel);
	count++;
	printf("成功输入！\n");
}

void show()
{
	int i;
	if(count == 0)
	{
		printf("查无此人\n");
		return;
	}
	printf("\n序号\t姓名\t\t电话\n");
	for(i = 0; i < count; i++)
	{
		printf("%d\t%s\t\t%s\n", i + 1, book[i].name, book[i].tel);
	}
}

void search()
{
	char name[20];
	int flag = 0;
	int i;
	printf("姓名查找：");
	scanf("%s", name);
	for(i = 0; i < count; i++)
	{
		if(strcmp(book[i].name, name) == 0)
		{
			printf("查找：%s %s\n", book[i].name, book[i].tel);
			flag = 1;
			break;
		}
	}
	if(!flag)
		printf("查无此人！！！\n");
}

void del()
{
	char name[20];
	int i, j, flag = 0;
	printf("选择：");
	scanf("%s", name);
	for(i = 0; i < count; i++)
	{
		if(strcmp(book[i].name, name) == 0)
		{
			for(j = i; j < count - 1; j++)
			{
				book[j] = book[j + 1];
			}
			count--;
			printf("已删除\n");
			flag = 1;
			break;
		}
	}
	if(!flag)
		printf("未找到\n");
}

int main()
{
	int op;
	while(1)
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
			case 1: add(); break;
			case 2: show(); break;
			case 3: search(); break;
			case 4: del(); break;
			case 0: printf("已退出\n"); return 0;
			default: printf("无法退出\n");
		}
	}
	return 0;
}
