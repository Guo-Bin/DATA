/* SWERC'97 - Box of Bricks */
/*  11/8/97 - Matthias Ruhl */

#include <stdio.h>

#define MAXSTACKS 50

FILE *inp;

int main()
{
  int i,k,n,sum,avgh,h[MAXSTACKS];
  int caseno = 1;

  inp = fopen("bricks.in","r");
  while(fscanf(inp,"%d",&n) && n != 0)
    {
      for(i=sum=0;i<n;i++)
	{
	  fscanf(inp,"%d",h+i);
	  sum += h[i];
	}
      if(sum%n) printf("Input error!\n");
      avgh = sum/n;
      for(i=k=0;i<n;i++)
	if(h[i] > avgh) k += h[i] - avgh;
      printf("Setting #%d\n",caseno++);
      printf("The minimum number of moves is %d.\n\n",k);
    }
  fclose(inp);
  return 0;
}
