#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 210000;

int n;
int a[MAXN];
long long t;
int lh;
long long h[MAXN];

void add(long long x)
{
	h[++lh] = x;
	int i = lh, j;
	while (i > 1)
	{
		j = (i >> 1);
		if (h[i] >= h[j]) break;
		long long t = h[i];
		h[i] = h[j];
		h[j] = t;
		i = j;
	}
}
long long get()
{
	long long ret = h[1];
	h[1] = h[lh--];
	int i = 1, j;
	while ((i << 1) <= lh)
	{
		j = (i << 1);
		if (j < lh && h[j + 1] < h[j]) ++j;
		if (h[i] <= h[j]) break;
		long long t = h[i];
		h[i] = h[j];
		h[j] = t;
		i = j;
	}
	return ret;
}

long long run(int k)
{
	if (k == 1) return 0xFFFFFFFFFFFFFFFL;
	lh = 0;
	for (int i = 1; i <= n; ++i)
		add(a[i]);
	long long t = 0;
	long long s = 0;
	while ((lh - 1) % (k - 1)) add(0);
	while (lh > 1)
	{
		s = 0;
		for (int i = 1; i <= k; ++i)
			if (lh > 0)
			{
				s += get();
			}
		t += s;
		add(s);
	}
	//printf("%d: %I64d, %I64d\n", k, t, h[1]);
	return t;
}

void init()
{
	scanf("%d %I64d", &n, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
}

void init2()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
}

void solve()
{
	int l = 2;
	int r = n;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		long long x = run(m);
		if (x <= t) r = m - 1;
		else l = m + 1;
	}
	printf("%I64d\n", l);
}

void solve2()
{
	//for (int i = 2; i <= n; ++i)
	//	printf("%d: %I64d\n", i, run(i));
	printf("%I64d\n", run(((rand() << 10) ^ rand()) % (n - 3) + 1));
}


int main()
{
	//freopen("input.txt", "r", stdin);
	int tt;
	scanf("%d", &tt);
	while (tt--)
	{
		init();
		solve();
	}
	return 0;
}
