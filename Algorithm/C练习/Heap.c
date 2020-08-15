#include <stdio.h>
#include <stdlib.h>

#define maxdata 99999

typedef struct node{
	 int *data;
	 int size;  // the current number of the array data
	 int capacity; // the max number of the array
} heap;

heap* createheap(int maxsize);
int isfull(heap *p);
int isempty(heap *p);
void insert(heap *p, int x);
int deleteheap(heap *p);
void adjustmaxheap(heap *p, int n);
void buildheap(heap *p);

int main()
{
	int n;
	printf("Input the max size:\n");
	scanf("%d", &n);
	heap *root = createheap(n);
	int x;
	printf("Input the number of the datas:\n");
	scanf("%d", &x);
	for(int i = 0; i < x; i++)
	{
		int number;
		printf("Input the number:\n");
		scanf("%d", &number);
		insert(root, number);
	}
	
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
	for( ; p->data[i/2] < x; i/=2)
	{
		p->data[i] = p->data[i/2];
	}
	p->data[i] = x;
}

int deleteheap(heap *p) // from the top to the bottom
{
	if(isempty(p))
	{
		printf("The heap is empty!");
		return;
	}
	int item = p->data[1];
	int x = p->data[p->size--];
	int child, parament;
	for(parament = 1; parament*2 <= p->size; parament = child)
	{
		child = 2*parament;
		if(child != p->size && p->data[child] < p->data[child+1]) child++;
		if(p->data[child] <= x) break;
		else p->data[parament] = p->data[child];
	}
	p->data[parament] = x;
	return item;
}

// build the max heap
void adjustmaxheap(heap *p, int n)
{
	int x = p->data[n];
	int child, parament;
	for(parament = 1; parament*2 <= p->size; parament = child)
	{
		child = 2*parament;
		if(child != p->size && p->data[child] < p->data[child+1]) child++;
		if(x >= p->data[child]) break;
		else p->data[parament] = p->data[child];
	}
	p->data[parament] = x;
}

void buildheap(heap *p)
{
	int i;
	for(i = p->size; i > 0; i--)
	{
		adjustmaxheap(p, i);
	}
}
