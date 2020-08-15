#include <stdio.h>
#include <math.h>
#include <assert.h>

double lg2(double x) {
  return log(x)/log(2.0);
}


int main () {
  int a[30];
  a[2] = 3;
  double f = lg2(2)+lg2(3);
  for (int i=3; i<=22; i++) {
    a[i] = a[i-1];
    while(f+lg2(a[i]+1) < 1<<i) 
      f += lg2(++a[i]);
    //    printf("%d %d\n",i, a[i]);
  }
  while (1) {
    int n;
    scanf("%d",&n);
    if (!n) break;
    assert(1960 <= n && n <= 2160);
    printf("%d\n",a[n/10-196+2]);
  }
}
