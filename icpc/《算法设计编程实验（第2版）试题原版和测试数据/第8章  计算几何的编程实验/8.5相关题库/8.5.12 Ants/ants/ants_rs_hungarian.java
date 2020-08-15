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

// Uses Hungarian algorithm for finding max matching with minimal sum
public class ants_rs_hungarian implements Runnable {
    private static final double eps = 1e-9;
    private BufferedReader in;
    private PrintWriter out;
    private int[] lm;
    private int[] rm;
    private boolean[] mark;
    private double[][] w;
    private int n;
    
    private boolean dfs(int u) {
        for (int v = 0; v < n; v++) {
            if ((w[u][v] < eps) && (!mark[v])) {
                mark[v] = true;
                if (rm[v] == -1 || dfs(rm[v])) {
                    lm[u] = v;
                    rm[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    private void solve() throws IOException {
        n = Integer.parseInt(in.readLine());
        int[] x1 = new int[n];
        int[] y1 = new int[n];
        int[] x2 = new int[n];
        int[] y2 = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            x1[i] = Integer.parseInt(st.nextToken());
            y1[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            x2[i] = Integer.parseInt(st.nextToken());
            y2[i] = Integer.parseInt(st.nextToken());
        }
        
        w = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = Math.hypot(x1[i] - x2[j], y1[i] - y2[j]);
            }
        }
        
        int matching = 0;
        mark = new boolean[n];
        lm = new int[n];
        rm = new int[n];
        Arrays.fill(lm, -1);
        Arrays.fill(rm, -1);
        for (int i = 0; i < n; i++) {
            double min = 1e100;
            for (int j = 0; j < n; j++) {
                min = Math.min(min, w[i][j]);
            }
            for (int j = 0; j < n; j++) {
                w[i][j] -= min;
            }
        }
        while (matching < n) {
restart:
            while (true) {
                Arrays.fill(mark, false);
                for (int i = 0; i < n; i++) {
                    if (lm[i] == -1 && dfs(i)) {
                        matching++;
                        continue restart;
                    }
                }
                break;
            }
            double min = 1e100; 
            for (int i = 0; i < n; i++) {
                if (lm[i] != -1 && !mark[lm[i]]) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (rm[j] != -1 && mark[j]) {
                        continue;
                    }
                    min = Math.min(min, w[i][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                if (lm[i] != -1 && !mark[lm[i]]) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    w[i][j] -= min;
                }
            }
            for (int j = 0; j < n; j++) {
                if (rm[j] == -1 || !mark[j]) {
                    continue;
                }
                for (int i = 0; i < n; i++) {
                    w[i][j] += min;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.println(lm[i] + 1);
        }
    }
    
    public static void main(String[] args) {
        new Thread(new ants_rs_hungarian()).start();
    }

    public void run() {
        String problem = getClass().getName().split("_")[0];
        try {
            in = new BufferedReader(new FileReader(new File(problem + ".in")));
            out = new PrintWriter(new File(problem + ".out"));
            solve();
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
