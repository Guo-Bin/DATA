/* South-Western-European Regional Contest 1997
   Problem: Video Surveillance
   Author: Falk Bartels
 */
   
#include <stdio.h>

#define MAX( x, y) ((x)<(y)? (y): (x))
#define MIN( x, y) ((x)<(y)? (x): (y))
#define LEFT -1
#define INLINE 0
#define RIGHT 1
#define eps 0.000000001
#define SGN(x) ((x)<-eps?-1:(x)>eps?1:0)
#define DET(a,b,c,d) ((a)*(d)-(b)*(c))
#define CRAMER1(a,b,x,c,d,y) (DET(x,b,y,d)/DET(a,b,c,d))

#define MAXPOLY 105 

typedef struct { double x, y; } point;
typedef struct { point p[MAXPOLY]; int pnum;} polygon;

FILE *input;
polygon inpoly;


int readcase()
{
  int l, pnum;

  fscanf( input, "%d", &pnum);
  if (pnum==0) return 0;
  if (pnum<3 || pnum>100) { printf("invalid input\n"); exit(1);}

  inpoly.pnum=pnum;

  for (l=0; l< pnum; l++) {
    fscanf(input, "%lf %lf", &(inpoly.p[l].x), &(inpoly.p[l].y));
  }

  return 1; 
}


point intersection (point p0, point p1, point q0, point q1)
{
  double r = CRAMER1(p1.x-p0.x, q0.x-q1.x, q0.x-p0.x,
		     p1.y-p0.y, q0.y-q1.y, q0.y-p0.y);
  point p = {p0.x+r*(p1.x-p0.x), p0.y+r*(p1.y-p0.y)};
  return p;
}

int discriminate( point pt, point p1, point p2)
{
  point n = {p2.y-p1.y, p1.x-p2.x};
  point d = {pt.x-p1.x, pt.y-p1.y};
  double lambda = n.x*d.x+n.y*d.y;
  if (lambda>eps) return RIGHT;
  if (lambda<-eps) return LEFT;
  return INLINE;
}

polygon cut_conv( polygon conv, point p1, point p2)
{
  polygon newc;
  newc.pnum=0;

  if (conv.pnum==1) {
    if (discriminate( conv.p[0], p1, p2)!=LEFT) newc.p[newc.pnum++]=conv.p[0];

  } else if (conv.pnum>1) {

    int l, olddis, dis;

    olddis=discriminate( conv.p[conv.pnum-1], p1, p2);
    for (l=0; l < conv.pnum; l++) {
      dis=discriminate( conv.p[l], p1, p2);
      if ((dis==LEFT && olddis==RIGHT) ||
          (dis==RIGHT && olddis==LEFT)) {
	newc.p[newc.pnum++]=
	  intersection( conv.p[(l-1+conv.pnum) % conv.pnum], conv.p[l],
			p1, p2);
      }
      if (dis==INLINE || dis==RIGHT) { newc.p[newc.pnum++]=conv.p[l]; }
      olddis=dis;
    }
  }
  return newc;
}

void solvecase( int kase)
{
  int l;
  polygon kernal;
  double minx, maxx, miny, maxy;
  point p1, p2;

  printf( "Floor #%d\n", kase);

/* find extreme koordinates */

  minx=inpoly.p[0].x;
  maxx=inpoly.p[0].x;
  miny=inpoly.p[0].y;
  maxy=inpoly.p[0].y;

  for (l=1; l < inpoly.pnum; l++) {
    minx=MIN( minx, inpoly.p[l].x);
    maxx=MAX( maxx, inpoly.p[l].x);
    miny=MIN( miny, inpoly.p[l].y);
    maxy=MAX( maxy, inpoly.p[l].y);
  }

/* init kernal as surrounding rectangle */

  kernal.pnum=4;
  kernal.p[0].x=minx; kernal.p[0].y=miny;
  kernal.p[1].x=minx; kernal.p[1].y=maxy;
  kernal.p[2].x=maxx; kernal.p[2].y=maxy;
  kernal.p[3].x=maxx; kernal.p[3].y=miny;

/* compute intersection of halfspaces defined by the input-polygon */

  for (l=0; l < inpoly.pnum; l++) {
    p1=inpoly.p[l]; p2=inpoly.p[(l+1)%inpoly.pnum];
    kernal=cut_conv( kernal, p1, p2);
  }

/* output */

  /*
  if (kernal.pnum==0) printf( "No positioning possible.\n");
  else {
    printf( "Possible camera position: (%.1f, %.1f)\n",
	    kernal.p[0].x, kernal.p[0].y);
  }
  */
  if (kernal.pnum==0)
    printf( "Surveillance is impossible.\n");
  else 
    printf( "Surveillance is possible.\n");

  printf("\n");

}

int main()
{
  int kase = 0;

  if ((input = fopen( "video.in", "r"))==NULL) {
    printf("No Inputfile\n"); exit(1);
  }

  while (readcase()) solvecase( ++kase);

  fclose(input);
  return 0;
}
