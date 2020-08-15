#include <stdio.h>

int i,j,k,n;
double phi;

main(){
   while (1 == scanf("%d",&n) && n) {
      k = n;
      phi = n;
      for (i=2;i*i<=k;i++) {
         if (k%i == 0) {
            phi *= (1 - 1.0/i);
         }
         while (k%i == 0) k /= i;
      }
      if (k > 1) phi *= (1 - 1.0/k);
      printf("%0.0lf\n",phi);
   }
}

