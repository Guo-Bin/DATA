#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define MAXN 40
#define MAXSEG 100

#define EPS 0.0000000001
#define SQR(a) ((a)*(a))

int n;
char name[MAXN+2];
int iscir[MAXN+2];
double cirx[MAXN+2],ciry[MAXN+2],cirr[MAXN+2];
int vercnt[MAXN+2];
double verx[MAXN+2][MAXSEG+2];
double very[MAXN+2][MAXSEG+2];


double dist_line_seg(double ax, double ay, double s1x, double s1y, double s2x, double s2y)
{
	double r = ((ax-s1x)*(s2x-s1x) + (ay-s1y)*(s2y-s1y)) / (SQR(s2x-s1x) + SQR(s2y-s1y));
	double px = s1x + r*(s2x-s1x);
	double py = s1y + r*(s2y-s1y);

	if(r<0 || r>1) return -1;
	return sqrt(SQR(px-ax)+SQR(py-ay));
}

double dist_points(double ax, double ay, double bx, double by)
{
	return sqrt(SQR(ax-bx)+SQR(ay-by));
}

int is_point_in_line(double px, double py, double l1x, double l1y, double l2x, double l2y)
{
	double ux=-1, uy=-1, xok=0, yok=0;

	if(fabs(l1x-l2x)<EPS) 
	{
		if(fabs(px-l1x)<EPS) xok = 1;
		else return 0;
	}
	else
	{
		ux = (px-l1x)/(l2x-l1x);
		if(ux+EPS<0 || ux-EPS>1) return 0;
	}
	if(fabs(l1y-l2y)<EPS) 
	{
		if(fabs(py-l1y)<EPS) yok = 1;
		else return 0;
	}
	else
	{
		uy = (py-l1y)/(l2y-l1y);
		if(uy+EPS<0 || uy-EPS>1) return 0;
	}
	if(xok || yok) return 1;
	if(fabs(ux-uy)<EPS) return 1;
	return 0;	
}


int seg_intersect(double a1x, double a1y, double a2x, double a2y, 
		double b1x, double b1y, double b2x, double b2y)
{
	double ua, ub;
	double denom = (b2y-b1y)*(a2x-a1x)-(b2x-b1x)*(a2y-a1y);
	if(denom==0) /* are parallel */
	{
		if(is_point_in_line(a1x,a1y,b1x,b1y,b2x,b2y)) return 1;
		if(is_point_in_line(a2x,a2y,b1x,b1y,b2x,b2y)) return 1;
		if(is_point_in_line(b1x,b1y,a1x,a1y,a2x,a2y)) return 1;
		if(is_point_in_line(b2x,b2y,a1x,a1y,a2x,a2y)) return 1;
		return 0;
	}
	else 
	{
		ua = ((b2x-b1x)*(a1y-b1y)-(b2y-b1y)*(a1x-b1x))/denom;
		ub = ((a2x-a1x)*(a1y-b1y)-(a2y-a1y)*(a1x-b1x))/denom;
	}
/*printf("%.4f %.4f\n",ua,ub);*/
	if(ua+EPS>=0 && ua-EPS<=1 && ub+EPS>=0 && ub-EPS<=1) return 1; else return 0;
}

int intersect(int a, int b)
{
	int i,j,tmp,tmp2;
	double dist,dist1,dist2,dist3;

	if(iscir[a] && iscir[b]) 
	{
		/* check triangle inequalities of triangle with edges r1,r2,dist(centers)*/
		dist = dist_points(cirx[a], ciry[a], cirx[b], ciry[b]);
		if(dist-EPS>cirr[a]+cirr[b] || cirr[b]>cirr[a]+dist+EPS || cirr[a]>cirr[b]+dist+EPS) 
			return 0; else return 1;
	}
	if(iscir[b]) { tmp = a; a = b; b = tmp; }
	if(iscir[a])
	{
		for(i=0;i<vercnt[b];i++)
		{
			tmp = (i+1)%vercnt[b];
			dist1 = dist_points(cirx[a], ciry[a], verx[b][i], very[b][i]);
			dist2 = dist_points(cirx[a], ciry[a], verx[b][tmp], very[b][tmp]);
			dist3 = dist_line_seg(cirx[a], ciry[a], verx[b][i], very[b][i], verx[b][tmp], very[b][tmp]);
			if(dist3<0)
			{
				if((dist1-EPS<cirr[a] && dist2+EPS>cirr[a]) || (dist1+EPS>cirr[a] && dist2-EPS<cirr[a]))
				{
					return 1;
				}
			}
			else
			{
				if((dist3-EPS<cirr[a] && (dist1+EPS>cirr[a] || dist2+EPS>cirr[a])))
				{
					return 1;
				}
			}
		}
		return 0;
	}
	for(i=0;i<vercnt[a];i++) for(j=0;j<vercnt[b];j++)
	{
		tmp = (i+1)%vercnt[a];
		tmp2 = (j+1)%vercnt[b];
		if(seg_intersect(verx[a][i],very[a][i],verx[a][tmp],very[a][tmp],
					verx[b][j],very[b][j],verx[b][tmp2],very[b][tmp2])) return 1;
	}
	return 0;
}


int main()
{
	int i,j,k,l;
	char tmpc;
	char tmps[50];
	double tmpl[10];
	double tmpx, tmpy;
	int ncnt;
	char neighs[100];

	while(1)
	{
		n=0;
		while(1)
		{
			scanf(" ");
			tmpc = getchar();
			if(tmpc=='.') return 0;
			if(tmpc=='-') break;
			name[n] = tmpc;
			scanf(" %s ",tmps);
			iscir[n] = 0;
			if(!strcmp(tmps,"circle"))
			{
				iscir[n] = 1;
				scanf(" (%lf,%lf) %lf", &cirx[n], &ciry[n], &cirr[n]);
			}
			if(!strcmp(tmps,"square"))
			{
				scanf(" (%lf,%lf) (%lf,%lf) ", &tmpl[0], &tmpl[1], &tmpl[2], &tmpl[3]);
				vercnt[n] = 4;
				verx[n][0] = tmpl[0]; very[n][0] = tmpl[1];
				verx[n][2] = tmpl[2]; very[n][2] = tmpl[3];

				tmpx = (verx[n][0]+verx[n][2])/2;
				tmpy = (very[n][0]+very[n][2])/2;
				verx[n][1] = tmpx + (very[n][0]-tmpy);
				verx[n][3] = tmpx - (very[n][0]-tmpy);
				very[n][1] = tmpy - (verx[n][0]-tmpx);
				very[n][3] = tmpy + (verx[n][0]-tmpx);
				
			}
			if(!strcmp(tmps,"triangle"))
			{
				scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf) ", 
						&tmpl[0], &tmpl[1], &tmpl[2], &tmpl[3], &tmpl[4], &tmpl[5]);
				vercnt[n] = 3;
				for(i=0;i<3;i++)
				{
					verx[n][i] = tmpl[2*i];
					very[n][i] = tmpl[2*i+1];
				}
			}
			if(!strcmp(tmps,"rectangle"))
			{
				vercnt[n] = 4;
				for(i=0;i<3;i++)
				{
					scanf(" (%lf,%lf) ", &verx[n][i], &very[n][i]);
				}
				tmpx = (verx[n][0]+verx[n][2])/2;
				tmpy = (very[n][0]+very[n][2])/2;
				verx[n][3] = verx[n][1] + 2*(tmpx-verx[n][1]);
				very[n][3] = very[n][1] + 2*(tmpy-very[n][1]);
			}
			if(!strcmp(tmps,"line"))
			{
				scanf(" (%lf,%lf) (%lf,%lf) ", &tmpl[0], &tmpl[1], &tmpl[2], &tmpl[3]);
				vercnt[n] = 2;
				for(i=0;i<2;i++)
				{
					verx[n][i] = tmpl[2*i];
					very[n][i] = tmpl[2*i+1];
				}
			}
			if(!strcmp(tmps,"polygon"))
			{
				scanf(" %d ", &vercnt[n]);
				for(i=0;i<vercnt[n];i++)
				{
					scanf(" (%lf,%lf) ", &verx[n][i], &very[n][i]);
				}
			}
/*if(iscir[n]==0) for(i=0;i<vercnt[n];i++) printf("%.4f %.4f   ", verx[n][i], very[n][i]);
printf("\n");*/
			n++;
		}
		if(n==0) continue;
/*name[n] = '\0';
printf("%d %s\n",n,name);*/

		
		for(i='A';i<='Z';i++) 
		{
			for(k=0;k<n;k++) if(name[k]==i) break;
			if(k==n) continue;
			
			ncnt = 0;
			for(j='A';j<='Z';j++) if(i!=j)
			{
				for(l=0;l<n;l++) if(name[l]==j) break;
				if(l==n) continue;
				if(intersect(k,l)) neighs[ncnt++] = j;
			}
			if(ncnt==0) printf("%c has no intersections\n",i);
			else if(ncnt==1) printf("%c intersects with %c\n", i,neighs[0]);
			else if(ncnt==2) printf("%c intersects with %c and %c\n", i,neighs[0],neighs[1]);
			else
			{
				printf("%c intersects with ", i);
				for(j=0;j<ncnt-1;j++) printf("%c, ", neighs[j]);
				printf("and %c\n", neighs[ncnt-1]);
			}
		}
		printf("\n");
	}
	return 0;
}
