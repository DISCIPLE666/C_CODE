#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fail");
		return;
	}
	//for (int j = 0; j < n; j++)
	//{
	//	for (int i = 0; i < range; i++)
	//	{
	//		if (a[j] - min == count[i])
	//			count[i]++;
	//	}
	//}
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int p = 0;
	int q = 0;
	for (p; p < range; p++)
	{
		while (count[p]--)
		{
			a[q++] = p + min;
		}
	}
	free(count);
}

int main()
{
	int a[10] = { 1,3,4,6,5,2,7,9,8,0 };
	CountSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}