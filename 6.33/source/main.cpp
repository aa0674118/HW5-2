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
	
	//�إ߰}�C
	for (i = 0; i < SIZE; i++)
	{
		a[i] = 2 * i;
	}

	printf("Enter a number between 0 and 28:");		scanf("%d",&key);
	
	//�L�X���Φ�
	printHeader();

	//�j�M���G
	result = binarySearch(a, key, 0, SIZE - 1);

	//��ܷj�M���G
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
size_t binarySearch(const int a[], int searchkey, size_t low, size_t high)		//high���W�СAlow���U��
{
	if (high >= low)
	{
		size_t middle;
		middle = (high + low) / 2;

		//��ܨϥΨ�j�M���}�C����(�ư}�C)
		printRow(a, low, middle, high);

		//�G���k
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

	//�j�M��Ӱ}�C
	for (i = 0; i < SIZE; i++)
	{
		
		//�}�C�����Q�ư}�C�ϥΪ���ܪť�
		if (i<low || i>high) { printf("    "); }
		
		//��ܰ}�C���Q�ư}�C�ϥΨ쪺��
		else { printf("%4d",a[i]); }
	}
	puts("");
}