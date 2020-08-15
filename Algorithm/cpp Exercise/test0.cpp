#include <iostream>
#include <cstdio>
using namespace std;
void Hanoi(int a, char src, char mid, char dest)
{
	if(a == 1) {
		cout << src << "->" << dest << endl;
		return;
	}
	Hanoi(a-1, src, dest, mid);
	cout << src << "->" << dest << endl;
	Hanoi(a-1, mid, src, dest);
	return;
}
int main()
{
	int a;
	cin >> a;
	Hanoi(a, 'A', 'B', 'C');
	return 0;
}
