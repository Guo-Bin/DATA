#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  return a==0? b : gcd(b%a, a);
}

ll getCount(ll dx, ll dy) {
  dx >?= -dx;
  dy >?= -dy;
  return gcd(dx, dy) - 1;
}

ll getArea(ll x1, ll y1, ll x2, ll y2) {
  ll z = x1*y2 - x2*y1;
  z >?= -z;
  return z;
}

int main() {
  ll x1, y1, x2, y2, x3, y3;

  while (1) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
      return 0;
    ll area = getArea(x2-x1, y2-y1, x3-x1, y3-y1);
    ll c1 = getCount(x2-x1, y2-y1);
    ll c2 = getCount(x3-x2, y3-y2);
    ll c3 = getCount(x1-x3, y1-y3);
    //   cout << area << " " << c1 << " " << c2 << " " << c3 << endl;
    cout << (area-1-c1-c2-c3)/2 << endl;
  }
}
