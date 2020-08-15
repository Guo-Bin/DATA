// Author: Adrian Kuegel

import java.io.*;
import java.util.*;

public class annoying {
	public static void main(String [] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("annoying.in"));
		String line;
		while((line = in.readLine()) != null) {
			StringTokenizer strtok = new StringTokenizer(line);
			int n = Integer.parseInt(strtok.nextToken());
			int m = Integer.parseInt(strtok.nextToken());
			int r = Integer.parseInt(strtok.nextToken());
			int c = Integer.parseInt(strtok.nextToken());
			if (n == 0 && m == 0 && r == 0 && c == 0)
				break;
			char [][] p = new char[n][m];
			for (int i=0; i<n; ++i) {
				line = in.readLine();
				p[i] = line.toCharArray();
				for (int j=0; j<m; ++j)
					p[i][j] -= '0';
			}
			int cnt = 0;
			for (int i=0; i+r<=n; ++i)
				for (int j=0; j+c<=m; ++j) {
					if (p[i][j] == 0)
						continue;
					++cnt;
					for (int ii=0; ii<r; ++ii)
						for (int jj=0; jj<c; ++jj)
							p[i+ii][j+jj] ^= 1;
				}
			for (int i=0; i<n; ++i)
				for (int j=0; j<m; ++j)
					if (p[i][j] != 0)
						cnt = -1;
			System.out.println(cnt);
		}
	}
}
