/* Solution to the Visit problem

   Jan Kybic, 20.10.2003

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define TOOBIG INT_MAX

int ncuts(int a,int b,int c,int d,int e,int f) ;

void do_solve(int a,int b,int c,int d,int e,int f)
     /* Try the four configurations to see which one is best */
{
  int x,m ;
  m=ncuts(a,b,c,d,e,f) ;
  if ((x=ncuts(b,a,c,d,e,f))<m) m=x ;
  if ((x=ncuts(a,b,d,c,e,f))<m) m=x ;
  if ((x=ncuts(b,a,d,c,e,f))<m) m=x ;
  if (m==TOOBIG)
    puts("The paper is too small.")  ;
  else
    printf("The minimum number of cuts is " 
           "%d.\n",m) ;
}

int ncuts(int a,int b,int c,int d,int e,int f) {
  /* How many cuts are needed in a specific configuration */
  // printf("a=%d b=%d c=%d d=%d e=%d f=%d\n",a,b,c,d,e,f) ;
  if (a*c>e || b*d>f) return TOOBIG ; /* sheet too big */
  // printf("    r=%d\n",a*b-1+(a*c<e)+(b*d<f)) ;
  return a*b-1+(a*c<e)+(b*d<f)  ;
}


int main()
{ int a,b,c,d,e,f ;
  for(;;) {
    a=0 ; b=0 ; c=0 ; d=0 ; e=0 ; f=0 ;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f) ;
    if (!a && !b && !c && !d && !e && !f) break ;
    do_solve(a,b,c,d,e,f) ;
  }
  return 0 ;
}


