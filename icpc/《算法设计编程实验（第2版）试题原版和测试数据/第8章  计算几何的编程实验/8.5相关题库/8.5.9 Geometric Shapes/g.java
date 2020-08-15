import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class geometry {
	StringTokenizer st = new StringTokenizer("");
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		new geometry().run();
	}
	String nextToken() throws Exception {
		while (!st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}
	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	int rx, ry;
	void readPoint() throws Exception {
		String s = nextToken();
		int i = s.indexOf(',');
		rx = Integer.parseInt(s.substring(1, i));
		ry = Integer.parseInt(s.substring(i+1, s.length()-1));
	}
	int readX() throws Exception {
		readPoint();
		return rx*2;
	}
	int readY() throws Exception {
		return ry*2;
	}

	static class Segment {
		int x1,y1, x2,y2;
		public Segment(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.x2 = x2;
			this.y1 = y1;
			this.y2 = y2;
		}
		public String toString() {
			return "("+x1+","+y1+")-("+x2+","+y2+")";
		}
	}

	boolean res[][];
	Segment[][] shapes;

	private void detectAll() {
		for (int i = 0; i < 26; ++i) {
			if (shapes[i] == null) continue;
			for (int j = 0; j < 26; ++j) {
				if (shapes[j] == null || i == j) continue;
				res[i][j] = detectTwo(shapes[i], shapes[j]);
			}
		}
	}

	private boolean detectTwo(Segment[] sh1, Segment[] sh2) {
		for (int i = 0; i < sh1.length; ++i) {
			for (int j = 0; j < sh2.length; ++j) {
				Segment s1 = sh1[i], s2 = sh2[j];
				if (intersect(s1.x1,s1.y1, s1.x2,s1.y2, s2.x1,s2.y1, s2.x2,s2.y2)) {
					return true;
				}
			}
		}
		return false;
	}

	private void printAll() {
		char mine[] = new char[26];
		for (int i = 0; i < 26; ++i) {
			char me = (char) ('A' + i);
			if (shapes[i] == null) continue;
			int cnt = 0;
			for (int j = 0; j < 26; ++j) {
				if (res[i][j]) mine[cnt++] = (char) ('A' + j);
			}
			if (cnt == 0) {
				System.out.println(me + " has no intersections");
			} else if (cnt == 1) {
				System.out.println(me + " intersects with " + mine[0]);
			} else if (cnt == 2) {
				System.out.println(me + " intersects with " + mine[0] + " and " + mine[1]);
			} else {
				System.out.print(me + " intersects with ");
				--cnt;
				for (int j = 0; j < cnt; ++j) System.out.print(mine[j] + ", ");
				System.out.println("and " + mine[cnt]);
			}
		}
		System.out.println();
	}

	private void run() throws Exception {
		for (;;) {
			res = new boolean[26][26];
			shapes = new Segment[26][];
			for (;;) {
				char ch = nextToken().charAt(0);
				if (ch == '.') return;
				if (ch == '-') break;
				String k = nextToken();
				if ("square".equals(k)) {
					shapes[ch-'A'] = readSquare();
				} else if ("rectangle".equals(k)) {
					shapes[ch-'A'] = readRect();
				} else if ("line".equals(k)) {
					shapes[ch-'A'] = readLine();
				} else if ("triangle".equals(k)) {
					shapes[ch-'A'] = readTrian();
				} else if ("polygon".equals(k)) {
					shapes[ch-'A'] = readPoly();
				}
				Segment[] ss = shapes[ch-'A'];
			}
			detectAll();
			printAll();
		}
	}

	private Segment[] readSquare() throws Exception {
		int x1 = readX();
		int y1 = readY();
		int x3 = readX();
		int y3 = readY();
		int dx = (x3-x1) / 2;
		int dy = (y3-y1) / 2;
		int x2 = x1 + dx - dy;
		int y2 = y1 + dy + dx;
		int x4 = x1 + dx + dy;
		int y4 = y1 + dy - dx;
		return new Segment[] {
				new Segment(x1,y1, x2,y2),
				new Segment(x2,y2, x3,y3),
				new Segment(x3,y3, x4,y4),
				new Segment(x4,y4, x1,y1),
			};
	}
	
	private Segment[] readRect() throws Exception {
		int x1 = readX();
		int y1 = readY();
		int x2 = readX();
		int y2 = readY();
		int x3 = readX();
		int y3 = readY();
		int x4 = x1-x2+x3;
		int y4 = y1-y2+y3;
		return new Segment[] {
			new Segment(x1,y1, x2,y2),
			new Segment(x2,y2, x3,y3),
			new Segment(x3,y3, x4,y4),
			new Segment(x4,y4, x1,y1),
		};
	}
	
	private Segment[] readLine() throws Exception {
		int x1 = readX();
		int y1 = readY();
		int x2 = readX();
		int y2 = readY();
		return new Segment[] {new Segment(x1,y1,x2,y2)};
	}
	
	private Segment[] readTrian() throws Exception {
		int x1 = readX();
		int y1 = readY();
		int x2 = readX();
		int y2 = readY();
		int x3 = readX();
		int y3 = readY();
		return new Segment[] {
				new Segment(x1,y1, x2,y2),
				new Segment(x2,y2, x3,y3),
				new Segment(x3,y3, x1,y1),
		};
	}
	
	private Segment[] readPoly() throws Exception {
		int n = nextInt();
		int x0 = readX();
		int y0 = readY();
		int xp = x0, yp = y0;
		Segment s[] = new Segment[n];
		for (int i = 1; i < n; ++i) {
			int x = readX();
			int y = readY();
			s[i] = new Segment(xp,yp, x,y);
			xp = x; yp = y;
		}
		s[0] = new Segment(xp,yp, x0,y0);
		return s;
	}

	private boolean intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
		int den = (y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
		int nom1 = (x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
		int nom2 = (x2-x1)*(y1-y3) - (y2-y1)*(x1-x3);
		if (den==0) {
			if (nom1!=0 || nom2!=0) return false; // parallel
			// else conincident
			if (x1==x2 && x2==x3 && x3==x4) {
				// parallel with y axis => use y instead of x
				x1=y1; x2=y2; x3=y3; x4=y4;
			}
			int x;
			if (x1 > x2) { x = x1; x1 = x2; x2 = x; }
			if (x3 > x4) { x = x3; x3 = x4; x4 = x; }
			return (x1<=x3 && x3<=x2) || (x1<=x4 && x4<=x2)
					|| (x3<=x1 && x1<=x4) || (x3<=x2 && x2<=x4);
		}
		if (den < 0) { den = -den; nom1 = -nom1; nom2 = -nom2; }
		return (0<=nom1 && nom1<=den && 0<=nom2 && nom2<=den);
	}
}
