#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d[1001][10001];

int i,j,k,m,n,a,b;

main(int argc, char **argv){
   int N = atoi(argv[1]);
   int E = atoi(argv[2]);
   printf("%d %d\n",N,E);
   for (i=0;i<E;i++) {
      for (;;) {
         a = random()%N; b = random()%N;
         if (a == b || d[a][b] || d[b][a]) continue;
         d[a][b] = 1;
         printf("%d %d %d\n",1+a,1+b,1 + random()%10000);
         break;
      }
   }
   printf("0\n");
}
