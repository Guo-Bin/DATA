#include <iostream>

using namespace std;

#define ABS(x) ((x)>0?(x):-(x))


int gcd(int a, int b)
{
  if(a==0)
    return b;
  if (b==0)
    return a;
  else return gcd(b, a%b);
}

int edge(int x, int y)
{
  int c = gcd(ABS(x), ABS(y));
  return c-1;
}

int main()
{

  int x1, x2, x3, y1, y2, y3;

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  while(x1 || y1 || x2 || y2 || x3 || y3) {

  int tarea = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
  tarea=ABS(tarea);
  int edgeC = edge(x1-x2, y1-y2)  + edge(x1-x3, y1-y3) + edge(x2-x3, y2-y3);

  //cout << "tarea: " << tarea << endl;
  //cout << "edgeC: " << edgeC << endl;
  //cout << "in: " << (tarea - edgeC - 1) << endl;
  int ans = (tarea - edgeC - 1)/2;
  cout << ans << endl;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  }

}
