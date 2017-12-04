#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
void printHeader();
void printRow(const int a[],size_t low,size_t mid, size_t high);
size_t binarySearch(const int a[], int searchkey, size_t low,size_t high);
int main()
{
	int a[SIZE];
	int key;
	size_t i;
	size_t result;
	
	//建立陣列
	for (i = 0; i < SIZE; i++)
	{
		a[i] = 2 * i;
	}

	printf("Enter a number between 0 and 28:");		scanf("%d",&key);
	
	//印出表格形式
	printHeader();

	//搜尋結果
	result = binarySearch(a, key, 0, SIZE - 1);

	//顯示搜尋結果
	if (result != -1) { printf("\n%d found in array element %d\n",key,result); }
	else { printf("\n%d not found\n",key); }
	system("pause");
	return 0;
}
void printHeader()
{
	puts("\nSubscripts:");
	for (unsigned int i = 0; i < SIZE; i++)
	{
		printf("%4u",i);
	}
	puts("");
	for (unsigned int i = 0; i < SIZE * 4; i++)
	{
		printf("-");
	}
	puts("");
}
size_t binarySearch(const int a[], int searchkey, size_t low, size_t high)		//high為上標，low為下標
{
	if (high >= low)
	{
		size_t middle;
		middle = (high + low) / 2;

		//顯示使用到搜尋的陣列部分(副陣列)
		printRow(a, low, middle, high);

		//二分法
		if (searchkey == a[middle]) { return middle; }
		else if (searchkey < a[middle])
		{
			high = middle - 1;
			binarySearch(a, searchkey, low, high);
		}
		else
		{
			low = middle + 1;
			binarySearch(a, searchkey, low, high);
		}
	}
	else { return -1; }
}
void printRow(const int a[],size_t low,size_t mid,size_t high)
{
	size_t i;

	//搜尋整個陣列
	for (i = 0; i < SIZE; i++)
	{
		
		//陣列中未被副陣列使用的顯示空白
		if (i<low || i>high) { printf("    "); }
		
		//顯示陣列中被副陣列使用到的值
		else { printf("%4d",a[i]); }
	}
	puts("");
}