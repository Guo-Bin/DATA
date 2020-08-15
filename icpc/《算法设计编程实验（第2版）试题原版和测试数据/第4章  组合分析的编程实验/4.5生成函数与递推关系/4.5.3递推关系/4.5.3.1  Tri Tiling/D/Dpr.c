#include <stdio.h>
#include <assert.h>

/*  In how many ways can one tile a 3xn board with 2x1 tiles,
 *   up to 30 
 *   Impossible when n is odd
 *   a[n] = 3*a[n-2] + 2*a[n-4] + 2*a[n-6] + ... + 2*a[0]
 *   which yields a[n] = 4*a[n-2] - a[n-4], a[0] = 1, a[2] = 3
 */

int main () {
  int i, n;
  unsigned long long int a1, a2, a;
  while (scanf("%d", &n) == 1) {
    assert (n <= 30);
    if (n%2) {
      printf("0\n");
      continue;
    }
    if (!n) {
      printf("1\n");
      continue;
    }
    if (n == 2) {
      printf("3\n");
      continue;
    }
    a2 = 1; a1 = 3;
    for (i = 4; i <= n; i += 2) {
      a = 4*a1-a2;
      a2 = a1;
      a1 = a;
    }
    printf("%llu\n", a);

  }
  return 0;
}
