#include <stdio.h>
#include <string.h>

int i,j,k,t,tt,r,c,n;

char g[101][101], gg[101][101];

doit(int i, int j, int ii, int jj) {
   if (i<0 || i>=r || j<0 || j >= c) return 0;
   if (g[i][j] == 'R' && g[ii][jj] == 'S') gg[ii][jj] = 'R';
   if (g[i][j] == 'S' && g[ii][jj] == 'P') gg[ii][jj] = 'S';
   if (g[i][j] == 'P' && g[ii][jj] == 'R') gg[ii][jj] = 'P';
   return 0;
}

main(){
   scanf("%d",&t);
   for (tt=0;tt<t;tt++) { 
      scanf("%d%d%d",&r,&c,&n);
      for (i=0;i<r;i++) if (1 != scanf("%s",g[i])) {printf("missing input\n");exit(1);}
      for (i=0;i<n;i++) {
         memcpy(gg,g,sizeof(gg));
         for (j=0;j<r;j++) for (k=0;k<c;k++) {
            doit(j,k,j+1,k);
            doit(j,k,j-1,k);
            doit(j,k,j,k+1);
            doit(j,k,j,k-1);
         }
         memcpy(g,gg,sizeof(gg));
      }
      if (tt) printf("\n");
      for (i=0;i<r;i++) printf("%s\n",g[i]);
   }
   if (1 == scanf("%s",g[0])) printf("Extra junk in input!\n");
}
