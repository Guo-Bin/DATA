import java.io.* ;
import java.util.* ;
public class army {
    public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
	while (true) {
	    String s = br.readLine() ;
	    String[] f = s.split(" ") ;
	    int r = Integer.parseInt(f[0]) ;
	    int n = Integer.parseInt(f[1]) ;
	    if (n < 0)
		return ;
	    int[] a = new int[n] ;
	    s = br.readLine() ;
	    f = s.split(" ") ;
	    for (int i=0; i<n; i++)
		a[i] = Integer.parseInt(f[i]) ;
	    Arrays.sort(a) ;
	    int rr = 0 ;
	    int max = -1000000 ;
	    for (int i=0; i<a.length; i++)
		if (a[i] > max) {
		    rr++ ;
		    int j = i ;
		    while (j+1 < a.length && a[j+1]-a[i] <= r)
			j++ ;
		    max = a[j] + r ;
		}
	    System.out.println(rr) ;
	}
    }
}
