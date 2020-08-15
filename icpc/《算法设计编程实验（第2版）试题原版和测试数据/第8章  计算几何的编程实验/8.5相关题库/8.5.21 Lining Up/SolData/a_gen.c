#include <stdlib.h>
#include <stdio.h>


int randx(int max,int mask)
{
    int k;
    max--;
    while((k=(rand() & mask))>max);
    return k+1;
}

void print_one_problem(int N)
{
    int i,x1,y1;
    int sx,sy,k;
    int x[1024],y[1024];
    
    printf("%i\n", N);
    k=0;
    for(i=1;i<=N;i++){
       if(!k){
          k=randx(randx(randx(62,63),63),63);
/*        printf("# %i\n",k);*/
          sx=50-randx(100,127);
          sy=50-randx(100,127);
          x1 = 16000-randx(32000,0x7fff);
          y1 = 16000-randx(32000,0x7fff);
       }
       x1+=sx;
       y1+=sy;
       k--;
       x[i]=x1;y[i]=y1;
    }

    for(i=1;i<=N;i++){   /* shake it */
      x1=randx(N,1023);
      k=x[x1];x[x1]=x[i];x[i]=k;      
      k=y[x1];y[x1]=y[i];y[i]=k;      
    }

    for(i=1;i<=N;i++)printf("%i %i\n",x[i],y[i]);

    printf("\n");

}

void main()
{
	int i;
	i= 50;
	while(i--)
	{
		print_one_problem(randx(700,1023));
	}
	printf("0\n");
}


