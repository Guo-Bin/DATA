#include <iostream>
using namespace std;

main() {
  int p, a;
  while (cin >> p >> a && p) {
    int x;
    for (x = 2; x*x <= p; x++) if (p%x == 0) break;
    if (x*x > p) {cout << "no" << endl; continue;}
    int pow = 1, ap = a;
    for (x = 1; x <= p; x <<= 1, ap = ((long long)ap * ap) % p)
      if (p & x) pow = ((long long)pow * ap) % p;
    if (pow == a) cout << "yes" << endl; else cout << "no" << endl;
  }
}
