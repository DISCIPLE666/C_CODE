#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void InsertSort(int* a, int n)
{
	
	for (int i=0;i < n - 1; i++)
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end+1] = tem;
	}
	for (int i = 0; i < n;i++)
	printf("%d\n", a[i]);
}
//¹þÏ£
void ShellSort(int* a, int n)
{
	int gap = 3;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++)
		{
			for (int i = 0; i < n - gap; i++)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
	

	
}
int main()
{
	int a[10] = { 1,3,2,4,0,8,6,7,9,5 };
	InsertSort(a, 10);
	return 0;
}