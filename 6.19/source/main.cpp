#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a, b, c[11];
int main()
{
	c[11] = { 0 };
	srand(time(NULL));
	for (int i = 1; i <= 36000; i++)
	{
		a = rand() % 6 + 1;
		b = rand() % 6 + 1;
		c[a + b] += 1;
	}
	for (int i = 2; i <= 12; i++)
	{
		printf("������l�`�@���I�Ƭ�%d������:%d\n",i,c[i]);
	}
	puts("");
	system("pause");
	return 0;
}
