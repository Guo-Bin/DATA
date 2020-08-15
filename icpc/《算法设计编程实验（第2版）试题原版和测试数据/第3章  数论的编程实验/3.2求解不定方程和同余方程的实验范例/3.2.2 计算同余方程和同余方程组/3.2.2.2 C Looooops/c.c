#include <stdio.h>

unsigned int w,A,B,C;

/*#define debug(x...) fprintf(stderr, x)*/
#define debug(x...) do {} while(0)

static void solve(void)
{
	long long int p, q, pc, pw, qc, qw, z, t;
	unsigned long long int W;

	W = 1ULL<<w;
	B = (B-A+W) % W;
	debug("### %d by %d mod %Ld\n", B, C, W);

	if (!C) {
		if (!B)
			puts("0");
		else
			puts("FOREVER");
		return;
	}

	p = C;  pc=1; pw=0;
	q = W;  qc=0; qw=1;
	while (q) {
		z = p/q;
		p -= z*q;
		pc -= z*qc;
		pw -= z*qw;
		t=p; p=q; q=t;
		t=pc; pc=qc; qc=t;
		t=pw; pw=qw; qw=t;
	}
	debug("\t%Ld = %Ld*%d + %Ld*%Ld\n", p, pc, C, pw, W);
	if (qc < 0) {
		qc = -qc;
		qw = -qw;
	}
	debug("\t%Ld = %Ld*%d + %Ld*%Ld\n", q, qc, C, qw, W);

	if (B % p) {
		puts("FOREVER");
		return;
	}

	z = B/p;
	pc *= z;
	pw *= z;
	debug("\t%d = %Ld*%d + %Ld*%Ld\n", B, pc, C, pw, W);

	if (pc < 0) {
		z = (qc-1 - pc) / qc;
		pc += z*qc;
		pw += z*qw;
	} else {
		z = pc/qc;
		pc -= z*qc;
		pw -= z*qw;
	}
	debug("\tRED %d = %Ld*%d + %Ld*%Ld\n", B, pc, C, pw, W);
	printf("%Ld\n", pc);
}

int main(void)
{
	for(;;) {
		scanf("%d%d%d%d", &A, &B, &C, &w);
		if (!w)
			break;
		solve();
	}
	return 0;
}
