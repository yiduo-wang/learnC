#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//利用fgets和fputs来进行文本文件的读写
int main()
{
	//标准输入流  --->  所有输出流(相当于写文件)
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fputs("zhangsan  20  95.5\n", pf);
	fputs("lisi  20  53.5\n", fp);
	fputs("wangmazi  21  76.5\n", pf);
	fclose(pf);
	pf = NULL;

	//所有输入流  --->  标准输出流(相当于读文件)
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char buf[100] = { 0 };
	fgets(buf, 50, pf);
	fputs(buf, stdout);
	fgets(buf, 50, pf);
	fputs(buf, stdout);	
	fgets(buf, 50, pf);
	fputs(buf, stdout);
	fclose(pf);
	pf = NULL;
	system("pause");
}


//利用fscanf和fprintf来进行文本文件的读写
int main()
{
	//标准输入流  --->  所有输出流(相当于写文件)
	FILE* pf = fopen("test1.txt", "w");
	char name[30] = { 0 };
	int age = 0;
	float score = 0.0;
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fscanf(stdin, "%s  %d  %f", name, &age, &score);
	fprintf(pf, "%s  %d  %2.2f\nfile:%s,date:%s,time:%s\n", name, age, score,__FILE__,__DATE__,__TIME__);
	fscanf(stdin, "%s  %d  %f", name, &age, &score);
	fprintf(pf, "%s  %d  %2.2f\n", name, age, score);
	fscanf(stdin, "%s  %d  %f", name, &age, &score);
	fprintf(pf, "%s  %d  %2.2f\n", name, age, score);
	fclose(pf);
	pf = NULL;

	//所有输入流  --->  标准输出流(相当于读文件)
	char name[30] = { 0 };
	int age = 0;
	float score = 0.0;
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fscanf(pf, "%s  %d  %f", name, &age, &score);
	fprintf(stdout, "%s  %d  %2.2f\nfile = %s,date = %s,time = %s\n", name, age, score,__FILE__,__DATE__,__TIME__);	
	fscanf(pf, "%s  %d  %f", name, &age, &score);
	fprintf(stdout, "%s  %d  %2.2f\n", name, age, score);
	fscanf(pf, "%s  %d  %f", name, &age, &score);
	fprintf(stdout, "%s  %d  %2.2f\n", name, age, score);
	fclose(pf);
	pf = NULL;
	system("pause");
}


//利用sscanf和sprintf来进行格式化数据与字符串的转化
typedef struct S
{
	char name[30];
	int age;
	float score;
}S;

int main()
{
	//格式化数据  --->  字符串(相当于从一个格式化数据中写一个字符串)
	S stu = { "zhangsan",20,95.5 };
	char buf[100] = { 0 };
	sprintf(buf,"%s %d %2.2f", stu.name,stu.age,stu.score);
	printf("%s\n", buf);

	//字符串  --->  格式化数据(相当于从一个字符串中读取一个格式化数据)
	S stu = { 0 };
	char buf[30] = "zhangsan 20 95.5";
	sscanf(buf, "%s %d %f", stu.name, &stu.age, &stu.score);
	printf("%s %d %2.2f\n", stu.name, stu.age, stu.score);
	system("pause");
}

//利用fread和fwrite来进行二进制文件的读写

typedef struct S
{
	char name[30];
	int age;
	float score;
}S;

int main()
{
	//fwrite(向文件中写二进制代码)
	FILE* pf = fopen("test2.txt","w");
	S stu = { "zhangsan",20,95.5 };
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fwrite(&stu, sizeof(stu), 99, pf);
	fclose(pf);
	pf = NULL;

	//fread(从二进制文件中读取代码)
	FILE* pf = fopen("test2.txt", "r");
	S stu = { 0 };
	if (pf == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fread(&stu, sizeof(stu), 1, pf);
	printf("%s %d %2.2f\n", stu.name, stu.age, stu.score);
	fclose(pf);
	pf = NULL;
	system("pause");
}