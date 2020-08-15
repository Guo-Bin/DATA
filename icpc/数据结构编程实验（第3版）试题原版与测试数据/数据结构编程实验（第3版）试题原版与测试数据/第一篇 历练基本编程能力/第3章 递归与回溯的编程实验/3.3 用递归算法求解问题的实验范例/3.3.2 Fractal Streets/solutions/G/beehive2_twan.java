// ---------------------------------------------------------------------------
//
// Opgave:     Beehive2
// Uitwerking: Twan
//
// Port of the C++ code
// 
// ---------------------------------------------------------------------------

import java.util.*;

class Main {
	
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int runs = sc.nextInt();
		while (runs --> 0) new Main();
	}
	
	Main() {
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		Point aa = decode(n,a-1), bb = decode(n,b-1);
		System.out.println((int)(aa.dist(bb) + 0.5));
	}
	
	class Point {
		long x,y;
		Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
		double dist(Point b) {
			long dx = (x-b.x);
			long dy = (y-b.y);
			return 10 * Math.sqrt(dx*dx + dy*dy);
		}
	}
	
	// decode i for a curve of order n
	Point decode(int n, int i) {
		Point p = new Point(0,0);
		for (int nn = 0 ; nn < n ; ++nn) {
			// quadrant
			// 0 3
			// 1 2
			int quadrant = (i >> (2*nn)) % 4;
			int size = 1 << nn;
			
			if (quadrant == 0) {
				p = new Point(p.y, p.x);
			} else if (quadrant == 1) {
				p = new Point(p.x, p.y + size);
			} else if (quadrant == 2) {
				p = new Point(p.x + size, p.y + size);
			} else if (quadrant == 3) {
				p = new Point(size + size - 1 - p.y, size - 1 - p.x);
			} else {
				throw new RuntimeException("bork bork bork");
			}
		}
		return p;
	}
	
}

