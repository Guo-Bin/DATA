#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string usefact(vector<int> fact) {
	string ret;
	while( fact[2] >= 3 ) {fact[2] -= 3; ret += '8';}
	while( fact[2] >= 2 ) {fact[2] -= 2; ret += '4';}
	while( fact[2] >= 1 ) {fact[2] -= 1; ret += '2';}
	while( fact[3] >= 2 ) {fact[3] -= 2; ret += '9';}
	while( fact[3] >= 1 ) {fact[3] -= 1; ret += '3';}
	while( fact[5] >= 1 ) {fact[5] -= 1; ret += '5';}
	while( fact[7] >= 1 ) {fact[7] -= 1; ret += '7';}
	return ret;
}

main() {
	int i, j, k, x, y, z, c;
	string n;

	for(;;) {
		cin >> n;
		if( n == "-1" ) break;
		if( n.size() == 1 ) {cout << "1" << n << '\n'; continue;}
		vector<int> fact(10);
		for( x = 2; x <= 9; x++ ) {
			c = 0;
			string n2 = n;
			for( i = 0; i < n.size(); i++ ) {
				c += n[i]-'0';
				n2[i] = c/x + '0';
				c = (c%x)*10;
			}
			if( !c ) {
				for( i = 0; n2[i] == '0'; i++ );
				n = n2.substr(i);
				fact[x--]++;
			}
		}
		if( n != "1" ) {cout << "There is no such number.\n"; continue;}
		string ret;
		ret = usefact(fact);
		sort(ret.begin(), ret.end());
		if( fact[2] && fact[3] ) {
			fact[2]--; fact[3]--;
			string ret2 = usefact(fact) + '6';
			sort(ret2.begin(), ret2.end());
			if( ret2.size() < ret.size() ||
				ret2.size() == ret.size() && ret2 < ret )
				ret = ret2;
		}
		cout << ret << '\n';
	}
}
