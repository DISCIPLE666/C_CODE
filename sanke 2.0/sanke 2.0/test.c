#define _CRT_SECURE_NO_WARNINGS 1
#include<locale.h>
#include"sanke.h"
void test()
{
	int ch=0;
	do 
	{
		system("cls");
		//创建贪吃蛇
		Sanke sanke = { 0 };
		//开始游戏
		gamestart(&sanke);
		//运行游戏
		gamerun(&sanke);
		//游戏结束
		gameend(&sanke);
		setpos(20, 15);
		printf("是否再来一局?(Y/N):");
		ch = getchar();
		while (getchar() != '\n');
	}while(ch !='Y'||'y');
	setpos(0, 27);
	
}
int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}