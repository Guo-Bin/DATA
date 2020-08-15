/* SWERC'97 - Video Surveillance */
/* 11/11/97 - Matthias Ruhl      */

#include <stdio.h>

#define MAXPOINTS 100

int px[MAXPOINTS+1],py[MAXPOINTS+1],n;

int solvable()
{
  int i,j;

  for(i=0;i<n;i++)
    for(j=i%2;j<n;j+=2)
      {
	if(px[i] == px[i+1])
	  {
	    if(px[i] < px[j] && py[i] > py[i+1] && py[j] < py[j+1]) return 0;
	  }
	else
	  {
	    if(py[i] > py[j] && px[i] > px[i+1] && px[j] < px[j+1]) return 0;
	  }
      }
  return 1;
}

int main()
{
  FILE *inp;
  int i,caseno = 1;

  inp = fopen("video.in","r");
  while(fscanf(inp,"%d",&n) && n != 0)
    {
      for(i=0;i<n;i++) fscanf(inp,"%d %d",px+i,py+i);
      px[n] = px[0]; py[n] = py[0];
      printf("Floor #%d\n",caseno++);
      if(solvable())
	printf("Surveillance is possible.\n\n");
      else
	printf("Surveillance is impossible.\n\n");
    }
  fclose(inp);
  return 0;
}
