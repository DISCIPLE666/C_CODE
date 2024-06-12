#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Qdata;
 typedef struct Qnode 
{
	 struct Qnode* next;
	 Qdata data;

}Qnode;
 typedef struct Queue
 {
	 Qnode* phead;
	 Qnode* ptail;
	 int size;

 }Queue;
 void Queueinit(Queue*pst)
 {
	 assert(pst);
	 pst->phead = NULL;
	 pst->ptail = NULL;
	 pst->size = 0;
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
	 pst->ptail = NULL;
	 pst->size = 0;
 }
 void QueuePush(Queue* pst,Qdata x)
 {
	 assert(pst);
	 if (pst->phead == NULL)
	 {
		 Qnode* new = (Qnode*)malloc(sizeof(Qnode));
		 if (new == NULL)
		 {
			 perror("QueuePush malloc fail");
			 exit(1);
		 }
		 new->next = NULL;
		 pst->phead = new;
		 pst->ptail = new;
		 pst->size++;
	 }
	 else
	 {
		 Qnode* new = (Qnode*)malloc(sizeof(Qnode));
		 if (new == NULL)
		 {
			 perror("QueuePush malloc fail");
			 exit(1);
		 }
		 new->next = NULL;
		 pst->ptail->next = new;
		 pst->ptail = new;
		 pst->size++;
	 }
	 pst->ptail->data = x;
 }
 void Queuepop(Queue* pst)
 {
	 assert(pst);
	 Qnode* cur = pst->phead;
	 if (pst->phead == pst->ptail)
	 {
		 pst->phead = pst->phead->next;
		 free(cur);
		 pst->ptail = NULL;
		 return;
	 }
	 pst->phead = pst->phead->next;
	 free(cur);
 }
int main()
{

	return 0;
}