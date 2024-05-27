#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Qdata;
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
void Queuepush(Queue* ps, Qdata x)
{
	assert(ps);
	if (ps->phead == ps->tail)
	{
		Qnode* new = (Qnode*)malloc(sizeof(Qnode));
	
		if (new == NULL)
		{
			perror("Queuepush malloc fail");
			return;
		}
		new->next = NULL;
		if (ps->phead == NULL)
		{
			ps->phead = ps->tail = new;
		}
		else
			ps->tail->next = new;
	}
	ps->tail->val = x;
	ps->tail = ps->tail->next;
	ps->size++;
}
void Qinit(Queue* ps)
{
	assert(ps);
	ps->phead = ps->tail = NULL;
	ps->size = 0;
}
void Qpop(Queue* ps)
{
	assert(ps);
	Qnode* cur = ps->phead;
	if (ps->phead == ps->tail)
	{
		free(ps->phead);
		ps->phead = ps->tail = NULL;
		return;
	}
	ps->phead = ps->phead->next;
	free(cur);
}