// Problem   Wine trading in Gergovia
// Algorithm greedy
// Runtime   O(n)
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
		long long cost = 0;
		for (int i=0,j=0; i<n; i++) {
			if (a[i] < 0)
				continue;
			// first send to the left as much as possible
			while(j < i) {
				if (a[j] < 0) {
					int t = min(-a[j],a[i]);
					a[i] -= t;
					a[j] += t;
					cost += (i-j)*t;
					if (!a[i])
						break;
				}
				j++;
			}
			if (i+1<n) {
				a[i+1] += a[i];
				cost += a[i];
				a[i] = 0;
			}
		}
		printf("%lld\n",cost);
	}
	assert(n == 0);
	return 0;
}
