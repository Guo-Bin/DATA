/*

1995-96 ACM International Collegiate Programming Contest
Southwestern European Regional Contest
ETH Zurich, Switzerland
December 9, 1995


Problem: Coloring

Idea and first implementation:	Andreas Wolf, ETH Zurich
Implementation:					Manuel Bleichenbacher, Head Judge

Source file: coloring.c / coloring.p
Input file: coloring.in
Output file: coloring.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef long int;

typedef enum {
	FALSE = 0,
	TRUE = 1
} bool;

typedef enum {
	eUnassigned,
	eWhite,
	eBlack
} Color;


#define MaxNode		101

typedef struct {
	int		nBlack, nWhite;
	Color	node[ MaxNode ];
} Coloring;

static int	nNodes;
static bool	edge[MaxNode][MaxNode];

static Coloring	bestColoring;
	

void color ( int firstNode, Coloring* coloring );



void color ( int firstNode, Coloring* coloring )
{
	int			i, j;
	Coloring	c;
	
	assert(firstNode <= nNodes+1);
	
	if (coloring->nWhite + coloring->nBlack == nNodes) {
		/* all nodes have a color; is it best coloring so far? */
		if (coloring->nBlack > bestColoring.nBlack)
			bestColoring = *coloring;
		return;
	}
	
	assert(firstNode <= nNodes);
	assert(coloring->nWhite + coloring->nBlack < nNodes);
	
	for ( i=firstNode; i <= nNodes; i++ ) {
		
		if ( coloring->node[i] == eUnassigned ) {
			c = *coloring;	/*local copy */
			c.nBlack++;
			c.node[i] = eBlack;
			for ( j=1; j <= nNodes; j++ )
				if ( edge[i][j] ) {
					if (c.node[j] == eBlack)
						break;
					else if (c.node[j] == eUnassigned) {
						c.node[j] = eWhite;
						c.nWhite++;
					}
				}
			
			if ( j > nNodes )
				if (nNodes - c.nWhite > bestColoring.nBlack)
				/* still possible to get a better coloring */
					color ( firstNode+1, &c );
		}
	}
}
			



int main(int argc, char* argv[])
{
	int nGraphs, nEdges;
	FILE *fin, *fout;
	int dummy;
	int i, j;
	int from, to;
	bool isFirst;
	Coloring coloring;

	fin = stdin;
	fout = stdout;

	dummy = fscanf(fin, "%d", &nGraphs);
	assert( dummy == 1 );
	
	while (nGraphs > 0) {
		nGraphs--;
		
		/* initalize */
		dummy = fscanf(fin, "%d %d", &nNodes, &nEdges);
		assert( dummy == 2 );
		assert( nNodes < MaxNode );
		
		bestColoring.nBlack = 0;
		bestColoring.nWhite = 0;
		for (i=1; i <= nNodes; i++) {
			bestColoring.node[i] = eUnassigned;
			for (j=1; j <= nNodes; j++)
				edge[i][j] = FALSE;
		}
		coloring = bestColoring;
			 
		while (nEdges > 0) {
			nEdges--;
			dummy = fscanf(fin, "%d %d", &from, &to);
			assert( dummy == 2 );
			assert( to != from );
			assert( to > 0 && to <= nNodes );
			assert( from > 0 && from <= nNodes );
			edge[from][to] = TRUE;
			edge[to][from] = TRUE;
		}
		
		color( 1, &coloring );
		
		isFirst = TRUE;
		fprintf(fout, "%d\n", bestColoring.nBlack );
		for (i=1; i <= nNodes; i++)
			if (bestColoring.node[i] == eBlack) {
				fprintf(fout, "%s%d", isFirst ? "" : " ", i);
				isFirst = FALSE;
			}
		fprintf(fout, "\n");
			
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}

