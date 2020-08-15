#include <stdio.h>
#include <stdlib.h>

struct test {
	int x;
	int num;
};

int cmp( const struct test *a , const struct test *b ) 
{ 
	if(a->x != b->x) return a->x < b->x?1:-1;
	return a->num > b->num?1:-1;
} 

struct test a[20001];
int n,k,e[10];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < 10; i++) scanf("%d",&e[i]);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].x);
		a[i].num = i+1;
	}
	//
	qsort(a, n, sizeof(a[0]), cmp);
	//
	for(int i = 0; i < n; i++) {
		a[i].x += e[i%10]; 
	}
	//
	qsort(a, n, sizeof(a[0]), cmp);
	//
	for(int i = 0; i < k; i++) {
		printf("%d",a[i].num);
		if(i != k-1) printf(" ");
	}
	return 0;
}
