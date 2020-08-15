#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char used[10000], u[10000];
int r,l[1000],i,j,k,m,n,c;
int N; int C;
int Q;
main(int argc, char**argv){
   N = atoi(argv[1]);
   C = atoi(argv[2]);
   Q = atoi(argv[3]);

while(Q--){
   memset(used,0,sizeof(used));
   printf("%d %d\n",N,C);
   for (i=0;i<N;i++) {
      for(r=random()%10000;used[r];r=random()%10000);
      l[i] = r; used[r] = 1;
   }
   for (i=0;i<N;i++) {
     if (i) printf(" ");
     printf("%04d",l[i]);
   }
   printf("\n");
   for (k=0;k<C;k++) {
     n = random()%N + 1;
     m = random()%(n+1);
     printf("%d %d",n,m);
     memset(u,0,sizeof(u));
     for (i=0;i<n;i++) {
        if (random()%100) for (r=l[random()%N];u[r];r=l[random()%N]);
        else for (r=random()%10000;u[r];r=random()%10000);
        u[r] = 1;
        printf(" %04d",r);
     }
     printf("\n");
   }
}
   printf("0\n");
}
