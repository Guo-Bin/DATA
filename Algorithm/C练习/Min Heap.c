#include <stdio.h>
#include <stdlib.h>
#define maxdata 1000

typedef struct {
	int *data;
	int size;
	int capacity;
} heap;

heap* createheap(int maxsize);
int isfull(heap *p);
int isempty(heap *p);
void insert(heap *p, int x);
int deletenode(heap *p);
void predown(heap *p, int n);
heap* buildheap(heap *p);

int main()
{
	
	return 0;
}

heap* createheap(int maxsize)
{
	heap *p = (heap*)malloc(sizeof(heap));
	p->data = (int*)malloc((maxsize+1)*sizeof(int));
	p->size = 0;
	p->capacity = maxsize;
	p->data[0] = maxdata;
	return p;
}

int isfull(heap *p)
{
	return (p->size == p->capacity);
}

int isempty(heap *p)
{
	return (p->size == 0);
}

void insert(heap *p, int x)
{
	if(isfull(p))
	{
		printf("The heap is full!");
		return;
	}
	int i = ++p->size;
	while(p->data[i/2] > x)
	{
		p->data[i] = p->data[i/2];
		i/=2;
	}
	p->data[i] = x;
}

int deletenode(heap *p)
{
	if(isempty(p))
	{
		printf("The heap is empty!");
		return;
	}
	int item = p->data[1], x = p->data[p->size--];
	int parament, child;
	for(parament = 1; 2*parament <= p->size; parament = child)
	{
		child = 2*parament;
		if(child != p->size && p->data[child] > p->data[child+1]) child++;
		if(x <= p->data[child]) break;
		else p->data[parament] = p->data[child];
	}
	p->data[parament] = x;
	return item;
}

void predown(heap *p, int n)
{
	int x = p->data[n];
	int parament, child;
	for(parament = n; parament*2 <= p->size; parament = child)
	{
		child = 2*parament;
		if(child != p->size && p->data[child] > p->data[child+1]) child++;
		if(p->data[child] >= x) break;
		else p->data[parament] = p->data[child]; 
	}
	p->data[parament] = x;
}

heap* buildheap(heap *p)
{
	int i;
	for(i = p->size; i > 0; i--)
	{
		predown(p, i);
	}
	return p;
}
