#include <iostream>
#include <math.h>

using namespace std;

struct Pos {
	int x, y;
	Pos(int x_, int y_) { x = x_; y = y_; }
};

Pos p(int o, int n) {
	if (o == 0) {
		switch (n) {
			case 0: return Pos(0,0);
			case 1: return Pos(1,0);
			case 2: return Pos(1,1);
			case 3: return Pos(0,1);
			default: return Pos(1/0,1/0); // wanna know if this happens!
		}
	} else {
		int q = n >> (2*o);
		int qs = 1 << o;
		int np = n - (q << (2*o));
		Pos s = p(o-1, np);
		int t;
		switch (q) {
			case 0:
				t = s.x; s.x = s.y; s.y = t;
				break;
			case 1:
				s.x += qs;
				break;
			case 2:
				s.x += qs;
				s.y += qs;
				break;
			case 3:
				t = s.x; s.x = s.y; s.y = t;
				s.x = qs-1 - s.x;
				s.y = 2*qs-1 - s.y;
				break;
			default:
				return Pos(1/0, 1/0);
		}
		return s;
	}
}

void run() {
	int o, n, m;
	cin >> o >> n >> m;
	--o; --n; --m;
	Pos s = p(o, n), e = p(o, m);
	int dx = 10*(s.x - e.x), dy = 10*(s.y - e.y);
	cout << round(sqrt(dx*dx + dy*dy)) << endl;
}

int main() {
	int runs;
	cin >> runs;
	while (runs--) run();
}
