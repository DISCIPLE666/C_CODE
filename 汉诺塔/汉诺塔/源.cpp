#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//    int hanoi(int, char, char, char);
//    int n, counter;
//    printf("Input the number of diskes£º");
//    scanf("%d", &n);
//    printf("\n");
//    counter = hanoi(n, 'A', 'B', 'C');
//    return 0;
//}
//
//int hanoi(int n, char x, char y, char z)
//{
//    int move(char, int, char);
//    if (n == 1)
//        move(x, 1, z);
//    else
//    {
//        hanoi(n - 1, x, z, y);
//        move(x, n, z);
//        hanoi(n - 1, y, x, z);
//    }
//    return 0;
//}
//
//int move(char getone, int n, char putone)
//{
//    static int k = 1;
//    printf("%2d:%3d # %c---%c\n", k, n, getone, putone);
//    if (k++ % 3 == 0)
//        printf("\n");
//    return 0;
//}


#include<stdio.h>


void move(char pos1,char pos2)
{
	static int k = 1;
	printf("%2d %c->%c\n",k,pos1, pos2);
	k++;
	
}

int count = 0;
void hannuo(int n, char pos1, char pos2, char pos3)
{
	
	if (n == 1)
	{
		move(pos1, pos3);
	}
	else
	{
		
		hannuo(n-1 , pos1, pos3, pos2);
		move(pos1, pos3);
		hannuo(n - 1 ,pos2, pos1, pos3);
	}
	
}
int main()
{
	hannuo(3, 'A', 'B', 'C');
	return 0;
}