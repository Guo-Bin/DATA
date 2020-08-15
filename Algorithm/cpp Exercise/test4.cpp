// øÏ≈≈   
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//int cutoff = 10;
void swap(int & x, int & y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void qsort(int a[], int lt, int rt)
{
	if(lt >= rt) return;
	int pivot = a[lt];
	swap(a[lt], a[rt]);
	int i = lt, j = rt-1;
	while(i < j) {
		while(a[i++] < pivot);
		while(a[j--] > pivot);
		if(i < j) swap(a[i++], a[j--]);
		else break;
	}
	swap(a[i], a[rt]);
	qsort(a, lt, i-1);
	qsort(a, i+1, rt);
	
}
void print(int a[], int n)
{
	for(int i = 0; i < n; i++) {
		printf("%d\t",a[i]);
	}
}
void insertion_sort(int a[], int n)
{
	for(int i = 1; i < n; i++) {
		int k = a[i],j;
		for(j = i; j > 0 && a[j-1] > k; j--) a[j] = a[j-1];
		a[j] = k;
	}
} 
int main()
{
	int a[] = {1,7,4,2,4,23,67,43,89,12,34,5,43,23,45,6,5,34,3,34,3,2343,6,765,43};
	//while(i < 5) cin >> a[i++];
	//qsort(a, 0, sizeof(a)/sizeof(a[0])-1);
	//sort(a, a+25);
	insertion_sort(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));
	return 0;
}
