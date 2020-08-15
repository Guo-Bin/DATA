#include <stdio.h>
#include <string.h>

char freddie[20000];

main() {
    int k, m, i, c, r, j, nope, course;
    while(1) {
        scanf("%d", &k);
        if(!k) break;
        scanf("%d", &m);
        memset(freddie, 0, sizeof(freddie));
        for(i=0; i<k; i++) {
            scanf("%d", &course);
            freddie[course] = 1;
        }
        nope = 0;
        for(i=0; i<m; i++) {
            scanf("%d", &c);
            scanf("%d", &r);
            for(j=0; j<c; j++) {
                scanf("%d", &course);
                if(freddie[course]) r--;
            }
            if(r>0) nope = 1;
        }
        if(nope) puts("no"); else puts("yes");
    }
}

