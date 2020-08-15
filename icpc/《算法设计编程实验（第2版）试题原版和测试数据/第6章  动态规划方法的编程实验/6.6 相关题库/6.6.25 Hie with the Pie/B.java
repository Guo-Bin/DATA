import java.util.*;

public class HiePie {
  public static int caseNum;
  public static int n;
  public static int minDist;
  public static int[][] dist, dist2;
  public static Scanner in;

  public static void main(String[] args) {
    caseNum = 0;
    in = new Scanner(System.in);
    n = in.nextInt();
    while (n != 0) {
      caseNum++;
      dist = new int[n+1][n+1];
      for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
          dist[i][j] = in.nextInt();
          if (dist[i][j] == 0 && i != j)
             dist[i][j] = 10000000;
        }

      solve();
      n = in.nextInt();
    }
  }

  public static void solve() {
    // First, find all-pairs shortest paths
    dist2 = new int[n+1][n+1];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        dist2[i][j] = dist[i][j];
    for (int k = 0; k <= n; k++)
      for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
          dist2[i][j] = Math.min(dist2[i][j],dist2[i][k]+dist2[k][j]);

    int[] s = new int[n];
    for (int i = 0; i < n; i++)
      s[i] = i+1;
    if (n == 1) {
      System.out.println("Case " + caseNum + ": " + (dist[0][1]+dist[1][0]));
      return;
    }
    minDist = Integer.MAX_VALUE;
    while (s != null) {


      int sum = dist2[0][s[0]] + dist2[s[n-1]][0];
      for (int i = 0; i < n-1; i++) {
         sum += dist2[s[i]][s[i+1]];
         if (sum >= minDist) {
           int temp[] = new int[n+1];
           for (int j = 0; j <= n; j++)
              temp[j] = 1;
           for (int j = 0; j <= i+1; j++)
              temp[s[j]] = 0;
           int loc = i+2;
           int j = n;
           while (loc < n && j >= 1) {
             if (temp[j] > 0) {
                s[loc] = j;
                loc++;
             }
             j--;
           }
           break;
         }
      }
      minDist = Math.min(sum,minDist);
      s = nextperm(s);
    }
    System.out.println(minDist);
  }

  public static int recur(int [] s, int k, int d) {
    if (d > minDist)
      return Integer.MAX_VALUE;
    if (k == n-1)
      return d;
    return recur(s,k+1,d+dist2[s[k]][s[k+1]]);
  }

  public static int[] nextperm(int[] s) {
    int swaploc = -1;
    int l = s.length;
    int[] ans;
    for (int i = l-1; i >= 1; i--) {
      if (s[i] > s[i-1]) {
        swaploc = i-1;
        break;
      }
    }
    if (swaploc < 0)
      return null;
    int swaploc2 = l-1;
    for (int i = l-1; i > swaploc; i--) {
      if (s[i] > s[swaploc]) {
         swaploc2 = i;
         break;
      }
    }
    ans = swap(s,swaploc,swaploc2);
    ans = rotate(ans,swaploc);
    return ans;
  }

  public static int[] swap(int[] s, int i, int j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return s;
  }

  public static int[] rotate(int[] s, int pos) {
    for (int i = pos+1; i <= pos+(n-pos)/2; i++) {
      int temp = s[i];
      s[i] = s[n-i+pos];
      s[n-i+pos] = temp;
    }
    return s;
  }
}
