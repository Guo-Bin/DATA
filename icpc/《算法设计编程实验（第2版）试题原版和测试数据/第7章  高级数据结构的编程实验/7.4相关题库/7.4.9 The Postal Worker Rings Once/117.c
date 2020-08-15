#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

/*************************************************
 problem 6 : 1992 Duke Internet Programming Contest
 written by: Owen Astrachan

 in its original incarnation this problem required that
 a minimal path be printed as well as the minimal path's
 length.  As a result, there is some extra code and
 extra data structures in this problem.
*************************************************/



#define MAX_VERT	28
#define INFINITY        1000000
#define DEAD_END        "deadend"

#define char2int(x)	(x - 'a')
#define int2char(x)     ('a' + x)
#define checkused(x,y)  ((x) < (y) ? used[(x)][(y)] : used[(y)][(x)])

typedef struct dl{
    int info;
    struct dl *next, *prev;
} node;

int v[MAX_VERT][MAX_VERT];
int shorty[MAX_VERT][MAX_VERT];
int nv;
int firstVert;
int edgeSum;

int numEdges[MAX_VERT];
    
int ReadGraph(void);
void FloydShort(void);
void Augment(void);

int
main()
{

    while (ReadGraph() && !feof(stdin)){
	FloydShort();
	Augment();
	printf("%d\n",edgeSum);
	edgeSum = 0;	
    }

    return(1);
}

int
ReadGraph()
{
    char buf[BUFSIZ];
    
    int i,j;
    for(i=0;i<MAX_VERT;i++){
	for(j=0;j<MAX_VERT;j++){
	    v[i][j] = INFINITY;
	}
	numEdges[i] = 0;
    }

    firstVert = INFINITY;

    buf[0] = '\0';  /* make buf initially empty */
    
    while ((gets(buf) != NULL) && strcmp(buf,DEAD_END) != 0){
	i = char2int(buf[0]);
	j = char2int(buf[strlen(buf)-1]);
	if (i < firstVert)
	    firstVert = i;
	if (j < firstVert)
	    firstVert = j;
	v[i][j] = v[j][i] = strlen(buf);
	edgeSum += v[i][j];
	numEdges[i]++;
	numEdges[j]++;
    }

    return firstVert != INFINITY;
}

void
FloydShort()
{
    int i,j,k;

    for(i=0;i<MAX_VERT;i++)
	for(j=0;j<MAX_VERT;j++)
	    shorty[i][j] = v[i][j];

    for(i=0;i<MAX_VERT;i++)
	shorty[i][i] = 0;

    for(k=0;k<MAX_VERT;k++)
	for(i=0;i<MAX_VERT;i++)
	    for(j=0;j<MAX_VERT;j++)
		if (shorty[i][k] + shorty[k][j] < shorty[i][j]){
		    shorty[i][j] = shorty[i][k] + shorty[k][j];
		}
}

void
Augment()
{
    int i,count;
    int odds[MAX_VERT];
    
    count = 0;
    for(i=0;i<MAX_VERT;i++)
	if (numEdges[i] % 2 == 1){
	    odds[count++] = i;
	}

    if (count == 2){
	edgeSum += shorty[odds[0]][odds[1]];
    }
    else if (count != 0){
	fprintf(stderr,"error, %d odd vertices\n",count);
    }
}
