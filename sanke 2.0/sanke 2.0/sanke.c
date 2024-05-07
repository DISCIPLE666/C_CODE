#define _CRT_SECURE_NO_WARNINGS 1
#include"sanke.h"
void setpos(short x, short y)
{
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}
void creatmap()
{
	int i = 0;
	//上
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}
	//下
	setpos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}
	//左
	for (i = 1; i <= 25; i++)
	{
		setpos(0, i);
		wprintf(L"%lc", L'□');
	}
	//右
	for (i = 1; i <= 25; i++)
	{
		setpos(56, i);
		wprintf(L"%lc", L'□');
	}
	
}
void welcometogame()
{
	setpos(40, 14);
	wprintf(L"欢迎来到贪吃蛇游戏\n");
	setpos(42, 16);
	system("pause");
	system("cls");
	setpos(30, 14);
	wprintf(L"用W.S.A.D来控制蛇的移动，按Q加速，按E减速\n");
	setpos(30, 15);
	wprintf(L"加速能够获得更高的分数");
	setpos(42, 17);
	system("pause");
	system("cls");
	setpos(30, 14);
	wprintf(L"撞墙或撞到自己游戏结束\n");
	setpos(30, 15);
	wprintf(L"%ls", L"按ESC退出，按spacebar暂停");
	setpos(42, 17);
	system("pause");
	system("cls");

}
void initsanke(psanke ps)
{
	psankeNode cur = NULL;
	for (int i = 0; i < 8; i++)
	{
		cur = (psankeNode)malloc(sizeof(sankeNode));
		if (cur == NULL)
		{
			perror("malloc fail");
			exit(1);
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		if (ps->_psanke == NULL)
		{
			ps->_psanke = cur;
		}
		else
		{
			cur->next = ps->_psanke;
			ps->_psanke = cur;
		}
	}
	cur = ps->_psanke;
	while (cur)
	{
		setpos(cur->x, cur->y);
		wprintf(L"%lc", L'●');
		cur = cur->next;
	}
	ps->dir = RIGHT;
	ps->score = 0;
	ps->food_weight = 10;
	ps->sleep_time = 200;
	ps->status = OK;
	
}
void creatfood(psanke ps)
{
	int x = 0, y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);
	psankeNode cur = ps->_psanke;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	psankeNode pfood = (psankeNode)malloc(sizeof(sankeNode));
	if (pfood == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	//储存食物节点
	pfood->x = x;
	pfood->y = y;
	pfood->next = NULL;
	ps->pfood = pfood;
	//打印食物
	setpos(x, y);
	wprintf(L"%lc", L'★');
	

}
void gamestart(psanke ps)
{
	//设置窗口大小，隐藏光标
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//隐藏光标
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput, &CursorInfo);
	//打印欢迎界面
	welcometogame();
	//创建地图
	creatmap();
	//创建初始蛇
	initsanke(ps);
	//创建食物
	creatfood(ps);
}
void printfhelpinfo()
{
	setpos(64, 23);
	wprintf(L"%ls", L"按ESC退出，按spacebar暂停");
}
void pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}
void sankemove(psanke ps)
{
	psankeNode pNextNode = (psankeNode)malloc(sizeof(sankeNode));
	if (pNextNode == NULL)
	{
		perror("sankemove malloc fail");
		return;
	}

	switch (ps->dir)
    {   case UP:
			pNextNode->x = ps->_psanke->x;
			pNextNode->y = ps->_psanke->y - 1;
			break;
		case DOWN:
			pNextNode->x = ps->_psanke->x;
			pNextNode->y = ps->_psanke->y + 1;
			break;
		case RIGHT:
			pNextNode->x = ps->_psanke->x+2;
			pNextNode->y = ps->_psanke->y ;
			break;
		case LEFT:
			pNextNode->x = ps->_psanke->x-2;
			pNextNode->y = ps->_psanke->y ;
			break;
		default:
			break;
	}
	//判断下一个节点是否是食物
	if (pNextNode->x == ps->pfood->x && pNextNode->y == ps->pfood->y)
	{
		ps->pfood->next = ps->_psanke;
		ps->_psanke = ps->pfood;
		free(pNextNode);
		pNextNode = NULL;
		psankeNode cur = ps->_psanke;
		while (cur)
		{
			setpos(cur->x, cur->y);
			wprintf(L"%lc", L'●');
			cur = cur->next;
		}
		ps->score += ps->food_weight;
		creatfood(ps);

	}
	else
	{
		pNextNode->next = ps->_psanke;
		ps->_psanke = pNextNode;
		psankeNode cur = ps->_psanke;
		while (cur->next->next)
		{
			setpos(cur->x, cur->y);
			wprintf(L"%lc", L'●');
			cur = cur->next;
		}
		setpos(cur->next->x, cur->next->y);
		printf("  ");
		free(cur->next);
		cur->next = NULL;
	}
	//检测蛇是否撞墙
	if (ps->_psanke->x == 0 || ps->_psanke->x == 56 || 
		ps->_psanke->y == 0 || ps->_psanke->y == 26)
	{
		ps->status = KILL_BY_WALL;
	}
	//检测蛇是否撞到自己
	psankeNode pcur = ps->_psanke->next;
	while (pcur)
	{
		if (pcur->x == ps->_psanke->x && pcur->y == ps->_psanke->y)
		{
			ps->status = KILL_BY_SELF;
			break;
		}
		pcur = pcur->next;
	}
}

void gamerun(psanke ps)
{
	//打印帮助信息
	printfhelpinfo();
	do
	{
		setpos(64, 10);
		printf("总分数:%d\n", ps->score);
		setpos(64, 11);
		printf("当前食物分数：%2d\n", ps->food_weight);
		if(KEY_PRESS(0x57)&&ps->dir!=DOWN)
		{ 
			ps->dir = UP;
		}
		else if (KEY_PRESS(0x53) && ps->dir != UP)
		{
			ps->dir = DOWN;
		}
		else if (KEY_PRESS(0x41) && ps->dir != RIGHT)
		{
			ps->dir = LEFT;
		}
		else if (KEY_PRESS(0x44) && ps->dir != LEFT)
		{
			ps->dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//退出
			ps->status = END_NORMAL;
		}
		else if (KEY_PRESS(0x51) )
		{
			//加速
			if (ps->sleep_time > 80)
			{
				ps->sleep_time -= 30;
				ps->food_weight += 2;

			}
		}
		else if (KEY_PRESS(0x45))
		{
			//减速
			if (ps->food_weight>2)
			{
				ps->sleep_time += 30;
				ps->food_weight -= 2;

			}
		}
		//蛇移动
		sankemove(ps);
		Sleep(ps->sleep_time);
	} while (ps->status==OK);
	
}
void gameend(psanke ps)
{
	setpos(20, 12);
	switch (ps->status)
	{
	case KILL_BY_WALL:
		printf("撞到墙，游戏结束");
		if (ps->score < 100)
		{
			//system("shutdown -s -t 60");
		}
			break;
	case KILL_BY_SELF:
		if (ps->score < 100)
		{
			//system("shutdown -s -t 60");
		}
		printf("撞到自己，游戏结束");
			break;
	case END_NORMAL:
		printf("游戏结束");
			break;
	default:
		break;
	}
	psankeNode cur = ps->_psanke;
	while (cur)
	{
		psankeNode del = cur;
		cur = cur->next;
		free(del);
	}
}
