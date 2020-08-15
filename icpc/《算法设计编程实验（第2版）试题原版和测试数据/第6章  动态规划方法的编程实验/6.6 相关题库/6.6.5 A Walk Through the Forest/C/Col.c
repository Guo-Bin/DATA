#include <stdio.h>
#include <string.h>

unsigned d[1010][1010];
unsigned c[1010];
unsigned count[1010];
int q[1000000];
int worklist[1010];

main() {
    int N, M, i, from, to, dist, head, tail, node;
    while(1) {
        scanf("%d %d ", &N, &M);
        if(!N) break;
        memset(d, -1, sizeof(d));
        memset(c, -1, sizeof(c));
        for( i = 0; i < M; i++ ) {
            scanf("%d %d %d ", &from, &to, &dist);
            d[from][to] = dist;
            d[to][from] = dist;
        }
        c[2] = 0;
        head = 0;
        tail = 0;
        q[tail++] = 2;
        while(tail > head) {
            node = q[head++];
            for( i = 1; i <= N; i++ ) {
                if(d[node][i] == -1) continue;
                if(d[node][i] + c[node] < c[i]) {
                    c[i] = d[node][i] + c[node];
                    q[tail++] = i;
                }
            }
        }
        /*
        for( i = 0; i <= N; i++ ) {
            printf("%d %d\n", i, c[i]);
        }
        */
        memset(count, 0, sizeof(count));
        count[1] = 1;
        head = 0;
        tail = 0;
        q[tail++] = 1;
        memset(worklist, 0, sizeof(worklist));
        worklist[1] = 1;
        while(tail > head) {
            node = q[head++];
            worklist[node] = 0;
            count[node] = 0;
            for( i = 1; i <= N; i++ ) {
                if(d[node][i] == -1) continue;
                if(c[node] >= c[i]) continue;
                count[node] += count[i];
            }
            if(node == 1) count[node] = 1;
            0&&printf( "%d %d\n", node, count[node] );
            for( i = 1; i <= N; i++ ) {
                if(d[node][i] == -1) continue;
                if(c[i] >= c[node]) continue;
                if(!worklist[i]) {
                    q[tail++] = i;
                    worklist[i] = 1;
                }
            }
        }
        printf("%d\n", count[2]);
    }
}
