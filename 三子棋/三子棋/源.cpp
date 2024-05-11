#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define LIE 3

void mune()
{
	printf("******************\n");
	printf("***** 1.��ʼ *****\n");
	printf("***** 0.�˳� *****\n");
	printf("******************\n");

	
}
void update(char show[ROW][LIE],int row,int lie)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < lie; j++)
		{
			show[i][j] =' ';
			
		}
	}
}
void sprintf(char show[ROW][LIE],int row,int lie)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lie; j++)
		{
			printf("%c", show[i][j]);
		    if (j < lie - 1)
			printf("  |");	
		}
		printf("\n");
		
		if (i!=row - 1)
		{
			for (int i = 0; i < lie; i++)
			{
				printf("---");
				if(i!=lie-1)
				printf("|");
			}
			printf("\n");
		}	
	}
	

}
void player(char show[ROW][LIE],int row,int lie)
{
	while (1)
	{
		printf("������������������:>");
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		if (x>=1 && x<=row&&y>=1&&y<=lie)
		{
			if (show[x - 1][y - 1] == ' ')
			{
				show[x - 1][y - 1] = '*';
				sprintf(show, row, lie);
				break;
			}
			else
				printf("�������ѱ�ռ��\n");
		}
		else
			printf("��������ȷ����(1<=x<=3),(1<=y<=3)\n");
		
		
	}
	

}
void compute1(char show[ROW][LIE],int row,int lie)
{
	printf("������:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % lie;
		if (show[x][y] == ' ')
		{
			show[x][y] = '#';
			break;
		}
	}

	sprintf(show, row, lie);
}
//void compute2(char show[][LIE],int row,int lie)
//{
//	int x = 0, y = 0;
//	
//}
char win(char show[ROW][LIE])
{
	for (int i = 0; i < ROW; i++)
	{
		if (show[i][0] == show[i][1]&&show[i][1] == show[i][2] && show[i][0] != ' ')
			return show[i][0];
	}
	for (int j = 0; j < LIE; j++)
	{
		if (show[0][j] == show[1][j] &&show[1][j] == show[2][j] && show[0][j] != ' ')
			return show[0][j];
	}
	if (show[0][0] == show[1][1]&&show[1][1] == show[2][2] && show[0][0] != ' ' || show[2][0] == show[1][1]&&show[1][1] == show[0][2] && show[2][0] != ' ')
		return show[1][1];
	

	return 'Q';
	
}

void game()
{
	char show[ROW][LIE];
	//��������
	update(show,ROW,LIE);
	//��ӡ����
	sprintf(show, ROW, LIE);
	char ret=0;
	while (1)
	{
		//�����
		player(show, ROW, LIE);
		win(show);
	    ret = win(show);
		if (ret != 'Q')
		{
			break;
		}
		//������
		compute1(show, ROW, LIE);
		win(show);
		ret = win(show);
		if (ret != 'Q')
		{
			break;
		}
	
	}
	if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else 
	{
		printf("ƽ��\n");
	}
	sprintf(show, ROW, LIE);

	////����ߵڶ���
	//player(show, ROW, LIE);
	////�����ߵڶ���
	//compute2(show, ROW, LIE);
	
}


int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		mune();
		int intput = 0;
		printf("��ѡ��>");
		scanf("%d", &intput);
		switch (intput)

		{
		case 1:
			game();
			break;
		case 0:
			return 0;
			break;
		default:
			printf("��������ȷֵ\n");

		}
	}


	return 0;
}
