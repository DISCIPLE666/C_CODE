#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int stdata;
typedef struct stack
{
	stdata* a;
	int top;
	int capacity;
}ST;
bool STempty(ST* ps)
{
	return ps->top == 0;
}
void STinit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void STpush(ST* ps, stdata x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		stdata* newa = (stdata*)realloc(ps->a, sizeof(newcapacity));
		if (newa == NULL)
		{
			perror("STpush realloc fail");
			return;
		}
		ps->a = newa;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top++] = x;
	ps->top++;
}
void STdestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void STpop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
stdata STTop(ST* ps)
{
	assert(ps);
	return ps->a[ps->top--];
}
int STsizeof(ST* ps)
{
	assert(ps);
	return ps->top;
}
