import java.io.*;
import java.util.*;

public class PH{

	static int[] pre;
	static int[] in;

	public static void main(String[] args){
		Scan scan = new Scan();
		int testcases = scan.nextInt();
		while(testcases-- != 0){
			int n = scan.nextInt();
			pre = new int[n];
			in = new int[n];
			for(int i=0;i<n;i++){
				pre[i] = scan.nextInt()-1;
				in[i] = i;
			}
			Node root = build(pre, in, 0, pre.length, 0, in.length);
			int queries = scan.nextInt();
			while(queries-- != 0){
				System.out.println(findPath(scan.nextInt()-1, root));
			}
		}
	}

	static Node build(int[] pre, int[] ino, int pb, int pe, int ib, int ie){
		if(pb+1 == pe) return new Node(pre[pb], null, null);
		if(pb == pe) return null;
		int root = pre[pb];
		int mid = ib;
		for(;mid<ie;mid++){
			if(ino[mid] == root) break;
		}
		Node left = build(pre, ino, pb+1, pb+1+mid-ib, ib, mid);
		Node right = build(pre, ino, pb+1+mid-ib, pe, mid+1, ie);
		return new Node(root, left, right);
	}

	static String findPath(int target, Node root){
		if(root.value == target) return "";
		if(root.value > target) return "E"+findPath(target, root.left);
		if(root.value < target) return "W"+findPath(target, root.right);
		return "What the fuck";
	}

	static class Node{
		int value;
		Node left, right;

		Node(int value, Node left, Node right){
			this.value = value;
			this.left = left;
			this.right = right;
		}
	}
}

class Scan{

	BufferedReader buffer;
	StringTokenizer tok;

	Scan(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}

	boolean hasNext(){
		while(tok==null || !tok.hasMoreElements()){
			try{
				tok = new StringTokenizer(buffer.readLine());
			}catch(Exception e){
				return false;
			}
		}
		return true;
	}

	String next(){
		if(hasNext()) return tok.nextToken();
		return null;
	}

	int nextInt(){
		return Integer.parseInt(next());
	}
}
