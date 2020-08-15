#include <stdio.h>
#include <stdlib.h>

char *play(int x){
   int q = random();
   if (q%6 <= x%3) return "rock";
   if (q%6 <= x%4) return "scissors";
   return "paper";
}

main(int argc, char **argv){
   int i,j,k,n,m;
   n = atoi(argv[1]);
   k = atoi(argv[2]);

   printf("%d %d\n",n,k);
   for (i=0;i<n;i++) {
      for (j=0;j<k;j++) {
         for (m=i+1;m<n;m++){
            printf("%d %s %d %s\n",i+1,play(i),m+1,play(m));
         }
      }
   }
}
