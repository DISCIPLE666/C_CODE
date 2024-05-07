#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>
#define POS_X 24
#define POS_Y 5
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)
//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//蛇的状态
enum GAME_STATUS
{
	OK,//正常
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF,//撞到自己
	END_NORMAL//退出
};

//蛇身类型的声明
typedef struct sankeNode
{
	int x;
	int y;
	struct sankeNode* next;
}sankeNode, * psankeNode;
//贪吃蛇
typedef struct Sanke
{
	psankeNode _psanke;//指向蛇头方向的指针
	psankeNode pfood;//指向食物方向的指针
	enum DIRECTION dir;//蛇的方向
	enum GAME_STATUS status;//游戏状态
	int food_weight;//一个食物的分数
	int score;      //总成绩
	int sleep_time;//休息时间，时间短速度快 
}Sanke, * psanke;
void setpos(short x, short y);
//开始游戏
void gamestart(psanke ps);
//欢迎界面
void welcometogame();
//创建地图
void creatmap();
//创建初始贪吃蛇
void initsanke(psanke ps);
//创建食物
void creatfood(psanke ps);
//运行游戏
void gamerun(psanke ps);
//移动蛇
void sankemove(psanke ps);
//游戏结束
void gameend(psanke ps);