#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
#define maxdata 9999

typedef struct {
	int *data;
	int size;
	int capacity;
} heap;

typedef struct vnode{
	int adjv;
	//int weight;
	struct vnode *next;
} adjlists;

typedef struct {
	int nv;
	int ne;
	adjlists* gra[];
} graph;

typedef struct {
	int front;
	int rear;
	int array[];
} queue;

void unweight(graph *g, int *dist, int *path, int vertex);
int deletenode(heap *h);
void insert(heap *h, int number);
heap* createheap();
int isfull(heap *h);
int isempty(queue *q);
int outqueue(queue *q);
void inqueue(queue *q, int p);
queue* createqueue();
graph* buildadjlist();
void insertedge(graph *g, int v1, int v2);
graph* creategraph(int NV);

int main()
{
	int nv;
	graph *test = buildadjlist();
	printf("Input the nv:\n");
	scanf("%d", &nv);
	int dist[nv]; int path[nv];
	for(int i = 0; i < nv; i++)
	{
		dist[i] = -1; path[i] = -1;
	}
	int vertex;
	printf("Input the vertex (the sourse vertex):\n");
	scanf("%d", &vertex);
	dist[vertex] = 0;
	
	unweight(test, dist, path, vertex);
	
	for(int j = 0; j < nv; j++) printf("%d\t", path[j]);
	return 0;
}

graph* creategraph(int NV0)
{
	graph *g = (graph*)malloc(sizeof(graph));
	g->nv = NV0;
	g->ne = 0;
	for(int i = 0; i < g->nv; i++) g->gra[i] = NULL;
	return g;
}

void insertedge(graph *g, int v1, int v2)  /* ÓÐÏòÍ¼²åÈë±ß */ 
{
	adjlists *e = (adjlists*)malloc(sizeof(adjlists));
	//e->weight = weight0;
	e->adjv = v2;
	e->next = g->gra[v1];
	g->gra[v1] = e;
}

graph* buildadjlist()
{
	int nv0;
	printf("Input the number of the vnode:\n");
	scanf("%d", &nv0);
	graph *t = creategraph(nv0);
	int ne0;
	printf("Input the number of the edges:\n");
	scanf("%d", &ne0);
	for(int i = 0; i < ne0; i++)
	{
		int v1, v2;
		printf("Input the v1, v2:\n");
		scanf("%d%d", &v1, &v2);
		insertedge(t, v1, v2);
	}
	return t;
}

queue* createqueue()
{
	queue *q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = -1;
	return q;
}

void inqueue(queue *q, int p)
{
	if((q->rear+1)%maxsize == q->front)
	{
		printf("The queue is full!\n");
		return; 
	}
	q->rear = (q->rear+1)%maxsize;
	q->array[q->rear] = p;
}

int outqueue(queue *q)
{
	if(q->rear == q->front)
	{
		printf("The queue is empty!\n");
		return;
	}
	q->front = (q->front+1)%maxsize;
	return q->array[q->front];
}

int isempty(queue *q)
{
	return (q->front == q->rear);
}

int isfull(heap *h)
{
	return (h->size == h->capacity);
}

heap* createheap()
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->size = 0;
	h->capacity = maxdata;
	h->data[0] = maxdata;
	return h;
}

void insert(heap *h, int number)
{
	if(isfull(h))
	{
		printf("The heap is full!\n");
		return;
	}
	int i = ++h->size;
	for( ; h->data[i/2] < number; i/=2)
	{
		h->data[i] = h->data[i/2];
	}
	h->data[i] = number;
}

int deletenode(heap *h)
{
	if(isempty(h))
	{
		printf("The heap is empty!\n");
		return;
	}
	int item = h->data[1]; int x = h->data[h->size--];
	int parament, child;
	for(parament = 1; 2*parament < h->size; parament = child)
	{
		child = 2*parament;
		if(2*child != h->size && h->data[child] > h->data[child+1]) child++;
		if(h->data[child] >= x) break;
		else h->data[parament] = h->data[child];
	}
	h->data[parament] = x;
	return item;
}

void unweight(graph *g, int *dist, int *path, int vertex)
{
	adjlists *p;
	queue *q = createqueue();
	inqueue(q, vertex);
	while(!isempty(q))
	{
		int tmp = outqueue(q);  //printf("%d\t", tmp);
		for(adjlists *temp = g->gra[tmp]; temp != NULL; temp = temp->next)
		{
			if(dist[temp->adjv] == -1)
			{
				dist[temp->adjv] = dist[tmp]+1;
				path[temp->adjv] = tmp;
				inqueue(q, temp->adjv);
			}
		}
	}
}
