#include <stdio.h>
#include <string.h>

int crossMulti(int x1,int y1,int x2,int y2,int x3,int y3) {
	return (x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1);
}

class CrossPoint {
public:
	int a,b;
};

class Segment {
public:
	Segment() {
		clear();
	}

	void addSegment(Segment s) {
		int a,b;
		if (s.x1 == x1 && s.y1 == y1) {
			a=0;
			b=1;
		} else {
			a=crossMulti(x1,y1,x2,y2,s.x1,s.y1);
			b=crossMulti(x1,y1,x2,y2,s.x2,s.y2);
			if (!(a>=0&&b<0||a<=0&&b>0)) return;
			a=crossMulti(s.x1,s.y1,s.x2,s.y2,x1,y1);
			b=crossMulti(s.x1,s.y1,s.x2,s.y2,x2,y2);
			if (!(a>=0&&b<0||a<=0&&b>0)) return;
		}
		b=a-b;
		for(int i=0;i<cn;i++) {
			if (((__int64)a)*cross[i].b==((__int64)b)*cross[i].a) break;
		}
		if (i==cn) {
			cross[cn].a=a;
			cross[cn].b=b;
			cn++;
		}
	}

	int getCount() {
		return cn;
	}

	void clear() {
		cn=0;
	}
	int x1,y1,x2,y2;
private:
	CrossPoint cross[320];
	int cn;
} seg[320];

int p[320][2];
int n;

void main() {
	FILE *fp;
	int i,j;

	fp=fopen("euler.in","r");
	for(int ca=1;;ca++) {
		if (fscanf(fp,"%d",&n)!=1) break;
		if (n==0) break;
		for(i=0;i<n;i++) {
			fscanf(fp,"%d%d",&p[i][0],&p[i][1]);
			if (i&&p[i][0]==p[i-1][0]&&p[i][1]==p[i-1][1]) {
				i--;
				n--;
			}
		}
		if (p[n-1][0]==p[0][0]&&p[n-1][1]==p[0][1]) {
			n--;
		} else {
			p[n][0]=p[0][0];
			p[n][1]=p[0][1];
		}
		for(i=0;i<n;i++) {
			seg[i].x1=p[i][0];
			seg[i].y1=p[i][1];
			seg[i].x2=p[i+1][0];
			seg[i].y2=p[i+1][1];
			seg[i].clear();
		}
		int total=2;
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				seg[i].addSegment(seg[j]);
			}
			total+=seg[i].getCount();
		}
		printf("Case %d: There are %d pieces.\n",ca,total);
	}
}
