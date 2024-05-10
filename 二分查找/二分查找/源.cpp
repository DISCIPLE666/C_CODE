#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	/*for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}*/
	int n = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	
	printf("输入要查找的值");
	scanf("%d", &n);
	while (left<=right)
	{
		 int find = (left + right) / 2;
		if (arr[find] < n)
			left = find;
		else if (arr[find] > n)
			right = find;
		else
		{
			printf("%d", find);
			break;
		}
	}
	return 0;
}