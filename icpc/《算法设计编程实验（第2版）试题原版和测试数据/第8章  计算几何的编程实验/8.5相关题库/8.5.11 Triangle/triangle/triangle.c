#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GCF(int n, int m) {
  int q;

  if (n==1 || m==1)
    return 1;
  
  if (n==0)
    return m;
  else {
   q = m/n;
   return GCF(m-q*n, n);
  }
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  int x21, y21, x31, y31;
  double slope21, slope31, slope32;
  int doubleArea;
  int num21, num31, num32;
  double x, y;
  int xInt, yInt, yInt2;
  int total;
  
  while (1) {
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0)
      break;
    x21 = x2-x1;
    y21 = y2-y1;
    x31 = x3-x1;
    y31 = y3-y1;
    doubleArea = abs(x21*y31-x31*y21);
    //printf("%d\n", doubleArea);
    
    if (x2 == x1) 
      num21 = abs(y2-y1)+1;
    else if (y2 == y1)
      num21 = abs(x2-x1)+1;
    else {
      num21 = GCF(abs(x2-x1), abs(y2-y1))+1;
      /*
      slope21 = ((double) (y2-y1))/((double) (x2-x1))*10000.0;
      num21 = 0;
      if (x1 < x2) {
	for (x=x1; x<=x2; x=x+1.0) {
	  y = slope21*x;
	  yInt = (int) y;
	  yInt2 = yInt+1;
	  //printf("%lf %d %d\n", y, yInt, yInt2);
	  if (fabs(y-(double) yInt) < 0.000001 || fabs(y-(double) yInt2) < 0.000001)
	    num21++;
	}
      }
      else {
	for (x=x2; x<=x1; x=x+1.0) {
          y = slope21*x;
          yInt = (int) y;
          yInt2 = yInt+1;
          if (fabs(y-(double) yInt) < 0.000001 || fabs(y-(double) yInt2) < 0.000001)
            num21++;
        }
      }
      */
    }
    
    //printf("%d\n", num21);
    
    if (x3 == x1)
      num31 = abs(y3-y1)+1;
    else if (y3 == y1)
      num31 = abs(x3-x1)+1;
    else {
      //printf("%d %d\n", abs(x3-x1), abs(y3-y1));
      num31 = GCF(abs(x3-x1), abs(y3-y1))+1;
      //printf("%d\n", num31);
      /*
      slope31 = ((double) (y3-y1))/((double) (x3-x1))*10000.0;                                                                            
      num31 = 0;
      if (x1 < x3) {
	for (x=x1; x<=x3; x=x+1.0) {
	  y = slope31*x;
	  yInt = (int) y;
	  yInt2 = yInt+1;
	  if (fabs(y-(double) yInt) < 0.000001 || fabs(y-(double) yInt2) < 0.000001)
	    num31++;
	}
      }
      else {
	for (x=x3; x<=x1; x=x+1.0) {
          y = slope31*x;
          yInt = (int) y;
          yInt2 = yInt+1;
          if (fabs(y-(double) yInt) < 0.0001 || fabs(y-(double) yInt2) < 0.0001)
            num31++;
        }
      }
      */
    }

    //printf("%d\n", num31);

    if (x3 == x2)
      num32 = abs(y3-y2)+1;
    else if (y3 == y2)
      num32 = abs(x3-x2)+1;
    else
      {
      num32 = GCF(abs(x3-x2), abs(y3-y2))+1; /*
      slope32 = ((double) (y3-y2))/((double) (x3-x2))*10000.0;
      num32 = 0;
      if (x2 < x3) {
	for (x=x2; x<=x3; x=x+1.0) {
	  y = slope32*x;
	  yInt = (int) y;
	  yInt2 = yInt+1;
	  if (fabs(y-(double) yInt) < 0.000001 || fabs(y-(double) yInt2) < 0.000001)
	    num32++;
	}
      }
      else {
        for (x=x3; x<=x2; x=x+1.0) {
          y = slope32*x;
          yInt = (int) y;
          yInt2 = yInt+1;
          if (fabs(y-(double) yInt) < 0.000001 || fabs(y-(double) yInt2) < 0.000001)
            num32++;
        }
      }
				 */
    }

    //printf("%d\n", num32);
  
    // printf("%lf %lf %lf\n", slope21, slope31, slope32);
    //printf("%d %d %d\n", num21, num31, num32);
    total = num21+num31+num32-3;
    printf("%d\n", (doubleArea-total)/2+1);
  }
  return 0;
}
