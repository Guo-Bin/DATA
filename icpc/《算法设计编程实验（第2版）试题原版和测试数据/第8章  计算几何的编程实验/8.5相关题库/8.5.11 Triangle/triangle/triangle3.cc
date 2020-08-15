#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(double((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}

int gcd(int a, int b)
{
	while(a%b) { int c = a%b; a=b; b=c; }
	return b;
}

int sl(int x1, int y1, int x2, int y2)
{
	int x = x2-x1;
	if(x<0) x=-x;
	int y = y2-y1;
	if(y<0) y=-y;
	if(x==0) return y;
	if(y==0) return x;
	return gcd(x,y);
}

void run()
{
	int x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if(x1==0 && x2==0 && x3==0 && y1==0 && y2==0 && y3==0)
		exit(0);

	double a = dist(x1,y1,x2,y2);
	double b = dist(x2,y2,x3,y3);
	double c = dist(x3,y3,x1,y1);
	double S = (a+b+c)*0.5;
	double A = sqrt(S*(S-a)*(S-b)*(S-c));
	int two_a = (int)(2*A + 0.5);

	int E = sl(x1,y1,x2,y2)+sl(x2,y2,x3,y3)+sl(x3,y3,x1,y1);
	int I = (two_a + 2 - E)/2;
	cout << I << endl;
}

int main()
{
	while(1) run();
}
