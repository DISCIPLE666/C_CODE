#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int select(int*a,int left, int right)
{
	int k = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[k]< a[left])
			return left;
		else if (a[k] > a[right])
			return right;
		else
			return k;
			
	}
	else
	{
		if (a[k] < a[right])
			return right;
		else if (a[k] > a[left])
			return left;
		else
			return k;
	}
}
void QuckSort(int* a,int left,int right)
{
	if (left >=right)
		return;
	int b = select(a, left, right);
	Swap(&a[left], &a[b]);
	int k = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		
		while (begin<end && a[end]>=a[k])
		{
			--end;
		}
		while (begin<end && a[begin]<=a[k])
		{
			++begin;
		}
		Swap(&a[end], &a[begin]);
		
	}
	Swap(&a[begin], &a[k]);
	k = begin;
	QuckSort(a, left, k - 1);
	QuckSort(a, k + 1, right);

}
#include"Ô´.h"
//Õ»ÊµÏÖ
int QSort(int* a, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	int k = left;
	while (cur <= right)
	{
		if (a[cur] < a[k] && prev++ != cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[k], &a[prev]);
	k = prev;
	return k;
 }
void QuickSOrtNOnR(int* a, int left, int right)
{
	ST st;
	STinit(&st);
	STpush(&st, right);
	STpush(&st, left);
	while (!STempty(&st))
	{
		int begin = STTop(&st);
		STpop(&st);
		int end = STTop(&st);
		STpop(&st);
		int keyi = QSort(a, begin, end);
		if (keyi + 1 < end)
		{
			STpush(&st, end);
			STpush(&st, keyi + 1);
		}
		if (keyi - 1 > begin)
		{
			STpush(&st, keyi - 1);
			STpush(&st, begin);
		}
			
	}
}
int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9 };
	QuickSOrtNOnR(a, 0, 9);
	for (int j = 0; j <10; j++)
	{
		printf("%d", a[j]);
	}
	return 0;
}
