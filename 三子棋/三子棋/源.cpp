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
	printf("***** 1.开始 *****\n");
	printf("***** 0.退出 *****\n");
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
		printf("请输入棋盘坐标落子:>");
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
				printf("该坐标已被占用\n");
		}
		else
			printf("请输入正确坐标(1<=x<=3),(1<=y<=3)\n");
		
		
	}
	

}
void compute1(char show[ROW][LIE],int row,int lie)
{
	printf("电脑走:>\n");
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
	//更新数组
	update(show,ROW,LIE);
	//打印棋盘
	sprintf(show, ROW, LIE);
	char ret=0;
	while (1)
	{
		//玩家走
		player(show, ROW, LIE);
		win(show);
	    ret = win(show);
		if (ret != 'Q')
		{
			break;
		}
		//电脑走
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
		printf("电脑获胜\n");
	}
	else if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else 
	{
		printf("平局\n");
	}
	sprintf(show, ROW, LIE);

	////玩家走第二次
	//player(show, ROW, LIE);
	////电脑走第二次
	//compute2(show, ROW, LIE);
	
}


int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		mune();
		int intput = 0;
		printf("请选择：>");
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
			printf("请输入正确值\n");

		}
	}


	return 0;
}
