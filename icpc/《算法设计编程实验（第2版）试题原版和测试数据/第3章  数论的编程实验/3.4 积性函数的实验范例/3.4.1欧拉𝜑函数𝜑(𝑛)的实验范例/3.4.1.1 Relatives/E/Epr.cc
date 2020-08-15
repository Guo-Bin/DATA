#include <stdio.h>
#include <math.h>
#include <assert.h>

int P[40000];
int Plen;

int D[50];

void Primes() {
  int i, j;
  P[0] = P[1] = 0;
  for (i = 2; i < 40000; i++) P[i] = i;
  for (i = 2; i <= 20001; i++) for (j = 2; i*j < 40000; j++) P[i*j] = 0;
  Plen = 0;
  for (i = 0; i < 40000; i++) if (P[i] != 0)  P[Plen++] = P[i];
}

void main () {
  int n, f[100], nof, p;
  Primes();
  while (scanf("%d", &n) == 1 && n) {
    if (n == 1) { printf("0\n"); continue; }
    nof = 0; p = n;
    for (int i = 0; i < Plen; i++) 
      if (!(n%P[i])) {
	f[nof++] = P[i];
	n /= P[i]; 
	while (!(p%P[i])) p /= P[i];
      }
    if (p > 1) f[nof++]	= p;
    n /= p;
    for (int i = 0; i < nof; i++) 
      n *= (f[i]-1);
    printf("%d\n",n);
  }
  if (n) printf("No endmarker!\n");
}
