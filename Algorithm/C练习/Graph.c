#include <stdio.h>
#include <stdlib.h>
#define maxvertexnum 10

typedef struct gnode{
	int nv;
	int ne;
	int gra[maxvertexnum][maxvertexnum];
	int vnode[maxvertexnum];
} graph;

typedef struct enode{
	int v, w;
	int weight;
} edge;

graph* creategraph(int vertex);
void insertedge(graph *g, edge *e);
graph* buildgraph();
void DFS(graph *g, int v1);

int main()
{
	graph *test = buildgraph();
	int vnumber;
	printf("Input the v1:\n");
	scanf("%d", &vnumber);
	DFS(test, vnumber);
	return 0;
}

graph* creategraph(int vertex)
{
	graph *g = (graph*)malloc(sizeof(graph));
	g->nv = vertex;
	g->ne = 0;
	for(int j = 0; j < vertex; j++)
		for(int k = 0; k < vertex; k++)
			g->gra[j][k] = 0;                /* 初始化矩阵，没有边但至少有一个顶点的图 */ 
	for(int j = 0; j < vertex; j++)
		g->vnode[j] = 0;
	return g;
}

void insertedge(graph *g, edge *e)
{
	g->gra[e->v][e->w] = 1;
	g->gra[e->w][e->v] = 1;  /* 无向图时有这一步 */ 
}

graph* buildgraph()
{
	int nv, ne0;
	int v1, w1;
	edge *e;
	printf("Input the number of the vertex:\n");
	scanf("%d", &nv);
	graph *g = creategraph(nv);
	printf("Input the number of the edge:\n");
	scanf("%d", &ne0);
	g->ne = ne0;
	if(g->ne != 0)                          /* 边数为零时直接返回 */ 
	{
		e = (edge*)malloc(sizeof(edge));
		for(int i = 0; i < ne0; i++)
		{
			printf("Input the v and w:\n");
			scanf("%d%d", &v1, &w1);
			e->v = v1; e->w = w1;          /* 在此处输入权重 */ 
			insertedge(g, e);
		}
	}
	return g;
}

/* 深度优先搜索 DFS */

void DFS(graph *g, int v1)
{
	g->vnode[v1] = 1;
	printf("Yes!\t");
	for(int i = 0; i < g->nv; i++)
	{
		if(g->gra[v1][i] != 0)
			if(g->vnode[i] != 1)
				DFS(g, i);
	}
}


