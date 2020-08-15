#include <stdio.h>
#include <stdlib.h>
struct test {
	int x;
	int y;
};
/*int cmp( const void *a ,const void *b) 
{ 
return (*(struct test *)a).x > (*(struct test *)b).x ? -1 : 1; 
} 
*/
int cmp( const void *a , const void *b ) 
{ 
struct test *c = (struct test *)a; 
struct test *d = (struct test *)b; 
if(c->x != d->x) return d->x - c->x; 
else return c->y - d->y; 
} 


struct test a[10];
int main()
{
	for(int i = 0; i < 10; i++) {
		a[i].y = i+1;
		a[i].x = 0;
	}
	qsort(a,10,sizeof(a[0]),cmp);
	for(int i = 0; i < 10; i++) printf("%d\t",a[i].y);
	return 0;
}
