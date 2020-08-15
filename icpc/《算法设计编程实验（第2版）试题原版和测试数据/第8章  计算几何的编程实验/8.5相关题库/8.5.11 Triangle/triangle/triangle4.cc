#include <iostream>
#include <vector>
using namespace std;

bool within(int y, int y1, int y2)
{
  if (y1 <= y2)
    return ((y >= y1) && (y <= y2));
  else
    return ((y >= y2) && (y <= y1));
}

int main()
{
  while (true)
  {
    vector<int> x(4), y(4);

    int miny = INT_MAX, maxy = INT_MIN;
    bool all_zero = true;

    for (int i = 0; i < 3; ++i)
    {
      cin >> x[i];
      cin >> y[i];
      if ((x[i] != 0) || (y[i] != 0))
        all_zero = false;
      
      miny = min(y[i], miny);
      maxy = max(y[i], maxy);
    }
    x[3] = x[0];
    y[3] = y[0];

    if (all_zero)
      break;

    int area = 0;
    for (int yy = miny + 1; yy < maxy; ++yy)
    {
      //cout << yy << endl;
      int minx = INT_MAX, maxx = INT_MIN;
      for (int i = 0; i < 3; ++i)
      {
        int j = i + 1;
        if ((y[j] != y[i]) && within(yy, y[i], y[j]))
        {
          double xx = double(x[i]) + double(x[j] - x[i]) * double(yy - y[i]) / double(y[j] - y[i]);
          int x1 = int(floor(xx)) + 1;
          int x2 = int(ceil(xx)) - 1;
          if (x1 < minx)
            minx = x1;
          if (x2 > maxx)
            maxx = x2;
        }
      }

      //cout << "[" << minx << ", " << maxx << "]" << endl;
      if (maxx >= minx)
        area += (maxx - minx) + 1;
    }
    cout << area << endl;
  }
  return 0;
}
