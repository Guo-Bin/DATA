#include<stdio.h>
#include<stdlib.h>
#define rnd(p) (random()%(p))
#define N 50
int i,j,k;
int main() {
 for (i=0; i<N; i++) {
	j=2+rnd(14);
	printf("%d\n",j);
	for (k=0; k<j; k++)
		printf("%4d%4d%4d%4d\n",-50+rnd(101),-50+rnd(101),rnd(500),rnd(100));
	}
 printf("0\n");
 return 0;
 }
