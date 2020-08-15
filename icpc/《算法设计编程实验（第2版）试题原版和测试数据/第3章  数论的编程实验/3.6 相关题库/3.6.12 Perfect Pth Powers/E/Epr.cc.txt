#include <stdio.h>
#include <math.h>

int main () {
  while (1) {
    long long int m, nn, b;
    int n, e;
    scanf("%d", &n);
    if (!n) break;
    // when n == INT_MIN then -n overflows (of course)
    nn = n;
    if (nn < 0) nn = -nn;
    int E = 0;
    for (b = 2; b*b <= nn ; b++) {
      m = b;
      for(e = 2; m <= nn; e++) {
	m = m*b;
	if (m == nn && (n > 0 || e%2)) {
	  E = e;  goto A;
	}
      }
    }
  A: printf("%d\n", E ? E : 1);
  }
}
