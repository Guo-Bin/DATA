import java.util.*;
import java.io.*;
public class triangle {
    public static void main(String args[]) {
	try {
	    BufferedReader br=new BufferedReader(new
						 InputStreamReader(System.in));
	    while(true) {
		StringTokenizer tok=new StringTokenizer(br.readLine()," ");
		int p[][]=new int[3][2];
		boolean stop=true;
		for(int i=0;i<3;i++) {
		    for(int j=0;j<2;j++) {
			p[i][j]=Integer.parseInt(tok.nextToken());
			if(p[i][j]!=0) stop=false;
		    }
		    
		}
		if(stop) break;
		
		int maxx,minx,maxy,miny;
		maxx=p[0][0];minx=p[0][0]; maxy=p[0][1]; miny=p[0][1];
		for(int i=0;i<3;i++) {
		    if(p[i][0]>maxx) maxx=p[i][0];
		    if(p[i][0]<minx) minx=p[i][0];
		    if(p[i][1]>maxy) maxy=p[i][1];
		    if(p[i][1]<miny) miny=p[i][1];
		}

		double
		tot_area=p[0][0]*p[1][1]+p[1][0]*p[2][1]+p[2][0]*p[0][1]-p[0][1]*p[1][0]-p[1][1]*p[2][0]-p[2][1]*p[0][0];
		tot_area=Math.abs(tot_area)/2.0;

		//System.out.println(tot_area+" is area");

		int tot=(maxx-minx+1)*(maxy-miny+1);
		int extra_vert=-1;
		for(int i=0;i<3;i++) {
		    //construct edge from i to i+1
		    int s=i,e=(i+1)%3;
		    int dx=p[i][0]-p[(i+1)%3][0],dy=p[i][1]-p[(i+1)%3][1];
		    dx=Math.abs(dx); dy=Math.abs(dy);
		    //figure out how many points lie along this line
		    int gcd=1;
		    for(int j=1;j*j<=dx;j++) {
			if(dx%j==0) {
			    if(dy%j==0 && j>gcd) gcd=j;
			    if(dy%(dx/j)==0 && (dx/j)>gcd) gcd=(dx/j);
			}
		    }
		    if(dx==0) gcd=dy;
		    if(dy==0) gcd=dx;
		    int np=gcd+1;
		    int tri_num=((dx+1)*(dy+1)+np)/2;
		    tot-=tri_num;
		    tot_area+=dx*dy/2.0;
		    //figure out if there is an extra rectangle
		    if(p[i][0]!=maxx&&p[i][0]!=minx &&
		       p[i][1]!=maxy&&p[i][1]!=miny) {
			extra_vert=i;
		    }
		}
		//one last thing: if this triange is obtuse, there is a
		//rectangle remaining
		double area_left=(maxx-minx)*(maxy-miny);
		area_left-=tot_area;
		int extra=0;
		if(area_left>0) {
		    for(int i=0;i<2;i++)
			for(int j=0;j<2;j++) {
			    int h,w;
			    if(i==0) h=maxy-p[extra_vert][1];
			    else h=p[extra_vert][1]-miny;
			    if(j==0) w=maxx-p[extra_vert][0];
			    else w=p[extra_vert][0]-minx;
			    if(w*h==(int)area_left) {
				extra=w*h;
			    }
			}

		}
		//System.out.println(extra + " is extra");
		tot-=extra;
		tot+=3;
		System.out.println(tot);
	    }
	}catch(Exception e) {
	    e.printStackTrace();
	}
    }
}
