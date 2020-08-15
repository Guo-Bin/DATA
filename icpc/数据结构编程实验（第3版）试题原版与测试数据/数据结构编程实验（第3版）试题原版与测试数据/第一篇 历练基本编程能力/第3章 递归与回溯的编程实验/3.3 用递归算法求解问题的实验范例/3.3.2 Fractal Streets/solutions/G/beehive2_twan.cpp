
// ---------------------------------------------------------------------------
//
// Opgave:     Beehive2
// Uitwerking: Twan
//
// 01:00 - 01:19
// 
// ---------------------------------------------------------------------------

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int verbose = 0;

inline double sqr(double x) { return x*x; }

// ---------------------------------------------------------------------------
// Input
// ---------------------------------------------------------------------------

int n,a,b;

void read_input() {
	scanf("%d %d %d",&n,&a,&b);
}

// ---------------------------------------------------------------------------
// Hilbert curve
// ---------------------------------------------------------------------------

struct Point {
	Point(int x,int y) : x(x),y(y) {}
	int x,y;
	Point transpose() const { return Point(y,x); }
	Point rot180()    const { return Point(y,x); }
};

double dist(Point a, Point b) {
	return std::sqrt(sqr(10*(a.x-b.x)) + sqr(10*(a.y-b.y)));
}

void print(Point p) {
	fprintf(stderr, "(%d,%d) ",p.x,p.y);
}

// decode i for a curve of order n
Point decode(int n, int i) {
	if (n == -1) return Point(0,0);
	// quadrant
	// 0 3
	// 1 2
	Point p = decode(n-1, i);
	Point old_p = p;
	int quadrant = (i >> (2*n)) % 4;
	int size = 1 << n;
	
	if (quadrant == 0) {
		std::swap(p.x,p.y);
	} else if (quadrant == 1) {
		p.y += size;
	} else if (quadrant == 2) {
		p.y += size;
		p.x += size;
	} else if (quadrant == 3) {
		p = Point(size + size - 1 - p.y, size - 1 - p.x);
	}
	if (verbose) {
		fprintf(stderr," level %d quadrant %d  size %d (%d,%d)->(%d,%d)\n", n,quadrant,size,old_p.x,old_p.y,p.x,p.y);
	}
	return p;
}


// ---------------------------------------------------------------------------
// Main program
// ---------------------------------------------------------------------------

void run() {
	read_input();
	Point aa = decode(n-1,a-1), bb = decode(n-1,b-1);
	if (verbose) {
		print(aa);
		print(bb);
	}
	double d = dist(aa,bb);
	if ((int)(d + 0.5 - 1e-6) != (int)(d + 0.5 + 1e-6)) {
		fprintf(stderr, "Not roundable: %f", d);
		exit(1);
	}
	printf("%.f\n", d);
}

int main(int argc, char** argv) {
	// Parse args
	for (int i = 1 ; i < argc ; ++i) {
		string arg = argv[i];
		if (arg.size() > 2 && arg.substr(0,2) == "--") arg = arg.substr(1);
		if (arg == "-v" || arg=="-verbose") {
			verbose = 1;
		} else {
			fprintf(stderr, "Unknown argument: %s", argv[i]);
			exit(1);
		}
	}
	// Number of runs
	int runs;
	scanf("%d", &runs);
	while (runs --> 0) run();
	return 0;
}
