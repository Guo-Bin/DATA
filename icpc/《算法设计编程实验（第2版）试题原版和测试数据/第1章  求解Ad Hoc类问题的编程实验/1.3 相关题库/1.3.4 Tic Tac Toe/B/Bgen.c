#include <stdio.h>
#include <stdlib.h>
int z,i,j,k;

main(){
   printf("100\n");
   for (i=0;i<100;i++) {
      if (i) printf("\n");
      for (j=0;j<3;j++) {
         for (k=0;k<3;k++) {
            printf("%c",".XO"[random()%3]);
         }
         printf("\n");
      }
   }
}
           
            
