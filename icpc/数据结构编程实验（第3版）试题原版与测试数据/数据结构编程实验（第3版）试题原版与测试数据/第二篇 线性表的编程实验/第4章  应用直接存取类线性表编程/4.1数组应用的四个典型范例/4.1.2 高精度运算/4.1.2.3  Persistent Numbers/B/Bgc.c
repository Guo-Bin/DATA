#include <stdlib.h>
#include <stdio.h>

char n[5000], m[5000];

int i,j,k,nn,mn;

int rem(int d){
   int i,carry=0;
   for (i=0;i<nn;i++) {
      carry = 10 * carry + n[i];
      carry %= d;
   }
   return carry;
}

void Div(int d){
   int i,carry=0;
   for (i=0;i<nn;i++) {
     carry = 10 * carry + n[i];
     n[i] = carry/d;
     carry %= d;
   }
}

int one(){
   int i;
   for (i=0;i+1<nn;i++) if (n[i]) return 0;
   return n[i] == 1;
}
     
main(){
   while (strcmp(gets(n),"-1")) {
      nn = strlen(n);
      if (nn == 1) {
         printf("1%c\n",n[0]);
         continue;
      }
      mn = 0;
      for (i=0;i<nn;i++) n[i] -= '0';
      for (i=9;i>1;i--) {
         while (rem(i) == 0) {
            m[mn++] = '0'+i;
            Div(i);
         }
      }
      if (!one()) {
         printf("There is no such number.\n");
         continue;
      }
      for (i=mn-1;i>=0;i--) printf("%c",m[i]);
      printf("\n");
   }
}
