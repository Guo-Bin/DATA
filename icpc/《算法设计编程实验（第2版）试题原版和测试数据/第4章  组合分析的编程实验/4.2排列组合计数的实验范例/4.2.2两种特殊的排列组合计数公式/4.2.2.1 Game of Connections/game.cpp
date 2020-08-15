#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>

using namespace std;

#define maxn 25

const int size = 735471; // C(24, 8)

int number[maxn];
const int n=24;
char h[1<<n];
int open[size];
char depth[1<<n];
int a[maxn],b[maxn];
int cur,tail;

int table[8][7]={
	1,3,7,12,16,21,23,
	2,4,9,13,18,22,24,
	11,10,9,8,7,6,5,
	20,19,18,17,16,15,14,
	24,22,18,13,9,4,2,
	23,21,16,12,7,3,1,
	14,15,16,17,18,19,20,
	5,6,7,8,9,10,11
};
	

void decode(int *a, int x)
{
	int i;
	int len=0;
	for(i=0;i<n;i++)
		if( x&(1<<i))
			a[i]=1;
		else
			a[i]=0;
}

int encode(int *a)
{
	int x=0;
	int i;
	for(i=n-1;i>=0;i--) {
		x=x*2+a[i];
	}
	//if(x>(1<<24)) cout<<"faint"<<endl;
	return x;
}


void presearch()
{
	int i,j,k,x,y;
	memset(depth,100,sizeof(depth));
	for(i=0;i<8;i++)
		for(j=0;j<7;j++)
			table[i][j]--;
	
	int initx = (1<<6)+(1<<7)+(1<<8)+(1<<11)+(1<<12)+(1<<15)+(1<<16)+(1<<17) ;
	open[0]=initx;
	depth[0]=0;
	cur=-1;
	tail=0;
	h[initx]=0;
	depth[initx]=0;
	while(++cur<=tail) {
		y=open[cur];
		decode(b, y);
		for(i=0;i<8;i++) {
			memcpy(a,b,sizeof(int)*n);
			k=a[table[i][6]];
			for(j=6;j>=1;j--) {
				a[table[i][j]] = a[table[i][j-1]];
			}
			a[table[i][0]]=k;
			x = encode(a);
			//cout<<x<<endl;
			if(  depth[y]+1<depth[x] ||
			    (depth[y]+1==depth[x] && i<h[x]) )
			{
				//if( y = 2638351 )
					//cout<<x<<endl;
				h[x]=i;
				if(depth[y]+1<depth[x]) {
					open[++tail]=x;
					depth[x]=depth[y]+1;
				}
			}
		}
		
	}
	
	//for(i=0;i<n;i++)		if(a[i]) cout<<i+1<<endl;
	//cout<<tail+1<<endl;
}

char ans[20];
char list[20];
int ans2;

void findans(int p, int x)
{
	
	if( depth[x]==0 ) return;
	list[p] = char('A')+h[x];
	decode(a, x);
	//cout<<list[p]<<" "<<x<<" "<<(int)depth[x]<<" "<<(int)h[x]<<endl;
	int i,j,tmp;
	i=h[x];
	tmp = a[table[i][0]];
	for(j=0;j<6;j++)
		a[table[i][j]] = a[table[i][j+1]];
	a[table[i][j]]= tmp;
	int y = encode(a);
	findans(p+1, y);
}

void solve()
{
	int i,j,k;
	int x,y;
	int len=100;
	
	for(k=1;k<=3;k++){
		for(i=0;i<n;i++)
			if(number[i]==k)
				a[i]=1;
			else
				a[i]=0;
		x = encode(a);
		if(depth[x]<len) {
			len=depth[x];
			ans2=k;
			findans(0,x);
			list[len]=0;
			strcpy(ans, list);
		}
		if(depth[x]==len){
			findans(0,x);
			list[len]=0;
			if( strcmp(list, ans)<0 ) {
				strcpy(ans, list);
				ans2=k;
			}			
		}
	}
	if(len==0)
		cout<<"No moves needed"<<endl;
	else
		cout<<ans<<endl;
	cout<<ans2<<endl;
}

int main()
{
	freopen("game.in","rt",stdin);
	int i,j,k;
	presearch();
	while(1) {
		for(i=0;i<n;i++)
			if(!(cin>>number[i])) break;
		if(cin.fail()) break;
		solve();
	};
	
	return 0;
}
