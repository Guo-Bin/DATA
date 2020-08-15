/*--------------------------------------------------------------*/
/* ACM ICPC 2007-2008                                           */
/* Northeastern European Regional Contest                       */
/* St Petersburg - Barnaul - Tashkent - Batumi, November 28, 200*/
/*--------------------------------------------------------------*/
/* Problem A. Ants                                              */
/*--------------------------------------------------------------*/
/* Solution                                                     */
/*                                                              */
/* Author                Petr Mitrichev                         */
/*--------------------------------------------------------------*/
 
import java.util.Locale;
import java.util.StringTokenizer;
import java.io.*;
import java.awt.geom.*;
import java.awt.*;

public class ants_petr implements Runnable {
    final String TASK_ID = "ants";
    final String IN_FILE = TASK_ID + ".in";
    final String OUT_FILE = TASK_ID + ".out";

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Thread(new ants_petr()).start();
    }

    public void run() {
        try {
            readInput();
            solve();
            writeOutput();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(57);
        }
    }

    int n;
    Point2D[] p1;
    Point2D[] p2;
    int[] pair;

    private void solve() {
        pair = new int[n];
        for (int i = 0; i < n; ++i)
            pair[i] = i;
        while (true) {
            boolean ok = true;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    if (cross(i, pair[i], j, pair[j])) {
                        int t = pair[i];
                        pair[i] = pair[j];
                        pair[j] = t;
                        ok = false;
                    }
                }
            if (ok)
                break;
        }
    }

    private boolean cross(int s1, int e1, int s2, int e2) {
        return new Line2D.Double(p1[s1], p2[e1]).intersectsLine(new Line2D.Double(p1[s2], p2[e2]));
    }

    private void writeOutput() throws FileNotFoundException {
        PrintWriter writer = new PrintWriter(OUT_FILE);

        for (int i = 0; i < n; ++i)
            writer.println(pair[i] + 1);

        writer.close();
    }

    private void readInput() throws IOException {
        reader = new BufferedReader(new FileReader(IN_FILE));
        tokenizer = null;

        n = nextInt();
        p1 = new Point2D[n];
        for (int i = 0; i < n; ++i) {
            int x = nextInt();
            int y = nextInt();
            p1[i] = new Point(x, y);
        }
        p2 = new Point2D[n];
        for (int i = 0; i < n; ++i) {
            int x = nextInt();
            int y = nextInt();
            p2[i] = new Point(x, y);
        }
    }

    StringTokenizer tokenizer;
    BufferedReader reader;

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}
