#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int max(int a[], int n)
{
	if (n == 1) { return a[0]; }
	else
	{
		int x;
		x = max(a, n - 1);
		if (a[n-1] > x) { return a[n-1]; }
		else { return x; }
	}
}
int main()
{
	int a[SIZE] = { 8,4,6};
	printf("%d",max(a,SIZE));
	system("pause");
	return 0;
}
