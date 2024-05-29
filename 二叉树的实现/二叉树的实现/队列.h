#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct BinaryTreeNode* Qdata;
typedef struct Queuenode
{
	struct Queuenode* next;
	Qdata val;
}Qnode;
typedef struct queue
{
	Qnode* phead;
	Qnode* tail;
	int size;
}Queue;
void Queuepush(Queue* ps, Qdata x);
void Qinit(Queue* ps);
void Qpop(Queue* ps);
void QueueDestroy(Queue* pst); 