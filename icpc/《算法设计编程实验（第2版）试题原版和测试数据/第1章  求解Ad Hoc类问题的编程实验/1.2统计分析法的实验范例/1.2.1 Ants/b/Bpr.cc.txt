#include <stdio.h>
#include <assert.h>
#include <algorithm>

int main () {
  int c, l, n;
  scanf("%d",&c);
  while (c--) {
    scanf("%d%d",&l,&n);
    assert(1<=l && l <=1000000);
    int low = 0, high = 0;
    while (n--) {
      int x;
      scanf("%d",&x);
      assert(0 <= x && x <= l);
      if (x < l-x) {
	if (low < x) low = x;
	if (high < l-x) high = l-x;
      } else {
	if (low < l-x) low = l-x;
	if (high < x) high = x;
      }
    }
  printf("%d %d\n", low, high);
  }
}
