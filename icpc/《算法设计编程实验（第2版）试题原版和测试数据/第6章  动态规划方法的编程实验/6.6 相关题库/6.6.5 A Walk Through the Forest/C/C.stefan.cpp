#include <stdio.h>
#include <string.h>


int matrix[1024][1024];
int n, p;


#define MIN(a, b) (a < b ? a : b)


void work() {
	int poss[1024], dist[1024];
	for (int i = 1; i <= n; i++) {
		dist[i] = 2000000000;
		poss[i] = 0;
	}
	dist[2] = 0;
	poss[2] = 1;
	int best = 2;
	do {
		for (int i = 1; i <= n; i++)
			if (matrix[best][i] <= 1000000) {
				if (dist[i] > 0)
					dist[i] = MIN(dist[i], matrix[best][i] + dist[best]);
				else if (-dist[i] < dist[best])
					poss[best] += poss[i];
			}
		dist[best] = -dist[best];
		best = -1;
		for (int i = 1; i <= n; i++)
			if ((dist[i] > 0) && (dist[i] <= 1000000000)) {
				if (best < 0)
					best = i;
				else if (dist[i] < dist[best])
					best = i;
			}
	} while (best > 0);
	printf("%d\n", poss[1]);
} // end of work()


int main() {
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		scanf("%d", &p);
		memset(matrix, 127, sizeof(matrix));
		for (int i = 0; i < p; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			matrix[x][y] = matrix[y][x] = d;
		}
		work();
	}
	return 0;
}


