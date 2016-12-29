#include "stdio.h"

void print(char* a, int dlinna)
{	int i;
if (a[0] == ' ')
    i=1;
    else i=0;
for (; i < dlinna; i++)
		printf("%c", a[i]);
}
int main(){
	char c;
	char* buf=NULL;
	int m = 0, n = 0, dlinna = 0;
	while ((c = getchar()) != '!')
	{
		switch (c)
		{
		case '.':  print(buf, dlinna); printf("%c\n", c); dlinna = 0; m++; n++; break;
		case ';':  print(buf, dlinna); printf("%c\n", c); dlinna = 0; m++; n++; break;
		case '?':  dlinna = 0; m++;    break;
		case '\n': dlinna = 0;    	    break;
		case '\t': dlinna = 0;    	    break;
		default:
		{
			buf = (char*)realloc(buf, (++dlinna) * sizeof(char));
			buf[dlinna - 1] = c;
		}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n);
	return 0;
}
