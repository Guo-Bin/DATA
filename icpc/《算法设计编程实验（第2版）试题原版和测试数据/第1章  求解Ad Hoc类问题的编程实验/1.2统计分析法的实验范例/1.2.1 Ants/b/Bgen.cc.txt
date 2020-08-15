#include <stdio.h>
#include <stdlib.h>

int main () {
  int c;
  fprintf(stderr,"How many cases?\n");
  scanf("%d",&c);
  printf("%d\n",c);
  while (c--) {
    fprintf(stderr,"Give length and number of ants\n"); 
    int l, n;
    scanf("%d%d",&l,&n);
    printf("%d %d\n",l,n);
    while (n--) printf("%d\n",rand()%l);
  }
}
