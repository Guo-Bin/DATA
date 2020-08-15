#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 1000000000
#define ll long long
using namespace std;
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
    return 0;
}
