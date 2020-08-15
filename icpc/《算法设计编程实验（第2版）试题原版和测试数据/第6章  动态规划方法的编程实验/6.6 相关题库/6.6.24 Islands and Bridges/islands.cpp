#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("islands.in");
#define cin fin
#define LL _int64
int v[20];   // values of the cities
int r[20][20];  // the adjacency matrix of the graph
int n,m,N;   // number of vertices, edges, and N=2^n.

int vBest[9000][13][13];
// vBest[Set][a][b]: the value of the best path we can get
// such that it visits the Set of vertices, and the last two stops are a and b.
LL nBest[9000][13][13];
// the number of such best paths.

void input()
{
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>v[i];
	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
			r[j][k]=0;
	for(i=0;i<m;i++)
	{
		cin>>j>>k;
		j--;k--;
		r[j][k]=r[k][j]=1;
	}
}

// play(Set, a, b) is the memorizing version of dynamic programming that computes
// vBest[Set][a][b] and nBest[Set][a][b]
// We insist that vBest == 0 => there is no such path, since any path will give positive value in our problem.

int play(int Set, int a, int b)
{
	if(vBest[Set][a][b]>=0) return vBest[Set][a][b];

	// check if a and b are different vertices in the set, and are adjacent
	if(a==b || !(Set & (1<<a)) || !(Set & (1<<b)) || !(r[a][b]))
	{
		vBest[Set][a][b]=0;
		return(0);
	}

	int bs=v[b]+v[a]*v[b];

	// Base case: Set = {a,b}
	if(Set == (1<<a)+(1<<b))
	{
		vBest[Set][a][b]=bs+v[a];
		nBest[Set][a][b]=1;
		return(bs+v[a]);
	}

	int max=0, c, t;
	LL cnt=0;

	for(c=0;c<n;c++)
	{
		t=play(Set-(1<<b), c, a);
		if(t>0)
		{
			t+=bs;
			if(r[c][b]) t+=v[a]*v[b]*v[c];
			if(t>max)
			{
				max=t;
				cnt=nBest[Set-(1<<b)][c][a];
			}
			else if(t==max)
				cnt+=nBest[Set-(1<<b)][c][a];
		}
	}

	vBest[Set][a][b]=max;
	nBest[Set][a][b]=cnt;
	return(max);
}

void play()
{
	int max;
	LL cnt;
	unsigned long p;
	if(n==1) {cout<<v[0]<<" "<<1<<endl; return;}
	int i,j,k;
	N=(1<<n);
	for(i=0;i<N;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				vBest[i][j][k]=-1;
	
	max=0; cnt=0;
	for(j=0;j<n;j++)
		for(k=0;k<n;k++)
		{
			i=play(N-1,j,k);
			if(i>0)
			{
				if(i>max)
				{
					max=i;
					cnt=nBest[N-1][j][k];
				}
				else if(i==max)
					cnt+=nBest[N-1][j][k];
			}
		}
	p=cnt/2;
	cout<<max<<" "<<p<<endl;
	// note that each path is counted twice if n>1.
}

int main()
{
	int q; cin>>q;
	while(q)
	{
		input();
		play();
		q--;
	}
	return 0;
}
