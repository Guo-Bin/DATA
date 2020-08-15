#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

using namespace std;

#define EPS 1E-8

#define MAXN 100000

typedef struct {
  double x, y;
} Point;

Point pa[MAXN+10], pb[MAXN+10];

int intersect_line(Point a, Point b, Point c, Point d){
  Point t; double r, s, denom, num1, num2;

  num1  = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2  = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

  if (fabs(denom) >= EPS) {
    r = num1 / denom;
    s = num2 / denom;
    if (0-EPS <= r && r <= 1+EPS && 0-EPS <= s && s <= 1+EPS) 
      return 1;
    return 0;
  }
  if (fabs(num1) >= EPS) return 0;
  if (a.x > b.x || (a.x == b.x && a.y > b.y)) { t = a; a = b; b = t; }
  if (c.x > d.x || (c.x == d.x && c.y > d.y)) { t = c; c = d; d = t; }
  if (a.x == b.x) {
    if (b.y == c.y) return 1; 
    else if (a.y == d.y) return 1;
    else if (b.y < c.y || d.y < a.y) return 0;
  } else {
    if (b.x == c.x) return 1;
    else if (a.x == d.x) return 1;
    else if (b.x < c.x || d.x < a.x) return 0;
  }
  return -1;
}

int main () {
  while (1) {
    int n;
    scanf("%d",&n);
    if (!n) break;
    assert(1<=n && n <=MAXN);
    for(int i=1;i<=n;i++) {
      scanf("%lf%lf%lf%lf",&(pa[i].x),&(pa[i].y),&(pb[i].x),&(pb[i].y));
    }
    printf("Top sticks:");
    int first = 1;
    for (int i = 1;i<=n;i++) {
      for (int j = i+1;j<=n;j++) 
	if (intersect_line(pa[i],pb[i],pa[j],pb[j])) goto A;
      if (!first) printf(",");
      first = 0;
      printf(" %d",i);
    A:;
    }
    printf(".\n");
  }
}
