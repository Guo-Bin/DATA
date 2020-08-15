int ppl[200];
int A[105][50000];

main() {
    int n;
    int i,sum=0,j,k;
    int max;
    scanf("%u ", &n );
    for(i=0;i<n;i++) {
        scanf( "%u ", &ppl[i] );
        sum+=ppl[i];
    }
    memset(A,-1,sizeof(A));
    A[0][0] = 0;
    for(i=0;i<n;i++) {
        for(j=1;j<=(1+n)/2;j++) {
            for(k=46000;k>=ppl[i];k--) {
                if( A[j-1][k-ppl[i]]>=0) {
                    A[j][k] = A[j-1][k-ppl[i]] + ppl[i];
                    if( A[j][k] != k ) { *((int*)5) = 1; }
                }
            }
        }
    }
    max=0;
    for( j=n/2; n-j-j > -2; j++ )
    for( k=0; k<=sum/2; k++ ) {
        if( A[j][k]>=0 ) {
            if( max<k ) max=k;
        }
    }
    printf( "%u %u\n", max, sum-max );
}
