// Author: Adrian Kuegel
// Date: 1. 6. 2007

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cctype>
using namespace std;

typedef vector<string> VS;

string code;
VS res;

void doit(int &pos, int d) {
	assert(pos >= 0);
	res[d] += code[pos];
	--pos;
	if (islower(code[pos+1]))
		return;
	assert(isupper(code[pos+1]));
	doit(pos,d+1);
	doit(pos,d+1);
}

int main() {
	int tc;
	ifstream in("expressions.in");
	in >> tc;
	assert(tc >= 1 && tc <= 200);
	while(tc--) {
		assert(in >> code);
		assert(code.size() < 10000 && code.size() % 2 == 1);
		res.assign(code.size(),"");
		int pos = code.size()-1;
		doit(pos, 0);
		assert(pos < 0);
		for (VS::reverse_iterator it=res.rbegin(); it!=res.rend(); ++it)
			cout << *it;
		cout << endl;
	}
	return 0;
}
