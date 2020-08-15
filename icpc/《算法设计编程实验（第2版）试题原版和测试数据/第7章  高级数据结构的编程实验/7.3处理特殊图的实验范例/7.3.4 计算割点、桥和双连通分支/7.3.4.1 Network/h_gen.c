#include <stdio.h>
#include <stdlib.h>

int e[128][128];
int comp[128];
int f[128];

void compress(int i)
{
	int l,p=i;	
	while(comp[i]!=i)i=comp[i];	
	while(p!=i){ l=p; p=comp[p]; comp[l]=i; }
}

int xrand(int deg, int n)
{
	while(deg--) n = 1+(rand()%n);
	return n-1;
}	
	
void main()
{	
	int i, j, x, y, m, n, o, cm, t;

	for(t = 0; t < 200; t++)
	{
again0:	
		n = 2 + rand() % 98;
		
		for(i = 0; i < n; i++)
			comp[i] = i;
		
		m = 0; 
		cm = n;
			
		for(;;)
		{
		again1:
			x = rand() % n;
			
			for(i = 0; i < m; i++)
				if(f[i] == x) goto again1;
			
			f[m] = x;
			
			o = 1 + xrand(6,n-1);
			e[m][0] = o;
			
			for(i = 1; i <= o; i++)
			{
			again2:
				y = rand() % n;
				if(x == y) goto again2;
				
				for(j = 1; j < i; j++)
					if(e[m][j] == y) goto again2;
				
				e[m][i] = y;
				
				compress(x);
				compress(y);
				
				if(comp[x] != comp[y])
				{
					comp[comp[x]] = comp[y];
					cm--;
				}
			}
			
			m++;			
			if(cm == 1) break;			
			if(m >= n) goto again0;
		}
		
		printf("%d\n", n);

		for(i = 0; i < m; i++)
		{
			printf("%d ", f[i]+1);
		
			for(j = 1; j <= e[i][0]; j++)
				printf("%d%c", e[i][j]+1,
					(j == e[i][0]) ? '\n' : ' '); 
		}
		
		printf("0\n");
	}
	
	printf("0\n");
}
