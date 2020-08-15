#include <stdio.h>

short int prime[42] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
	73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
	127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
	179, 181
};

void main (void)
{
	int go;
	FILE *f, *g;
	f = fopen("primelnd.in","rt");
	g = fopen("primelnd.out","wt");
	for (go = 1; go; ) {
		int s = 1;
		int i, prvy=1;
		int cis[16], ex[16], m=0;
		for (;;) {
			int p, e;
			char nl;
			fscanf(f,"%d %d%c",&p,&e,&nl);
			if (prvy && (p == 0)) {
				go = 0;
				break;
			}
			prvy = 0;
			while (e) {
				s *= p;
				e--;
			}
			if (nl == '\n' || nl == '\r') break;
		}
		s--;
		for (i=41; i>=0; i--) {
			int cnt = 0;
			if (s == 1) break;
			if (prime[i] > s) continue;
			while (s > 1 && s % prime[i] == 0) {
				s = s / prime[i];
				cnt++;
			}
			if (cnt > 0) {
				cis[m] = prime[i];
				ex[m] = cnt;
				m++;
			}
		}
		if (!go) break;
		if (s > 1) {
			fprintf(g,"%d %d",s,1);
			if (m > 0) fprintf(g," ");
		}
		for (i=0; i<m; i++) {
			fprintf(g,"%d %d",cis[i],ex[i]);
			if (i < m-1) fprintf(g," ");
		}
		fprintf(g,"\n");
	}
	fclose(g);
	fclose(f);
}
