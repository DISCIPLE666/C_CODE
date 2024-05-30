#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HpData;
typedef struct Heap
{
	HpData* a;
	int size;
	int capacity;
}HP;

void HpInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HpDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;

	
}
void HpPush(HP* php,HpData*x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HpData newa = (HpData*)realloc(php->a, sizeof(newcapacity));
		if (newa == NULL)
		{
			perror("HpPush realloc fail");
			return;
		}
		php->capacity = newcapacity;
		php->a = newa;
	}
	php->a[php->size] = x;
	php->size++;
	Adjustup(php->a,php->size-1);
}
void HpPop(HP* php)
{
	assert(php);
	php->a[0] = php->a[php->size];
	php->size--;
	AdjustDown(php, php->size,0);
	
}
void Adjustup(HpData* a,int child)
{
	int parent = (child - 1) / 2;
	while (parent)
	{

		if (a[child] > a[parent])
		{
			HpData temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
		}
		else
			break;
		parent = (child - 1) / 2;
	}

}
void AdjustDown(HpData* a,int n,int parent)
{
	int child = (parent + 1) * 2;
	while (a[child]>n)
	{
		if (a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		parent = child;
		child = (parent + 1) * 2;
	}
}
HpData HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}
int HpSize(HP* php)
{
	assert(php);
	return php->size;
}
int HpEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapSort(int* a, int n)
{
	for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		Adjustup(a,i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}