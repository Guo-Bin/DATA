#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 1000010
#define ll long long
using namespace std;
ll c[N] = {0};
ll T,n,m,k;
struct node
{
    ll x,y;
} city[N];
int cmp(struct node a, struct node b)
{
    if(a.x != b.x) return a.x < b.x;
    else return a.y <= b.y;
}
int lowbit(ll x) {return x&(-x);}
void add(ll x)
{
    for(ll i = x; i <= m; i+=lowbit(i))
        c[i] += 1;
}
ll getsum(ll x)
{
    ll ans = 0;
    for(ll i = x; i > 0; i-=lowbit(i))
        ans += c[i];
    return ans;
}
int main()
{
    ll answer = 0;
    ll cnt = 1;
    scanf("%d",&T);
    while(T--)
    {
        answer = 0;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(ll i = 0; i < k; i++) cin >> city[i].x >> city[i].y;
        sort(city,city+k,cmp);
        for(ll i = 0; i < k; i++) {add(city[i].y); answer+=(getsum(m)-getsum(city[i].y));}
        printf("Test case %d: ",cnt);
        cout << answer << endl;
    }
    return 0;
}
