/*

1995-96 ACM International Collegiate Programming Contest
Southwestern European Regional Contest
ETH Zurich, Switzerland
December 9, 1995


Problem: Coloring

Idea:			Andreas Wolf, ETH Zurich
Implementation:	Manuel Bleichenbacher, Head Judge

Analyzes the problem output against a sample solution.
The coloring must have the same number of black nodes
and the coloring must be legal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


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


int main(int argc, char* argv[])
{
	int nGraphs, nEdges;
	FILE *fin, *fsol, *fout;
	int dummy;
	int i, j;
	int from, to;
	int nExpectedBlackNodes;
	Coloring coloring;
	
	fin = fopen("coloring.in", "r");
	assert( fin != 0 );
	
	fsol = fopen("coloring.sol", "r");
	assert( fsol != 0);
	
	fout = fopen("coloring.out", "r");
	assert( fout != 0);
	
	dummy = fscanf(fin, "%d", &nGraphs);
	assert( dummy == 1 );
	
	while (nGraphs > 0) {
		nGraphs--;
		
		/* read parameters */
		dummy = fscanf(fin, "%d %d", &nNodes, &nEdges);
		assert( dummy == 2 );
		assert( nNodes < MaxNode );
		
		printf("%d nodes, %d edges.\n", nNodes, nEdges);
		
		/* initalize graph */
		coloring.nBlack = 0;
		coloring.nWhite = 0;
		for (i=1; i <= nNodes; i++) {
			coloring.node[i] = eUnassigned;
			for (j=1; j <= nNodes; j++)
				edge[i][j] = FALSE;
		}
		
		/* read in graph */
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
		
		/* read in expected values */
		dummy = fscanf(fsol, "%d", &nExpectedBlackNodes);
		assert( dummy == 1 );
		for (i = 0; i < nExpectedBlackNodes; i++) {
			dummy = fscanf(fsol, "%d", &j);
			assert( dummy == 1 );
		}
		
		/* compare number of black nodes */
		dummy = fscanf(fout, "%d", &i);
		if (dummy != 1) {
			printf("Error or unexpected end-of-file in coloring.out.\n");
			printf("WRONG OUTPUT.\n");
			exit(0);
		}
		if (i != nExpectedBlackNodes) {
			printf("Number of black nodes differs:\n");
			printf("Black nodes: %d (should be %d).\n", i, nExpectedBlackNodes);
			printf("WRONG OUTPUT.\n");
			exit(0);
		}
		
		/* check user's coloring */
		while (nExpectedBlackNodes > 0) {
			dummy = fscanf(fout, "%d", &i);
			if (dummy != 1)
				break;
				
			if (coloring.node[i] != eUnassigned)
				break;
			coloring.nBlack++;
			for (j = 1; j <= nNodes; j++) {
				if (edge[i][j]) {
					if (coloring.node[j] == eUnassigned) {
						coloring.node[j] = eWhite;
						coloring.nWhite++;
					} else if (coloring.node[j] == eBlack)
						break;
				}
			}
			if (j <= nNodes)
				break;
			nExpectedBlackNodes--;
		}
		if (dummy != 1) {
			printf("Error or unexpected end-of-file in coloring.out.\n");
			printf("WRONG OUTPUT.\n");
			exit(0);
		}
		if (nExpectedBlackNodes != 0) {
			printf("Invalid graph coloring.\n");
			printf("WRONG OUTPUT.\n");
			exit(0);
		}
	}
	
	printf("PROGRAM ACCEPTED.\n");
	
	fclose(fin);
	fclose(fout);
	fclose(fsol);
	
	return 0;
}

