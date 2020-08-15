//带有阈值的快速排序（插入排序） 
#include <stdio.h>

int cutoff = 10;
int a[1000001];
void swap(int i, int j);
int median(int l, int r);
void qsort(int l, int r);
void insort(int l, int r);

int main()
{
	int n;
	scanf("%d",&n);
	//int a[n];
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	qsort(0, n-1);
	for(int i = 0; i < n; i++){
		printf("%d",a[i]);
		if(i != n-1) printf(" ");
	}  
	return 0;
}

void swap(int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int median(int l, int r)
{
	int c = (l + r)/2;
	if(a[l] > a[c]) swap(l, c);
	if(a[l] > a[r]) swap(l, r);
	if(a[c] > a[r]) swap(c, r);
	swap(c, r);
	return a[r];
} 

void qsort(int l, int r)
{
	if(cutoff < r-l+1){
		int pivot = median(l, r);
		//int pivot = a[r];
		int i=l, j=r-1;
		while(1){
			while(a[i] < pivot) { i++; }
			while(a[j] > pivot) { j--; }
			if(i < j){
				swap(i, j);
				i++; j--;
			} else break;
		}
		swap(i, r);
		qsort(l, i-1);
		qsort(i+1, r);
	} else {
		insort(l, r);
	}
}

void insort(int l, int r)
{
	for(int i = 1; i <= r; i++){
		int tmp = a[i],j;
		for(j = i; j > 0 && a[j-1] > tmp; j--){
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
}

