/*--------------------------------------------------------------*/
/* ACM ICPC 2007-2008                                           */
/* Northeastern European Regional Contest                       */
/* St Petersburg - Barnaul - Tashkent - Batumi, November 28, 200*/
/*--------------------------------------------------------------*/
/* Problem A. Ants                                              */
/*--------------------------------------------------------------*/
/* Solution                                                     */
/*                                                              */
/* Author                Roman Elizarov                         */
/*--------------------------------------------------------------*/
 
/*
    Solution for NEERC'2007 Problem A: Ants
    (C) Roman Elizarov
    Note: this solution attempts to check correctness of the input
*/

import java.io.*;
import java.util.*;
import java.awt.geom.Line2D;

public class ants_re {

	public static void main(String[] args) throws Exception {
		new ants_re().go();
	}

	void go() throws Exception {
		// read input
		XScanner in = new XScanner(new File("ants.in"));
		in.useLocale(Locale.US);

		int n = in.nextInt();
		in.nextLine();

		assert n >= 1 && n <= 100;

		int[] x = new int[2 * n];
		int[] y = new int[2 * n];

		for (int i = 0; i < 2 * n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			assert x[i] >= -10000 && x[i] <= 10000;
			assert y[i] >= -10000 && y[i] <= 10000;
			in.nextLine();
		}
		in.close();

		for (int i = 0; i < 2 * n; i++)
			for (int j = i + 1; j < 2 * n; j++)
				for (int k = j + 1; k < 2 * n; k++) 
					assert vec(x[k] - x[i], y[k] - y[i], x[j] - x[i], y[j] - y[i]) != 0;

		// solve

		int[] s = new int[n];
		for (int i = 0; i < n; i++)
			s[i] = i;

		boolean changes = true;
		while (changes) {
			changes = false;
			for (int i = 0; i < n; i++) {
				int j = s[i] + n;
				for (int p = i + 1; p < n; p++) {
					int q = s[p] + n;
					if (Line2D.linesIntersect(x[i], y[i], x[j], y[j], x[p], y[p], x[q], y[q])) {
						int t = s[i];
						s[i] = s[p];
						s[p] = t;
						changes = true;
					}
				}
			}
		}

		// write output
		PrintWriter out = new PrintWriter("ants.out");
		for (int i = 0; i < n; i++) {
			out.println(s[i] + 1);
		}
		out.close();
	}

	private static int vec(int x1, int y1, int x2, int y2) {
		return x1 * y2 - y1 * x2;
	}

//----------------- just for validation ------------------

	/**
	 * Strict scanner to veryfy 100% correspondence between input files and input file format specification.
	 * It is a drop-in replacement for {@link java.util.Scanner} that could be added to a soulution source
	 * (cut-and-paste) without breaking its ability to work with {@link java.util.Scanner}.
	 */
	public class XScanner {
		private final BufferedReader in;
		private String line = "";
		private int pos;
		private int lineNo;
		private boolean localeset;

		public XScanner(File source) throws FileNotFoundException {
			in = new BufferedReader(new FileReader(source));
			nextLine();
		}

		public void close() {
			assert line == null : "Extra data at the end of file";
			try {
				in.close();
			} catch (IOException e) {
				throw new AssertionError("Failed to close with " + e);
			}
		}

		public void nextLine() {
			assert line != null : "EOF";
			assert pos == line.length() : "Extra characters on line " + lineNo;
			try {
				line = in.readLine();
			} catch (IOException e) {
				throw new AssertionError("Failed to read line with " + e);
			}
			pos = 0;
			lineNo++;
		}

		public String next() {
			assert line != null : "EOF";
			assert line.length() > 0 : "Empty line " + lineNo;
			if (pos == 0)
				assert line.charAt(0) > ' ' : "Line " + lineNo + " starts with whitespace";
			else {
				assert pos < line.length() : "Line " + lineNo + " is over";
				assert line.charAt(pos) == ' ' : "Wrong whitespace on line " + lineNo;
				pos++;
				assert pos < line.length() : "Line " + lineNo + " is over";
				assert line.charAt(0) > ' ' : "Line " + lineNo + " has double whitespace";
			}
			StringBuilder sb = new StringBuilder();
			while (pos < line.length() && line.charAt(pos) > ' ')
				sb.append(line.charAt(pos++));
			return sb.toString();
		}

		public int nextInt() {
			String s = next();
			assert s.length() == 1 || s.charAt(0) != '0' : "Extra leading zero in number " + s + " on line " + lineNo;
			assert s.charAt(0) != '+' : "Extra leading '+' in number " + s + " on line " + lineNo;
			try {
				return Integer.parseInt(s);
			} catch (NumberFormatException e) {
				throw new AssertionError("Malformed number " + s + " on line " + lineNo);
			}
		}

		public double nextDouble() {
			assert localeset : "Locale must be set with useLocale(Locale.US)";
			String s = next();
			assert s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0' : "Extra leading zero in number " + s + " on line " + lineNo;
			assert s.charAt(0) != '+' : "Extra leading '+' in number " + s + " on line " + lineNo;
			try {
				return Double.parseDouble(s);
			} catch (NumberFormatException e) {
				throw new AssertionError("Malformed number " + s + " on line " + lineNo);
			}
		}

		public void useLocale(Locale locale) {
			assert locale == Locale.US;
			localeset = true;
		}
	}
}
