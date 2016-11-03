#include "stdio.h"


void print(char* a, int len)
{
	int k, i, g = 0;
	if (a[i] == ' ') { g = 1; }
	else { g = 0; }
	for (i = g; i < len;i++)
		printf("%c", a[i]);
}

int main()
{
	char c, buff[512];
	int i = 0, k;
	int m = 0, n = 0, len = 0;

	while ((c = getchar()) != '!')
	{
		switch (c)
		{
		case '.':  print(buff, len); printf("%c\n",c); i = 0; m++; n++; break;
		case ';':  print(buff, len); printf("%c\n",c); i = 0; m++; n++; break;
		case '?':  i = 0; m++; break;
		case '\n': i = 0;	   break;
		case '	': i = 0;	   break;
		default:
		{
			buff[i] = c;
			i++;
			len = i;
		}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n);
	return 0;
}
