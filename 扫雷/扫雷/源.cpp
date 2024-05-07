#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define LIE 9
#define ROWS ROW+2
#define LIES LIE+2


void mune()
{
	printf("*********************\n");
	printf("****** 1.��ʼ *******\n");
	printf("****** 0.�˳� *******\n");
	printf("*********************\n");
}
void update(char board[][LIES], char temp)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < LIES; j++)
		{
			board[i][j] = temp;
		}
	}
}
void sprintf(char board[][LIES])
{
	printf("-------ɨ����Ϸ-------\n");
	for (int i = 0; i < ROW+1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= LIE; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void setmine(char board[ROWS][LIES])
{
	int count = 10;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % LIE + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	
}
int getmine(char mine[][LIES], char show[][LIES],int x, int y)
{
	int sum = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i == x && j == y)
				continue;
			else
			{
				sum += mine[i][j] - '0';
				if (mine[i][j] == '0'&&show[i][j]=='*')
				{
					show[i][j] = '0';
				}
			}
		}
	}
	printf("%d", sum);
	return sum;
}
int decide(char show[][LIES],char mine[][LIES])
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= LIE; j++)
		{
			if (show[i][j] == mine[i][j] && show[i][j] == '0')
			{
				printf("�úú�");
				return 0;
			}
		}
	}
	return 1;
}
void findmine(char mine[][LIES], char show[][LIES])
{
	while (1)
	{
		printf("�������׵�����:>");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y>=1 && y<=9)
		{
			if (mine[x][y] == '0')
			{
				int count = getmine(mine,show, x, y);
				show[x][y] = count+'0';
				sprintf(show);
				sprintf(mine);
				/*int a=decide(show,mine);
				if (a == 0)
					break;*/
			}
			else
			{
				printf("��ϲ�������ˣ�");
				break;
			}
		}
		else
		{
			printf("������Ϸ�����");
		}
	}
	
}
void game()
{
	char mine[ROWS][LIES];
	char show[ROWS][LIES];
	//��ʼ������
	update(mine, '0');
	update(show, '*');
	//��ӡ����
	sprintf(mine);
	sprintf(show);
	//������
	setmine(mine);
	sprintf(mine);
	//�Ų���
	findmine(mine,show);

	
	
}
int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		mune();
		printf("������ѡ��:>");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			printf("����������:>");
			break;
		}

	}

	return 0;
}