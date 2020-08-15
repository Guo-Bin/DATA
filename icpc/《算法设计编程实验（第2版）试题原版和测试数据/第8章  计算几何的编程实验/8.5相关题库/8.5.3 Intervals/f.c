/*
	Problem: 	Intervals
	Author:		Michal Koucky
	Algorithm:	geometry + qsort
	Complexity:	n * log(n)
*/

#include <stdio.h>
#include <math.h>

struct wt { double a,b; } w[512];

void gety1y2(int cxi, int cyi, int ri, int bxi, int byi, double *ap, double *bp)
{
    double cx = cxi, cy = cyi, r = ri, bx = bxi, by = byi;
	
    double delta = (bx-cx)*(bx-cx) + (by-cy)*(by-cy);
    double k2 = r/sqrt(delta - r*r);
    double k1 = -(bx-cx)/(by-cy);
	
    *bp = (k1+k2)/(1-k1*k2)*by + bx;
    *ap = (k1-k2)/(1+k1*k2)*by + bx;
}

int cmp(struct wt *w1, struct wt *w2)
{
	double r = w1->a - w2->a;	
	return (r >= 0) ? (r > 0) : -1;
}

int main()
{
	int i,n;
	int x,y,r,bx,by;
	double x1,x2;
	
	for(;;)	{
		scanf("%d\n",&n);
		
		if(!n)break;
		
		scanf("%d%d\n",&bx,&by);
		
		for(i=0; i< n; i++) {
			scanf("%d%d%d\n",&x,&y,&r);
			gety1y2(x,y,r,bx,by,&w[i].a,&w[i].b);
		}
				
		qsort(w, n, sizeof(w[0]), cmp);
		
		x1=w[0].a;
		x2=w[0].b;
		for(i=0 ;i<n;i++) {
			if(w[i].a<=x2)	{ if (w[i].b>x2)x2=w[i].b; }
			else {
				printf("%.2f %.2f\n",x1,x2);
				x1=w[i].a;x2=w[i].b;
			}
		}
		printf("%.2f %.2f\n\n",x1,x2);
	}
	
    return 0;
}
