//ʱ��// 
#include <stdio.h>
#include <time.h>
 
clock_t stop,start;  /*clock_t��clock�����������صı�������*/ 
double duration;  /*��¼��������ʱ�䣬����Ϊ��λ*/ 
#define max 1e2 /*�����ô���*/ 

void f(int a);
int main(){
	int a;
	int i;
	
	scanf("%d",&a);
	start=clock();
	for(i=0;i<max;i++)  /*ѭ�����ú���*/ 
	f(a);
	stop=clock();
	
	duration=((double)(stop-start))/CLK_TCK;
	int r;
	r=duration/1e2;
	printf("%4.12d\n",r);
	return 0;
}

void f(int a){
	a++;
	printf("%d\n",a);
}
