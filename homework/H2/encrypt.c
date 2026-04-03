#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char crtChart[2][27];

int main()
{
	FILE* fin = fopen("encrypt.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	char pin[50];
	scanf("%s", pin);//输入密钥单词

	char NoRePin[50];//原密钥单词不变，新建一个用于储存去重之后的
	strcpy(NoRePin, pin);
	int flag = 0;
	int i = 0; int j = 0;

	while (NoRePin[i] != '\0')
	{
		int pos = NoRePin[i] - 'a';
		if ((flag & (1 << pos)) == 0)
		{
			NoRePin[j] = NoRePin[i];
			flag |= (1 << pos);//把出现过的字母对应的二进制位设成1
			j++;
		}
		i++;
	}
	NoRePin[j] = '\0';//现在去重结束了

	for (int k = 0; k < 26; k++)
	{
		crtChart[0][k] = 'a' + k;
	}
	crtChart[0][26] = '\0';

	for (int k = 0; k < j; k++)
	{
		crtChart[1][k] = NoRePin[k];
	}

	int lenth = j;
	for (int k = 25; k >= 0; k--)
	{
		if ((flag & (1 << k)) == 0)
		{
			crtChart[1][lenth] = 'a' + k;
			lenth++;
		}
	}
	crtChart[1][lenth] = '\0';//到这里对应字母表做完了

	int ch;
	while ((ch = fgetc(fin)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			int index = ch - 'a';
			fputc(crtChart[1][index], fout);
		}
		else fputc(ch, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}