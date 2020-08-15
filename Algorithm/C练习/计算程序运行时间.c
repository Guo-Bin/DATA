//时间// 
#include <stdio.h>
#include <time.h>
 
clock_t stop,start;  /*clock_t是clock（）函数返回的变量类型*/ 
double duration;  /*记录函数被测时间，以秒为单位*/ 
#define max 1e2 /*最大调用次数*/ 

void f(int a);
int main(){
	int a;
	int i;
	
	scanf("%d",&a);
	start=clock();
	for(i=0;i<max;i++)  /*循环调用函数*/ 
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
