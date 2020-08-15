// πÍ≈≈ 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void merge(int a[], int lt, int mid, int rt, int tmp[])
{
	int i = lt, j = mid+1, pt = 0;
	while(i <= mid && j <= rt) {
		if(a[i] < a[j]) tmp[pt++] = a[i++];
		else tmp[pt++] = a[j++];
	}
	while(i <= mid) tmp[pt++] = a[i++];
	while(j <= rt)	tmp[pt++] = a[j++];
	for(int i = 0; i < rt-lt+1; i++) {
		a[lt+i] = tmp[i];
	}
}
void msort(int a[], int lt, int rt, int tmp[])
{
	int mid = lt + (rt - lt) / 2;
	if(lt == rt) return;
	msort(a, lt, mid, tmp);
	msort(a, mid+1, rt, tmp);
	merge(a, lt, mid, rt, tmp);
}
print(int a[], int n)
{
	for(int i = 0; i < n; i++) {
		printf("%d\t",a[i]);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n+10], tmp[n+10];
	for(int i = 0; i < n; i++) cin >> a[i];
	//msort(a, 0, n-1, tmp);
	sort(a, a+n);
	print(a, n);
	return 0;
}
