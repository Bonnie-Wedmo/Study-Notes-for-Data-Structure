#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BOOK
{
	char name[55];
	char author[25];
	char press[35];
	char time[15];
};
int cmp(const void* a, const void* b);
void sequence(struct BOOK* books, int cnt);

int main()
{
	FILE* fin = fopen("books.txt", "r");

	struct BOOK books[505];
	int cnt = 0;
	while (fscanf(fin, "%s %s %s %s",
		books[cnt].name,
		books[cnt].author,
		books[cnt].press,
		books[cnt].time) == 4)
	{
		cnt++;
	}//读入到结构体里

	while (1)
	{
		int ways;
		scanf("%d", &ways);
		if (ways == 1)
		{
			scanf("%s %s %s %s",
				books[cnt].name,
				books[cnt].author,
				books[cnt].press,
				books[cnt].time);
			cnt++;
			sequence(books, cnt);
		}
		else if (ways == 2)
		{
			char want[55];
			scanf("%s", want);
			for (int i = 0; i < cnt; i++)
			{
				if (strstr(books[i].name, want) != NULL)
				{
					printf("%-50s%-20s%-30s%-10s\n",
						books[i].name,
						books[i].author,
						books[i].press,
						books[i].time);
				}
			}
		}
		else if (ways == 3)
		{
			char want[55];
			scanf("%s", want);
			for (int i = 0; i < cnt; i++)
			{
				if (strstr(books[i].name, want) != NULL)
				{
					for (int j = i; j < cnt - 1; j++)
					{
						books[j] = books[j + 1];
					}
					i--;
					cnt--;
				}
			}
			sequence(books, cnt);
		}
		else break;
	}

	fclose(fin);

	return 0;
}

int cmp(const void* a, const void* b)
{
	struct BOOK* contactA = (struct BOOK*)a;
	struct BOOK* contactB = (struct BOOK*)b;

	return strcmp(contactA->name, contactB->name);
}

void sequence(struct BOOK* books, int cnt)
{
	FILE* fout = fopen("ordered.txt", "w");
	qsort(books, cnt, sizeof(struct BOOK), cmp);
	for (int i = 0; i < cnt; i++)
	{
		fprintf(fout, "%-50s%-20s%-30s%-10s\n",
			books[i].name,
			books[i].author,
			books[i].press,
			books[i].time);
	}
	fclose(fout);
}
