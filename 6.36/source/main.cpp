#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
void stringReverse(int);
char str[SIZE];
int main(void)
{
	int length;
	printf("Enter a string : ");
	scanf("%s", &str);
	length = strlen(str);
	stringReverse(length);
	puts("");
	system("pause");
	return 0;
}
void stringReverse(int length)
{
	if (length == 1)
	{
		printf("%c", str[0]);
	}
	else
	{
		printf("%c", str[length - 1]);
		stringReverse(length - 1);
	}
}