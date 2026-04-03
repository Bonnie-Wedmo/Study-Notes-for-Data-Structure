#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MaxLine 2000

int main()
{
	FILE* fin = fopen("filein.txt", "r");
	FILE* fout = fopen("fileout.txt", "w");

	if (fin == NULL) {
		printf("无法打开文件 filein.txt\n");
		return 1;
	}

	char DontWant[MaxLine];
	char Want[MaxLine];
	scanf("%s%s", DontWant, Want);
	int lenth = strlen(DontWant);

	char line[MaxLine];
	while (fgets(line, sizeof(line), fin))
	{
		//先把这一行都换成小写的，储存在TransLine里
		char TransLine[MaxLine];
		strcpy(TransLine, line);
		int i;
		for (i = 0; TransLine[i]; i++)
		{
			if (line[i] >= 'A' && line[i] <= 'Z')
			{
				TransLine[i] = line[i] + 'a' - 'A';
			}
		}

		char* pTrans = TransLine;
		char* pOri = line;
		char* found;
		char NewLine[2 * MaxLine] = "";

		while ((found = strstr(pTrans, DontWant))!=NULL)
		{
			int start = found - TransLine;
			char* MatchOri = line + start;
			strncat(NewLine, pOri, MatchOri - pOri);
			strcat(NewLine, Want);

			pOri = MatchOri + lenth;
			pTrans = found + lenth;
		}
		strcat(NewLine, pOri);
		fputs(NewLine, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
