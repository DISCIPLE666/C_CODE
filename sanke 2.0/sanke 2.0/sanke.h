#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>
#define POS_X 24
#define POS_Y 5
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)
//�ߵķ���
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//�ߵ�״̬
enum GAME_STATUS
{
	OK,//����
	KILL_BY_WALL,//ײǽ
	KILL_BY_SELF,//ײ���Լ�
	END_NORMAL//�˳�
};

//�������͵�����
typedef struct sankeNode
{
	int x;
	int y;
	struct sankeNode* next;
}sankeNode, * psankeNode;
//̰����
typedef struct Sanke
{
	psankeNode _psanke;//ָ����ͷ�����ָ��
	psankeNode pfood;//ָ��ʳ�﷽���ָ��
	enum DIRECTION dir;//�ߵķ���
	enum GAME_STATUS status;//��Ϸ״̬
	int food_weight;//һ��ʳ��ķ���
	int score;      //�ܳɼ�
	int sleep_time;//��Ϣʱ�䣬ʱ����ٶȿ� 
}Sanke, * psanke;
void setpos(short x, short y);
//��ʼ��Ϸ
void gamestart(psanke ps);
//��ӭ����
void welcometogame();
//������ͼ
void creatmap();
//������ʼ̰����
void initsanke(psanke ps);
//����ʳ��
void creatfood(psanke ps);
//������Ϸ
void gamerun(psanke ps);
//�ƶ���
void sankemove(psanke ps);
//��Ϸ����
void gameend(psanke ps);