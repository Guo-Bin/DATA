#include <iostream>
#include <queue>
#include <cstdio>
#define ll long long // ע�����ݷ�Χ��int�п������
using namespace std;
int main()
{
    ll n,x,s,c,a,b;
    c = 0;
    scanf("%lld",&n);
    priority_queue <ll, vector<ll>, greater<ll> > q;
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld",&x);
        q.push(x);
    }
    while(q.size() != 1)
    {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        c += a+b;
        q.push(a+b);
    }
    cout << c;
    return 0;
}
