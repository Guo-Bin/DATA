// Author: Adrian Kuegel

import java.io.*;
import java.util.*;

public class expressions {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("expressions.in"));
		int tc = Integer.parseInt(in.readLine());
		while(tc-- > 0) {
			String code = in.readLine();
			int n = code.length();
			int [] left = new int[n];
			int [] right = new int[n];
			Stack<Integer> s = new Stack<Integer>();
			// build syntax tree
			for (int i=0; i<n; ++i) {
				if (Character.isUpperCase(code.charAt(i))) {
					right[i] = s.pop();
					left[i] = s.pop();
				}
				else
					left[i] = right[i] = -1;
				s.push(i);
			}
			StringBuffer res = new StringBuffer();
			int [] Q = new int[n];
			Q[0] = s.pop();
			// now do a level order traversal of the syntax tree
			int len = 1;
			for (int i=0; i<len; ++i) {
				res.append(code.charAt(Q[i]));
				if (left[Q[i]] >= 0) {
					Q[len++] = left[Q[i]];
					Q[len++] = right[Q[i]];
				}
			}
			System.out.println(res.reverse());
		}
	}
}