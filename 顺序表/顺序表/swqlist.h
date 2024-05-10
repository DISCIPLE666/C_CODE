#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int sll;
typedef struct seqlist
{
	sll* arr;
	int size;
	int cap;
}sl;
void slinit(seqlist*s) {
	s->arr = NULL;
	s->cap = s->size = 0;
}
void slpushback(sl* s, sll x)
{
	assert(s);
	int newcap = s->cap == 0 ? 4 : 2 * s->cap;
	if (s->cap == s->size)
	{
		sll* temp = (sll*)realloc(s->arr, newcap * sizeof(sll));
		if (temp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		s->arr = temp;
	}
	s->arr[s->size] = x;
	s->size++;

}
void pushfount(sl* s, sll x)
{
	assert(s);
	if (s->cap == s->size)
	{
		int newcap = s->cap == 0 ? 4 : 2 * s->cap;
		sll* temp = (sll*)realloc(s->arr, newcap * sizeof(sll));
		if (temp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		s->arr = temp;
	}
	for (int i = s->size; i>0; i--)
	{
		s->arr[i] = s->arr[i-1];
	}
	s->arr[0] = x;
	s->size++;
	
}
void slpopback(sl* s)
{
	assert(s);
	assert(s->size);
	for (int i = 0; i < s->size; i++)
	{
		s->arr[i] = s->arr[i + 1];
	}
	s->size--;
}
void sldestory(sl* s) {

	if (s->arr)
	{
		free(s->arr);
	}
	s->arr = NULL;
	s->cap = s->size = 0;
}