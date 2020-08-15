// Author: Adrian Kuegel
// Date: 1. 6. 2007

#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int a[MAXN], ind[MAXN];

int main() {
	int c, n;
	freopen("halloween.in","r",stdin);
	while(scanf("%d %d",&c,&n) == 2 && (n || c)) {
		assert(n >= 1 && n <= 100000);
		assert(c <= n);
		for (int i=0; i<c; ++i)
			ind[i] = -1;
		for (int i=0; i<n; ++i) {
			scanf("%d",&a[i]);
			assert(a[i] >= 1 && a[i] <= 100000);
		}
		int sum = 0;
		ind[0] = 0;
		bool found = false;
		for (int i=0; i<n; ++i) {
			sum = (sum + a[i]) % c;
			if (ind[sum] >= 0) {
				int checksum = 0;
				for (int j=ind[sum]; j<=i; ++j) {
					checksum = (checksum+a[j])%c;
					printf("%d",j+1);
					if (j < i) printf(" ");
					else puts("");
				}
				assert(checksum % c == 0);
				found = true;
				break;
			}
			ind[sum] = i+1;
		}
		assert(found);
	}
	assert(c == 0 && n == 0);
	return 0;
}
