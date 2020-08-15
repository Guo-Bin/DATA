// Problem   Wine trading in Gergovia
// Algorithm greedy
// Runtime   O(n^2)
// Author    Adrian Kuegel
// Date      2006.06.18

#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

#define MAXN 100000

int a[MAXN];

int main() {
	int n;
	freopen("gergovia.in","r",stdin);
	while(scanf("%d",&n) == 1 && n != 0) {
		assert(n >= 2 && n <= MAXN);
		int sum = 0;
		for (int i=0; i<n; i++) {
			assert(scanf("%d",&a[i]) == 1);
			assert(a[i] >= -1000 && a[i] <= 1000);
			sum += a[i];
		}
		assert(sum == 0);
		int cost = 0;
		for (int i=0; i<n; i++) {
			if (a[i] < 0) {
				// sell a[i] units to other inhabitants
				for (int j=i+1; j<n && a[i] != 0; j++) {
					if (a[j]<=0)
						continue;
					int t = min(-a[i],a[j]);
					a[i] += t;
					a[j] -= t;
					cost += (j-i)*t;
				}
			}
			else {
				// buy a[i] units to other inhabitants
				for (int j=i+1; j<n && a[i] != 0; j++) {
					if (a[j]>=0)
						continue;
					int t = min(a[i],-a[j]);
					a[i] -= t;
					a[j] += t;
					cost += (j-i)*t;
				}
			}
		}
		printf("%d\n",cost);
	}
	assert(n == 0);
	return 0;
}
