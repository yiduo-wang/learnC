#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define PERSON_INTO_MAX_SIZE 200

typedef struct PersonInfo//联系人的信息
{
	char name[100];
	char sex[5];
	char age[5];
	char phone[40];
	char address[1024];
}PersonInfo;

typedef struct AddressBook//通讯录
{
	PersonInfo infos[PERSON_INTO_MAX_SIZE];
	int size;//[0,size)范围是有效的空间
}AddressBook;

AddressBook g_address_book;

void Init(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->size = 0;
	//size控制了结构体数组中的有效元素的区间范围,只要设为0,
	//无论数组中存在了什么都是没有意义的,所以就不需要在给数组进行初始化
}

void AddPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("插入一个联系人\n");
	if (addr_book->size >= PERSON_INTO_MAX_SIZE)
	{
		printf("当前通讯录已满,插入失败");
	}
	//每次把这个新的联系人放到有效数组的最后一个元素
	PersonInfo* p = &addr_book->infos[addr_book->size];
	printf("请输入新增联系人的姓名:\n");
	scanf("%s", p->name);
	//此处不能取一个结构体的变量,只能取结构体指针,
	//不能传值只能传址
	printf("请输入新增联系人的性别\n");
	scanf("%s", p->sex);
	printf("请输入新增联系人的年龄\n");
	scanf("%s", p->age);
	printf("请输入新增联系人的电话\n");
	scanf("%s", p->phone);
	printf("请输入新增联系人的地址\n");
	scanf("%s", p->address);
	//新增完成后,需要更新size
	++addr_book->size;
	printf("插入联系人成功\n");
}

void DelPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("删除联系人\n");
	printf("请输入要删除联系人的序号\n");
	int id = 1;
	scanf("%d", &id);
	if (id < 1 || id > addr_book->size)
	{
		printf("您输入的有误!删除失败\n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id-1];
	printf("您要删除的联系人为[%d] %s\t%s\t%s\t%s\t%s\n",
		id, p->name, p->sex, p->age, p->phone, p->address);
	printf("确认请按\"Y\"\n");
	char cmd[5] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") != 0)
	{
		printf("删除操作已取消\n");
		return;
	}
	PersonInfo* from = &addr_book->infos[addr_book->size];
	PersonInfo* to = p;
	*to = *from;
	--addr_book->size;
	printf("删除成功\n");
}

void FindPersonInfo(AddressBook* addr_book)
{

}

void ModfiyPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("修改联系人信息\n");
	printf("请输入要修改的联系人序号\n");
	int id = 1;
	scanf("%d", &id);
	if (id<1 || id>addr_book->size)
	{
		printf("您输入的序号错误\n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id-1];
	char input[1024] = { 0 };
	printf("请输入您要修改的姓名\n");
	scanf("%s", &input);
	if (strcmp(input, "#") != 0)
		strcpy(p->name, input);
	printf("请输入您要修改的年龄\n");
	scanf("%s", &input);
	if (strcmp(input, "#") != 0)
		strcpy(p->age, input);
	printf("请输入您要修改的性别\n");
	scanf("%s", &input);
	if (strcmp(input, "#") != 0)
		strcpy(p->sex, input);
	printf("请输入您要修改的电话\n");
	scanf("%s", &input);
	if (strcmp(input, "#") != 0)
		strcpy(p->phone, input);
	printf("请输入您要修改的住址\n");
	scanf("%s", &input);
	if (strcmp(input, "#") != 0)
		strcpy(p->address, input);
	printf("修改成功\n");
}

void PrintAllPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("显示所有联系人\n");
	for (int i = 1; i <= addr_book->size; ++i)
	{
		PersonInfo* p = &addr_book->infos[i-1];
		printf("[%d] %s\t%s\t%s\t%s\t%s\n", i,p->name,
			p->sex,p->age,p->phone,p->address); 
	}
	printf("共显示了%d条数据\n",addr_book->size);
}

void ClearAllPersonInfo(AddressBook* addr_book)
{

}

void SortAllPersonInfo(AddressBook* addr_book)
{

}

void SaveAllPersonInfo(AddressBook* addr_book)
{

}

void LoadAllPersonInfo(AddressBook* addr_book)
{

}

int Menu()
{
	printf("================\n");
	printf("1.新增\n");
	printf("2.删除\n");
	printf("3.修改\n");
	printf("4.查找\n");
	printf("5.显示所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("7.以姓名排序所有联系人\n");
	printf("8.保存联系人到文件\n");
	printf("9.加载联系人\n");
	printf("0.退出\n");
	printf("================\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main()
{
	//1.对通讯录进行初始化
	Init(&g_address_book);//传址不能传值
	typedef void(*pfounc_t)(AddressBook*);
	pfounc_t table[]=
	{
		AddPersonInfo,DelPersonInfo,ModfiyPersonInfo,
		FindPersonInfo,PrintAllPersonInfo,
		ClearAllPersonInfo,SortAllPersonInfo,
		SaveAllPersonInfo,LoadAllPersonInfo
	};
	while (1)
	{
		int choice = Menu();
		if (choice < 0 || choice>(int)(sizeof(table)/sizeof(table[0])))
		{
			printf("您输入的有错误,请重新输入:\n");
			continue;
		}
		if (choice == 0)
		{
			printf("goodbye\n");
			break;
		}
		table[choice - 1](&g_address_book);
	}
	system("pause");
}