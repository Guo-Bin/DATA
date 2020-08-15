// Author: Adrian Kuegel
// Date: 15. 6. 2007
// Algorithm: greedy
// Complexity: O(r*(n-r)*c*(m-c))

#include <stdio.h>
#include <assert.h>

char p[128][131];

int main() {
	FILE *in = fopen("annoying.in","r");
	int n, m, r, c;
	while(fscanf(in, "%d %d %d %d ",&n,&m,&r,&c) == 4) {
		if (n == 0 && m == 0 && r == 0 && c == 0)
			break;
		assert(1 <= r && r <= n && n <= 100 && 1 <= c && c <= m && m <= 100);
		for (int i=0; i<n; ++i) {
			fgets(p[i],sizeof(p[i]),in);
			for (int j=0; j<m; ++j) {
				assert(p[i][j] >= '0' && p[i][j] <= '1');
				p[i][j] -= '0';
			}
			assert(p[i][m] == '\n');
		}
		int cnt = 0;
		for (int i=0; i+r<=n; ++i)
			for (int j=0; j+c<=m; ++j) {
				if (!p[i][j])
					continue;
				++cnt;
				for (int ii=0; ii<r; ++ii)
					for (int jj=0; jj<c; ++jj)
						p[i+ii][j+jj] ^= 1;
			}
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (p[i][j])
					cnt = -1;
		printf("%d\n",cnt);
	}
	assert(n == 0 && m == 0 && r == 0 && c == 0);
	fclose(in);
	return 0;
}
