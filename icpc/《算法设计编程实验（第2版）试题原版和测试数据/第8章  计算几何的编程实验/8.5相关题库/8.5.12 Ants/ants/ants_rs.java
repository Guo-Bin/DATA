/*--------------------------------------------------------------*/
/* ACM ICPC 2007-2008                                           */
/* Northeastern European Regional Contest                       */
/* St Petersburg - Barnaul - Tashkent - Batumi, November 28, 200*/
/*--------------------------------------------------------------*/
/* Problem A. Ants                                              */
/*--------------------------------------------------------------*/
/* Solution                                                     */
/*                                                              */
/* Author                Roman Satyukov                         */
/*--------------------------------------------------------------*/
 
import java.io.*;
import java.util.*;

public class ants_rs implements Runnable {
    private static final double eps = 1e-9;
    private Scanner in;
    private PrintWriter out;

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    
    
    private void solve() throws IOException {
        in = new Scanner(new FileReader("ants.in"));
        out = new PrintWriter("ants.out");
        
        int n = in.nextInt();
        int[] x1 = new int[n];
        int[] y1 = new int[n];
        int[] x2 = new int[n];
        int[] y2 = new int[n];
        for (int i = 0; i < n; i++) {
            x1[i] = in.nextInt();
            y1[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            x2[i] = in.nextInt();
            y2[i] = in.nextInt();
        }
        
        int[] match = new int[n];
        for (int i = 0; i < n; i++) {
            match[i] = i;
        }
        
        while (true) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int ii = match[i];
                    int jj = match[j];
                    if (intersects(x1[i], y1[i], x2[ii], y2[ii], x1[j], y1[j], x2[jj], y2[jj])) {
                        match[i] = jj;
                        match[j] = ii;
                        found = true;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            out.println(match[i] + 1);
        }
        
        in.close();
        out.close();
    }
    
    private boolean intersects(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2) {
        long a1 = y1 - y2;
        long b1 = x2 - x1;
        long c1 = -a1 * x1 - b1 * y1;
        long a2 = yy1 - yy2;
        long b2 = xx2 - xx1;
        long c2 = -a2 * xx1 - b2 * yy1;
        long d = a1 * b2 - a2 * b1;
        long d1 = -(c1 * b2 - c2 * b1);
        long d2 = -(a1 * c2 - a2 * c1);
        
        if (a1 * xx1 + b1 * yy1 + c1 == 0) {
            return true;
        }
        if (a1 * xx2 + b1 * yy2 + c1 == 0) {
            return true;
        }
        if (a2 * x1 + b2 * y1 + c2 == 0) {
            return true;
        }
        if (a2 * x2 + b2 * y2 + c2 == 0) {
            return true;
        }
        
        if (d != 0) {
            double x = 1.0 * d1 / d;
            double y = 1.0 * d2 / d;
            if (bt(x, x1, x2) && bt(y, y1, y2) && bt(x, xx1, xx2) && bt(y, yy1, yy2)) {
                return true;
            }
            return false;
        }
        
        return false;
    }


    private boolean bt(double x, int x1, int x2) {
        return ((x1 - eps < x) && (x < x2 + eps)) || ((x2 - eps < x) && (x < x1 + eps));
    }


    public static void main(String[] args) {
        new Thread(new ants_rs()).start();
    }

}
