
#include"╤сап.h"

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
void QueueDestroy(Queue* pst)
{
	assert(pst);
	Qnode* cur = pst->phead;
	while (cur)
	{
		Qnode* del = cur;
		cur = cur->next;
		free(del);
	}
	pst->phead = NULL;
	pst->tail = NULL;
	pst->size = 0;
}