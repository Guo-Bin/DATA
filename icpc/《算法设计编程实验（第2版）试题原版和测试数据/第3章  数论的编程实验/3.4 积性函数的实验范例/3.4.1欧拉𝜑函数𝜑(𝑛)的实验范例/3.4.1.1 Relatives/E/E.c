#include <stdio.h>

main(){
   int n,i,sum;
   while (1 == scanf("%d",&n) && n) {
      sum = n;
      for (i=2;i*i <= n;i++) {
         if (n%i == 0) {
            sum -= sum/i;
         }
         while (n%i == 0) n /= i;
      }
      if (n > 1) sum -= sum/n;
      printf("%d\n",sum);
   }
}
