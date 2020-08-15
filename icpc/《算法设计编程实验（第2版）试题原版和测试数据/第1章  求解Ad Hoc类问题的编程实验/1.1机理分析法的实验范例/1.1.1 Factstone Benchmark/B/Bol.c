#include <math.h>
#include <stdio.h>
char foo[10000];
main() {
    int y;
    int i;
    double fct;
    double yy;
    while(1) {
        scanf("%d", &y);
        if(!y) break;
        y/=10;
        y-=194;
        y = 1<<y;
        yy = y;
        fct = 0.0;
        for(i=1;;i++) {
            fct += log(i)/log(2);
          0&&printf("%f %f\n", fct, yy);
            if(fct > yy) {
                printf("%d\n", i-1);
                break;
            }
        }
    }
}
