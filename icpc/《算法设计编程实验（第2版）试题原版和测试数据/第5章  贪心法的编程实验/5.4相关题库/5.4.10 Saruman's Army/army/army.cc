#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
  while (true){
    int R, n;
    cin >> R >> n;
    if (R == -1 && n == -1) break;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort (v.begin(), v.end());

    // scan from left to right in list of troops

    int ct = 0, left = 0;
    while (left < n){
      
      // find furthest troop with R units of left
      
      int mid = left;
      while (mid < n && v[mid] - v[left] <= R) mid++;
      mid--;

      // find furthest troop with R units of mid

      int right = mid;
      while (right < n && v[right] - v[mid] <= R) right++;
      right--;

      left = right+1;
      ct++;
    }
    cout << ct << endl;
  }
}
