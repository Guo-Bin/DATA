#include <stdio.h>

/* brute force */

gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b,a%b);
}

main(){
   int n,i,sum;
   while (1 == scanf("%d",&n) && n) {
      sum = 0;
      for (i=1;i<n;i++) if (gcd(i,n) == 1) sum++;
      printf("%d\n",sum);
   }
}
