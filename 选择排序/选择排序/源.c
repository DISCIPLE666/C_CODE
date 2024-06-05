#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
void Swap(int*a, int*b)
{
	int tmp =*a;
	*a = *b;
	*b =tmp;
}
void ChooseSort(int* a, int n)
{
	int bagin = 0;
	int end = n - 1;
	
	while (bagin <end)
	{
		int minx = bagin; int maxx = bagin;
		for (int i = bagin+1; i <=end; i++)
		{
			if (a[minx] > a[i])
			{
				minx = i;
			}
			if (a[maxx] < a[i])
			{
				maxx = i;
			}
		}
		Swap(&a[bagin], &a[minx]);
		if (maxx == bagin)
		{
			maxx = minx;
		}
		Swap(&a[end], &a[maxx]);
		bagin++;
		end--;
	}
	
	for (int j = 0; j < n; j++)
	{
		printf("%d ", a[j]);
	}
	
}
int main()
{
	int a[8] = { 9,1,2,5,7,4,6,3 };
	clock_t start, cend;
	start = clock();
	ChooseSort(a, 8);
	cend = clock();
	printf("%d\n", start - cend);
	return 0;
}