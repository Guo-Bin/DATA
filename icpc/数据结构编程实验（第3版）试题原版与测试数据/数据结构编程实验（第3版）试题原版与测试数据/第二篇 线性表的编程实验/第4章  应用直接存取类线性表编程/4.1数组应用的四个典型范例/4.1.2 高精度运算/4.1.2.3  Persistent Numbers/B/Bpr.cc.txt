#include <stdio.h>
#include <string.h>

char n[1010];   // at most 1000 digits
int len;

int divisible (int fact) {
  char m[1010];
  int mlen = 0, carry = 0;
  for (int i = 0; i < len; i++) {
    m[mlen++] = (carry*10+n[i])/fact;
    carry = (carry*10+n[i])%fact;
  }
  if (!carry) {
    for (int i = 0; i < mlen; i++) n[i] = m[i];
    len = mlen;
    return 1;
  }
  return 0;
}

int factmult(int fact) {
  int res = 0;
  while (divisible(fact)) res++;
  return res;
};


int main () {
  while (fgets(n,1002,stdin) != NULL) {
    if (n[0] == '-') break;
    len = strlen(n)-1;
    for (int i = 0; i < len; i++) n[i] -= '0';
    int iszero = 1;
    for (int i = 0; iszero && i < len; i++) if (n[i]) iszero = 0;
    if (iszero) { printf("10\n"); continue; }
    iszero = 1;
    for (int i = 0; iszero && i < len-1; i++) if (n[i]) iszero = 0;
    if (iszero)  { printf("1%1d\n",n[len-1]); continue; }

    int f2,f3,f5,f7;
    f2 = factmult(2);
    f3 = factmult(3);
    f5 = factmult(5);
    f7 = factmult(7);
//      printf("%d %d %d %d \n", f2, f3, f5, f7);

    iszero = 1;
    for (int i = 0; iszero && i < len-1; i++) if (n[i]) iszero = 0;
    if (!iszero || n[len-1] != 1) {
      printf("There is no such number.\n");
      continue;
    }
    int digits[2000], count = 0;
    while (f3 > 1) {      digits[count++] = 9;      f3 -= 2;    }
    while (f2 > 2) {      digits[count++] = 8;      f2 -= 3;    }
    while (f7)     {      digits[count++] = 7;      f7--;       }
    while (f2 && f3) {    digits[count++] = 6;      f2--; f3--; }
    while (f5)     {      digits[count++] = 5;      f5--;       }
    while (f2 > 1) {      digits[count++] = 4;      f2 -= 2;    }
    while (f3)     {      digits[count++] = 3;      f3--;       }
    while (f2)     {      digits[count++] = 2;      f2--;       }
    for (count = count-1; count >= 0; count--)
      printf("%1d",digits[count]);
    printf("\n");
  }
}
