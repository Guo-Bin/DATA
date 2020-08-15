#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

set<string> boards;
string b = ".........";
string wins[] = {"..X..X..X", ".X..X..X.", "X..X..X..",
				 "XXX......", "...XXX...", "......XXX",
				 "X...X...X", "..X.X.X.."};

void doit(char turn) {
	if( boards.count(b) ) return;
	boards.insert(b);
	int i, j;
	for( i = 0; i < 8; i++ ) {
		for( j = 0; j < 9; j++ )
			if( wins[i][j] == 'X' && b[j] != 'X' ) break;
		if( j == 9 ) return;
		for( j = 0; j < 9; j++ )
			if( wins[i][j] == 'X' && b[j] != 'O' ) break;
		if( j == 9 ) return;
	}
	for( i = 0; i < 9; i++ ) if( b[i] == '.' ) {
		b[i] = turn;
		doit( turn=='X' ? 'O' : 'X' );
		b[i] = '.';
	}
}

main() {
	int i, j, k, x, y, z, n;

	doit('X');
	for( cin >> n; n; n-- ) {
		string b;
		char ch;
		for( i = 0; i < 9; i++ ) {
			cin >> ch;
			b += ch;
		}
		cout << (boards.count(b) ? "yes" : "no") << endl;
	}
}

