#include <iostream>

using namespace std;

int gcd (int a, int b){
  if (b == 0) return a;
  return gcd (b, a % b);
}

// compute number of lattice points on line from (0,0) to (x,y)

int numBound (int x, int y){
  x = abs(x);
  y = abs(y);

  return gcd (x, y) + 1;
}

int main (){
  int x1, y1, x2, y2, x3, y3;
  int area2;

  // The "trick" to this problem is to use Pick's formula for the
  // area of a triangle:
  //     A = I + B/2 - 1
  // where
  //     A = area of triangle
  //     I = # of internal lattice points
  //     B = # of lattice points on the boundary

  while (true){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0) break;
    
    // compute twice the area of the triangle
    area2 = abs((x2*y1+x3*y2+x1*y3)-(x2*y3+x3*y1+x1*y2));

    area2 += 2;
    
    area2 -= 
      numBound (x2-x1,y2-y1) + 
      numBound (x3-x2,y3-y2) + 
      numBound (x1-x3,y1-y3) - 3;

    cout << area2 / 2 << endl;
  }
}
