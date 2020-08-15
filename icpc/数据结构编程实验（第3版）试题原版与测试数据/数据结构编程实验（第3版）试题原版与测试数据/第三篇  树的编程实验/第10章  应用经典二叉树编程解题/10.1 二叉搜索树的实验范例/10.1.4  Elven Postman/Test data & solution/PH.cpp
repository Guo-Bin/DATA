#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct node{
	int v;
	node *l, *r;
	node(int _v): v(_v), l(NULL), r(NULL) {}
};

node* rec(vector<int> &a)
{
	if(a.size()==0) return NULL;
	node *ret=new node(a[0]);
	vector<int> left, right;
	int pos;
	for(pos=1; pos < a.size() && a[pos]<a[0]; pos++)
		left.push_back(a[pos]);
	while(pos<a.size()) right.push_back(a[pos++]);
	ret->l=rec(left);
	ret->r=rec(right);
	return ret;
}

void solve()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	node *root=rec(a);
	int q;
	scanf("%d",&q);
	for(int i = 0; i < q; i++)
	{
		int x;
		scanf("%d",&x);
		for(node *it=root; it->v!=x;)
		{
			if(it->v>x) { putchar('E'); it=it->l; }
			else { putchar('W'); it=it->r; }
		}
		putchar('\n');
	}
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--) solve();
	return 0;
}
