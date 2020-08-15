#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct test {
	int top;
	int x;
};

struct test a[20];

int cmp(const struct test *a, const struct test *b)
{
	return a->top > b->top?-1:1;
}

int num(int x)
{
	int cont = 0;
	while(x>0) {
		x /= 10;
		cont++;
	}
	return cont;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i].x);
		a[i].top = a[i].x/pow(10, num(a[i].x)-1);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i = 0; i < n; i++) printf("%d",a[i].x);
	return 0;
}
