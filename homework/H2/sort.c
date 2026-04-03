#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b);

struct  CONTACT
{
	char name[25];
	char phone[15];
};

int main()
{
	struct CONTACT contact[105];
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s %s", contact[i].name, contact[i].phone);
	}//到这里数据都存好了

	int n = num;//用于储存去重之后的个数
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(contact[i].phone, contact[j].phone) == 0 && strcmp(contact[i].name, contact[j].name) == 0)
			{
				for (int k = j; k < n - 1; k++)
				{
					contact[k] = contact[k + 1];
				}
				n--;
				j--;//这个位置被新数据替换了，下次继续检查这个位置
			}
		}
	}//到这里应该已经去重结束了，接下来应该开始标记重复人名了

	for (int i = 0; i < n; i++)//再从头开始查一遍人名，这里用的n就是新的n了
	{
		int cnt = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(contact[i].name, contact[j].name) == 0)//如果名字重了
			{
				cnt++;
				sprintf(contact[j].name, "%s_%d", contact[j].name, cnt);
			}
		}
	}//到这里这一堆结构体都已经被改变了

	qsort(contact, n, sizeof(struct CONTACT), cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%s %s\n", contact[i].name, contact[i].phone);
	}
	return 0;
}

int cmp(const void* a, const void* b)
{
	struct CONTACT* contactA = (struct CONTACT*)a;
	struct CONTACT* contactB = (struct CONTACT*)b;

	return strcmp(contactA->name,contactB->name);
}
