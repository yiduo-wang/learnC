#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct stu
{
	int num;
	int score;
	struct stu *next;
};
struct stu *create(int n)       //创建链表 
{
	struct stu *head = NULL, *tail, *p;
	int i;
	for (i = 1; i <= n; i++)
	{
		p = malloc(sizeof(struct stu));
		scanf("%d%d", &p->num, &p->score);
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	tail->next = NULL;
	return head;
}
struct stu *heBin(struct stu *h1, struct stu *h2)    //合并链表 
{
	struct stu *p = h1;
	while (p->next)
		p = p->next;
	p->next = h2;
	return h1;
}
struct stu *sort(struct stu *head)            //链表排序 
{
	struct stu *end, *p;
	int t;
	end = head;
	while (end)
		end = end->next;
	while (head->next != end)
	{
		p = head;
		while (p->next != end)
		{
			if (p->num > p->next->num)
			{
				t = p->num;
				p->num = p->next->num;
				p->next->num = t;
				t = p->score;
				p->score = p->next->score;
				p->next->score = t;
			}
			p = p->next;
		}
		end = p;
	}
	return head;
}
void print(struct stu *head)        //输出链表 
{
	struct stu *p;
	while (head)
	{
		p = head;
		head = head->next;
		printf("%d %d\n", p->num, p->score);
		free(p);
	}
}
int main()
{
	struct stu *h1, *h2, *head;
	int n, m;
	scanf("%d%d", &n, &m);
	h1 = create(n);
	h2 = create(m);
	head = heBin(h1, h2);
	head = sort(head);
	print(head);
	system("pause");
}
