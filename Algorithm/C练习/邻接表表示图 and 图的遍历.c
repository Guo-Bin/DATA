#include <stdio.h>
#include <stdlib.h>

typedef struct vnode{
	int adjv;
	int weight;
	struct vnode *next;
} adjlist;

/*typedef struct {
	ptrtoadjvnode *firstedge;
} adjlist; */

typedef struct {
	int nv;
	int ne;
	adjlist* *gra;
} graph;

graph* creategraph(int numvertex)
{
	graph *g = (graph*)malloc(sizeof(graph));
	g->ne = 0;
	g->nv = numvertex;
	for(int i = 0; i < numvertex; i++) g->gra[i] = NULL;
	return g;
}

void insertedge(graph *g, int Weight, int v1, int v2)
{
	adjlist *tmp = (adjlist*)malloc(sizeof(adjlist));
	tmp->adjv = v2;
	tmp->weight = Weight;
	tmp->next = g->gra[v1];
	g->gra[v1] = tmp->next;
	/* 若是无向图， 则再插入v2到v1的边 */
	adjlist *temp = (adjlist*)malloc(sizeof(adjlist));
	temp->adjv = v1;
	temp->weight = Weight;
	temp->next = g->gra[v2];
	g->gra[v2] = temp->next;
}



 
