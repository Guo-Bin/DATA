// º∆À„24µ„ 
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define min 1e-6
double a[5];
bool iszero(int x)
{
	if(fabs(x-0) <= min) return true;
	else return false;
}

bool count(double a[], int n)
{
	if(n == 1 && iszero(a[0]-24)) return true;
	else if(n == 1 && !iszero(a[0] - 24)) return false;
	double b[5];
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			int m = 0;
			for(int k = 0; k < n; k++) {
				if(a[k] != a[i] && a[k] != a[j]) b[m++] = a[k];
			}
			b[m] = a[i] + a[j];;
			b[m] = a[i] - a[j];
			if(count(b, m+1)) return true
			if(count(b, m+1)) return true;
			b[m] = a[j] - a[i];
			if(count(b, m+1)) return true;
			b[m] = a[i] * a[j];
			if(count(b, m+1)) return true;
			if(a[i] != 0) b[m] = a[j] / a[i];
			if(count(b, m+1)) return true;
			if(a[j] != 0) b[m] = a[i] / a[j];
			if(count(b, m+1)) return true;
		}
	}
	return false;
}

int main()
{
	for(int i = 0; i < 4; i++) cin >> a[i];
	if(count(a, 4)) cout << "YES";
	else cout << "NO";
	return 0;
}

