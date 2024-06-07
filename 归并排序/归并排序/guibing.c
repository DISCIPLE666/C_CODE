#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void _MertgeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_MertgeSort(a, tmp, begin, mid);
	_MertgeSort(a, tmp, mid + 1, end);
	int begin1 = begin; int end1 = mid;
	int begin2 = mid + 1; int end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
//·ÇµÝ¹é°æ±¾
void Mertge(int* a, int* tmp, int end)
{
	int gap = 1;
	while (gap < end)
	{
		for (int j = 0; j < end; j += gap * 2)
		{
			int begin1 = j; int end1 = j + gap - 1;
			int begin2 = j+gap; int end2 = j + gap * 2 - 1;
			int i = j;
			if (begin2 >= end)
			{
				break;
			}
			if (end2 >= end)
			{
				end2 =end-1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
			memcpy(a + j, tmp + j, (end2 - j + 1) * sizeof(int));
		}
		gap *= 2;
	}

}
void MertgeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	//_MertgeSort(a, tmp, 0, n - 1);
	Mertge(a, tmp, n);
	free(tmp);
	tmp = NULL;
}

int main()
{
	int a[10] = { 1,3,4,2,6,5,7,9,8,0 };
	MertgeSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}