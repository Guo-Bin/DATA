#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>

#define y1 Y1

#define T double  // long double if you need exact for ints > 10^7

using namespace std;

struct point { 
   T x,y;
   point () { x=y=0; }
   point (T xx, T yy) { x=xx; y = yy; }
};

int strictcross(point p1, point p2, point p3, point p4) {
    T a, b, c, d;
    a=(p3.y-p2.y)*(p1.x-p2.x)-(p1.y-p2.y)*(p3.x-p2.x);
    b=(p4.y-p2.y)*(p1.x-p2.x)-(p1.y-p2.y)*(p4.x-p2.x);
    c=(p1.y-p4.y)*(p3.x-p4.x)-(p3.y-p4.y)*(p1.x-p4.x);
    d=(p2.y-p4.y)*(p3.x-p4.x)-(p3.y-p4.y)*(p2.x-p4.x);
    return a*b<0 && c*d<0;
}

int i,j,k,m,n;
double x1[100000], x2[100000], Y1[100000], y2[100000];
int me[100000];
char covered[100000];

int main(){
   while (1 == scanf("%d",&n) && n) {
      memset(covered,0,n);
      for (m=i=0;i<n;i++,m++) {
         scanf("%lf%lf%lf%lf",&x1[m],&Y1[m],&x2[m],&y2[m]);
         me[m] = i+1;
         for (k=m-1;k>=0;k--) {
            if (strictcross(point(x1[m],y1[m]),point(x2[m],y2[m]),
                            point(x1[k],y1[k]),point(x2[k],y2[k]))){
               for (j=k;j<m;j++) {
                  x1[j] = x1[j+1]; y1[j] = y1[j+1];
                  x2[j] = x2[j+1]; y2[j] = y2[j+1];
                  me[j] = me[j+1];
               }
               m--;
            }
            
         }
      }
      printf("Top sticks:");
      for (i=0;i<m-1;i++) printf(" %d,",me[i]);
      printf(" %d.\n",me[m-1]);
   } 
   return 0;
}
