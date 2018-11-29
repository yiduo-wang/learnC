#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//////////////////////////////////////////
//现在需要给学生发奖学金
//奖学金只给学习好的同学发，只发前n名
/////////////////////////////////////////

//自定义类型，用这个类型来抽象表示学生信息
typedef struct Student
{
	char name[1024];
	//绩点一般是小数，但是通常只保留一位小数，就可以通过乘以10的方式来表示
	int score;
	struct Student* s;
}Student;
//student2是全局变量，相当于struct Student student2;
//*p,定义了一个结构体指针，也是全局变量

//typedef struct School
//{
//	Student student[1000];
//}School;

	typedef struct School
	{
		Student students[1000];
		int size;
	}School;



int main()
{
	School school;
	int index = school.size - 1;
	Student* p = school.students;
	p[index].name;
	//printf("%d\n", sizeof(Student));
	//struct Student student1 = {"张三",50};
	//student1.name;
	//student1.score;
	//printf("%s,%d\n", student1.name,student1.score);
	//student1.score = 100;
	//printf("%s,%d\n", student1.name, student1.score);
	//strcpy(student1.name, "李四");
	//printf("%s,%d\n", student1.name, student1.score);

	//Student* p = &student1;
	//printf("%s,%d\n", p->name,p->score );
	//printf("%s,%d\n", (*p).name, p->score);

	 system("pause");
}