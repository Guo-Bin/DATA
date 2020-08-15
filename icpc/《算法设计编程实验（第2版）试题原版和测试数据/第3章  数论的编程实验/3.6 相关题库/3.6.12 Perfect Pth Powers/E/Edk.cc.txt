#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

main() {
	int i, j, k, x, y, z, n;

	while( cin >> n && n ) {
		z = (int)(sqrt(fabs((double)n))+1);
		int ret = 1;
		for( x = 2; x <= z; x++ ) {
			for( i = 0, y = n; y%x == 0; i++, y /= x );
			if( y == 1 ) ret >?= i;
			if( y == -1 && i%2 ) ret >?= i;
		}
		cout << ret << '\n';
	}
}

