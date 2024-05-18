#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ltdata;
typedef struct listnode
{
	ltdata data;
	struct listnode* next;
	struct listnode* prev;
}listnode;
listnode*ltbuynode(ltdata x)
{
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data;
	newnode->next = newnode->prev = newnode;
	return newnode;
}
void ltinit(listnode** phead)
{
	*phead = ltbuynode(1);
}
void ltpushback(listnode* phead, ltdata x)
{
	listnode* newnode = ltbuynode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void itpintf(listnode* phead)
{
	listnode* cur = phead;
	while (cur->next != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}
//ͷ��
void ltpushfount(listnode* phead, ltdata x)
{
	listnode* cur = ltbuynode(x);
	cur->next = phead->next;
	phead->next->prev = cur;
	cur->prev = phead;
	phead->next = cur;
}
//ͷɾ
void itpopfount(listnode* phead)
{
	listnode* cur = phead->next;
	phead->next = cur->next;
	cur->next->prev = phead;
	free(cur);
	cur = NULL;
}
//βɾ
void ltpopback(listnode* phead)
{
	assert(phead->next!=phead);
	listnode* cur = phead->prev;
	phead->prev = cur->prev;
	cur->prev->next = phead;
	free(cur);
	cur = NULL;
	
}

int main()
{
	return 0;
}