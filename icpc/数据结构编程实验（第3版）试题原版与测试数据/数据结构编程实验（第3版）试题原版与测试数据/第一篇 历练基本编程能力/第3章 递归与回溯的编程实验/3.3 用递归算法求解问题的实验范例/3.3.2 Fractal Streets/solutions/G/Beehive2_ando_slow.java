import java.io.*;
import java.lang.*;
import java.util.*;


// Programma is niet echt efficient, hij loopt nu altijd
// het hele grid door, twee keer.  Met wat simpele optimalisatie
// (i.e. niet twee keer hetzelfde grid doorlopen, en stoppen
// zodra het laatste huis is bereikt), zou je hem lineair kunnen
// laten lopen, lineair met max(o,h).

class Turtle {
	public int turn = 0;
	public int x = 0;
	public int y = 0;
	public int h;

	public Turtle(int h) { // h = house number
		this.h = h;
	}

	public void f() {
		if (h > 1) { // house numbers assumed to start at 1
			h--;
			switch (turn) {
				case 0:
					x+= 10;
					break;
				case 90:
					y-= 10;
					break;
				case 180:
					x-= 10;
					break;
				case 270:
					y+= 10;
					break;
			}
		}
	}

	public void p() {
		turn=(turn+90)%360;
	}

	public void m() {
		turn=(turn+270)%360;
	}

	public void l(int n) {
		if (n == 0) {
			return;
		}
		p();
		r(n-1);
		f();
		m();
		l(n-1);
		f();
		l(n-1);
		m();
		f();
		r(n-1);
		p();
	}

	public void r(int n) {
		if (n == 0) {
			return;
		}
		m();
		l(n-1);
		f();
		p();
		r(n-1);
		f();
		r(n-1);
		p();
		f();
		l(n-1);
		m();
	}

}

class Main extends Beehive2_ando {}
class Beehive2_ando {

	static BufferedReader br = new BufferedReader(
							 new InputStreamReader(System.in));
	static StreamTokenizer tok = new StreamTokenizer(br);

	private static long leesInt() throws IOException{
		tok.nextToken();
		return (long) tok.nval;
	}

	private static String leesRegel() throws IOException {
		return (br.readLine());
	}

	public static void main(String argv[]) throws IOException {
		long runCnt = leesInt();
		for (long i = 0;i < runCnt; i++){
			run();
		}
	}

	private static void run() throws IOException {
		int n = (int)leesInt();
		int h = (int)leesInt(); // offered house
		int o = (int)leesInt(); // city planning office
		Turtle ch = getHouseCoords(h,n);
		Turtle co = getHouseCoords(o,n);

		System.out.println((long)(0.5+computeDistance(ch,co)));

	}

	private static Turtle getHouseCoords(int nr, int ord) {
		Turtle t = new Turtle(nr);
		t.l(ord);
		return t;
	}

	private static double computeDistance(Turtle a, Turtle b) {
		return Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}


}
