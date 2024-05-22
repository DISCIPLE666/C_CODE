#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>

void CreateNDate()
{
	// дьЪ§Он
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int child = (parent + 1) * 2;
	while (child < n)
	{
		if (a[child] < a[child + 1]&&child+1<n)
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			parent = child;
			child = (parent + 1) * 2;
		}
		else
			break;
	}
}
void PrintTopK(int k)
{
	int*Kminheap = (int*)malloc(sizeof(int) * k);
	if (Kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &Kminheap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(Kminheap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > Kminheap[0])
		{
			Kminheap[0] = x;
			AdjustDown(Kminheap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", Kminheap[i]);
	}
	
}

int main()
{
	CreateNDate();
	PrintTopK(10);
	return 0;
}