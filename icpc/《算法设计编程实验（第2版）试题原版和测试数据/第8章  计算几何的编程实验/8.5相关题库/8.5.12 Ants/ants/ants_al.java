/*--------------------------------------------------------------*/
/* ACM ICPC 2007-2008                                           */
/* Northeastern European Regional Contest                       */
/* St Petersburg - Barnaul - Tashkent - Batumi, November 28, 200*/
/*--------------------------------------------------------------*/
/* Problem A. Ants                                              */
/*--------------------------------------------------------------*/
/* Solution                                                     */
/*                                                              */
/* Author                Andey Lopatin                          */
/*--------------------------------------------------------------*/
 
import java.util.*;
import java.io.*;
import java.awt.*;

public class ants_al {
  static Scanner in;
  static final int MaxN = 100, MaxC = 10000;
  static final double inf = 1e100;


  static void rangeInt (int r, int a, int b) throws Exception {
    if (r < a || r > b)
      error ("ERROR IN TEST: Expected integer between " + a + " and " + b +", found " + r);
  };

  static int rangeInt (int a, int b) throws Exception {
    int r = in.nextInt ();
    rangeInt (r, a, b);
    return r;
  };

  static void error (String s) throws Exception {
    throw new RuntimeException (s);
  };

  public static void main (String args []) throws Exception {
    in = new Scanner (new File ("ants.in"));
    PrintWriter out = new PrintWriter (new File ("ants.out"));
    int n = rangeInt (1, MaxN);
    int [] x1 = new int [n], y1 = new int [n], x2 = new int [n], y2 = new int [n];
    Set <Point> lst = new HashSet <Point> ();
    ArrayList <Point> l = new ArrayList <Point> ();
    for (int i = 0; i < n; i++) {
      x1[i] = rangeInt (-MaxC, MaxC);
      y1[i] = rangeInt (-MaxC, MaxC);
      Point t = new Point (x1[i], y1[i]);
      if (lst.contains (t)) error ("Duplicate point " + t);
      lst.add (t);
      l.add (t);
    };
    for (int i = 0; i < n; i++) {
      x2[i] = rangeInt (-MaxC, MaxC);
      y2[i] = rangeInt (-MaxC, MaxC);
      Point t = new Point (x2[i], y2[i]);
      if (lst.contains (t)) error ("Duplicate point " + t);
      lst.add (t);
      l.add (t);
    };
    if (in.hasNext ()) error ("End-of-file expected");

    for (int i = 0; i < 2 * n; i++) {
      Point p1 = l.get (i);
      for (int j = i + 1; j < 2 * n; j++) {
        Point p2 = l.get (j);
        for (int k = j + 1; k < 2 * n; k++) {
          Point p3 = l.get (k);
          int v = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
          if (v == 0) error ("Points " + p1 + ", " + p2 + " and " + p3 + " are on the same line");
        };
      };
    };
          

    

    double [][] G = new double [n + 1][n + 1];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        G[i + 1][j + 1] = Math.hypot (x2[j] - x1[i], y2[j] - y1[i]);

    /*for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        System.out.println (G[i + 1][j + 1]);*/

    double [] u = new double [n + 1], v = new double [n + 1], x = new double [n + 1];
    int [] A = new int [n + 1], B = new int [n + 1], P = new int [n + 1];

    boolean [] F = new boolean [n + 1];

    for (int i = 1; i <= n; i++) {
      Arrays.fill (F, false);
      Arrays.fill (x, inf);

      int c = 0; B[0] = i;

      do {
        F[c] = true;
        int k = B[c];
        double mn = inf;
        int mj = -1;
        for (int j = 1; j <= n; j++) if (!F[j]) {
          double t = G[k][j] - u[k] - v[j];
          if (t < x[j]) {
            x[j] = t; P[j] = c;
          };
          if (x[j] < mn) {
            mn = x[j]; mj = j;
          };
        };
        for (int j = 0; j <= n; j++) if (F[j]) {
          u[B[j]] += mn;
          v[j] -= mn;
        } else
          x[j] -= mn;
        c = mj;
      } while (B[c] != 0);

      do {
        int t = P[c];
        B[c] = B[t];
        c = t;
      } while (c != 0);
    };

    //System.out.println (v[0]);

    for (int i = 1; i <= n; i++) A[B[i]] = i;

    for (int i = 1; i <= n; i++) out.println (A[i]);

    out.close ();
  };
};