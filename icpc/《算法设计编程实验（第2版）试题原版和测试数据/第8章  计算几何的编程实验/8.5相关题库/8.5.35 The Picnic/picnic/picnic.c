/******************************************************************************
* Sample solution for the Picnic problem in NWERC 2002.
* Author: Andreas Björklund
*
* Compile with the define PRINT_SOLUTION for output of the indices of the
* obstacles on the circumference of the largest region in counterclockwise
* order. (If many obstacles on the same line, some of the inbetween ones may
* be omitted though.)
*
*  y
*  ^
*  |
*  +---> x
* Time complexity O(n^3) where n is the number of obstacles.
******************************************************************************/
#include <stdio.h>

#define CROSSDOT(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define LENGTH(x1,y1) ((x1)*(x1)+(y1)*(y1))

#define MAX_NBR_DOTS (100)

int x[MAX_NBR_DOTS];
int y[MAX_NBR_DOTS];
int sx[MAX_NBR_DOTS];
int sy[MAX_NBR_DOTS];
int perm[MAX_NBR_DOTS];
int tri[MAX_NBR_DOTS][MAX_NBR_DOTS];
int wit[MAX_NBR_DOTS][MAX_NBR_DOTS];
int nam[MAX_NBR_DOTS][MAX_NBR_DOTS];

int bestArea;

int solcnt;
int sol[MAX_NBR_DOTS];

void clearTri(int m)
{
  int i,j;
  for (i=0;i<m;i++)
    for (j=i+1;j<m;j++)
    {
      tri[j][i] = 0;
      wit[j][i] = -1;
      nam[j][i] = i;
    }
}
        
int sort(int who,int m)
{
  int i,j,k,p,dist,xx,yy;
  p=0;
  for (i=0;i<m;i++)
    if (i!=who)
    {
      if (y[i]<y[who] || ((y[i]==y[who]) && (x[i]<x[who])))
      {
        yy=y[i]-y[who];
        xx=x[i]-x[who];
        j=0;dist=LENGTH(xx,yy);
        while (j<p && CROSSDOT(xx,yy,sx[j],sy[j])>0) j++;
        while (j<p && CROSSDOT(xx,yy,sx[j],sy[j])==0 && LENGTH(sx[j],sy[j])<dist) j++;
        for (k=p;k>j;k--)
        {
          sx[k]=sx[k-1];
          sy[k]=sy[k-1];
          perm[k]=perm[k-1];
        }
        sx[j]=xx;
        sy[j]=yy;
        perm[j]=i;
        p++;
      }
    }
  return p;      
}

void sweep(int who, int m)
{
  int i,j,k,s,t,update;
  int area;
  clearTri(m);
  for (i=1;i<m;i++)
  {
    j=i-1;
    while (j>=0 && CROSSDOT(sx[j],sy[j],sx[i],sy[i])==0) j--;
    update=(j==i-1);
    while (j>=0)
    {
      k=j-1;
      while (k>=0 && CROSSDOT(sx[k]-sx[j],sy[k]-sy[j],sx[j]-sx[i],sy[j]-sy[i])>0) k--;
      area=CROSSDOT(sx[i],sy[i],sx[j]-sx[i],sy[j]-sy[i]);
      if (k>=0)
      {
        wit[i][j]=nam[j][k];
        area += tri[j][k];
      }
      if (update) tri[i][j]=area;
      if (area>bestArea)
      {
        bestArea=area;
        sol[0]=who;
        sol[1]=perm[i];
        sol[2]=perm[j];
        s=i;
        t=j;
        solcnt=3;
        while (wit[s][t]!=-1)
        {
          sol[solcnt]=wit[s][t];
          s=t;
          t=sol[solcnt];
          sol[solcnt]=perm[sol[solcnt]];
          solcnt++;
        }
      }
      if (!update) wit[i][j]=-1;
      j=k;
    }
    if (update)
      for (k=1;k<i;k++)
        if (tri[i][k]<tri[i][k-1])
        {
          nam[i][k] = nam[i][k-1];
          tri[i][k] = tri[i][k-1];
          wit[i][k] = wit[i][k-1];
        }
  }
}

int solve(int m)
{
  int i, p;
  bestArea = 0;
  for (i=0;i<m;i++)
  {
    p=sort(i,m);
    sweep(i,p);
  }
  return bestArea;
}

int main(void)
{
  int n,m,i,j;
  freopen("e.in","r",stdin);
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
    scanf("%d",&m);
    for (j=0;j<m;j++)
    {
      scanf("%d %d",&x[j],&y[j]);
    }  
    printf("%0.1f\n",(float)solve(m)/2);
    #ifdef PRINT_SOLUTION
    printf("Sol:");
    for (j=0;j<solcnt;j++)
      printf("%d ",sol[j]);
    printf("\n");  
    #endif
  }
  return 0;
}









