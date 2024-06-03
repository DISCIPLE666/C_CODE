#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int sll;
typedef struct slistnode
{
	sll data;
	struct slistnode* next;
}sl;
//��ӡ������
void sltprint(sl*phead)
{
	//assert(phead);
	sl* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//ͷ��
void slpushfront(sl**phead,sll x)
{
	sl* newnode = (sl*)malloc(sizeof(sl));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next =*phead;
	*phead = newnode;
}
//β��
void slpushback(sl* phead, sll x)
{
	sl* newnode = (sl*)malloc(sizeof(sl));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		sl* cur = phead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	newnode->data = x;
	newnode->next = NULL;
}
//βɾ
void sltpopback(sl** phead)
{
	assert(*phead&&phead);
	
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		sl* cur = *phead;
		sl* pcur = *phead;
		pcur = pcur->next;
		while (pcur->next)
		{
			cur = cur->next;
		}
		free(pcur);
		pcur = NULL;
		cur->next = NULL;
	}
}
//ͷɾ
void sltpopfront(sl** phead)
{
	assert(phead&&*phead);
		sl* cur = *phead;
		sl* pcur = *phead;
		cur = cur->next;
		free(pcur);
		pcur = NULL;
		*phead = cur;
	
}
//����
sl* sltfind(sl* phead, sll x)
{
	sl* cur = phead;
	while (cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��ָ��λ��֮ǰ��������
void sltinsert(sl**phead, sl* pos, sll x)
{
	assert(phead && *phead);
	assert(pos);
	if (*phead == pos)
	{
		sltpopfront(pos, x);
	}
	else
	{

		sl* cur = *phead;
		sl* newnode = (sl*)malloc(sizeof(sl));
		if (newnode == NULL)
		{
			perror("malloc faile");
			exit(1);
		}
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->data = x;
		newnode->next = pos;
		cur->next = newnode;
	}
}
//��ָ��λ��֮���������
void sltinsertafter( sl* pos, sll x)
{
	assert(pos);
		sl* pcur = pos->next;
		sl* newnode = (sl*)malloc(sizeof(sl));
		if (newnode == NULL)
		{
			perror("malloc");
			exit(1);
		}
		newnode->next = pcur;
		pos->next = newnode;
		newnode->data = x;
}
//ɾ��pos�ڵ�
void slterase(sl**phead,sl* pos)
{
	assert(phead && *phead);
	assert(pos);
	if (pos == *phead)
	{
		*phead = pos->next;
		free(pos);
		pos == NULL;
	}
	else
	{
		sl* cur = *phead;
		while (cur != pos->next)
		{
			cur = cur->next;
		}
		cur = pos->next;
		free(pos);
		pos = NULL;
	}
}
//ɾ��pos֮��Ľڵ�
void slteraseafter(sl*pos)
{
	assert(pos&&pos->next);
	/*sl* arr[100] = { NULL };
	int i = 1;
	while (pos->next)
	{
		arr[i] = pos->next;
		pos = pos->next;
		i++;
	}
	while (i)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
		*/
	
	sl* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
	
	
}