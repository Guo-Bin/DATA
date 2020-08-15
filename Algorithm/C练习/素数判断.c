//练习题//
/*素数判断*/ 
#include <stdio.h>
/*
int g(int a);
int main(){
	int a;
	int s;
	
	scanf("%d",&a);
	s=g(a);
	if(s){
	printf("不是素数");
}
	else{
	printf("是素数");
}
	return 0;
}

int g(int a){
	int i;
	int s;
	
	for(i=2;i<=a-1;i++){
		s=a%i;
		if(s==0){ 
		return 1;
	}
}return 0;
}
*/
#include <math.h>  //只需要从2试到a的平方根即可// 
int f(int a);
int main(){
	int a;
	int s;
	
	scanf("%d",&a);
	s=f(a);
	if(s){
		printf("是素数\n");
	}else{
		printf("不是素数\n");
	}
	return 0;
}

int f(int a){
	double s=sqrt(a);
	int i,m;
	
	for(i=2;i<=s;i++){
		m=a%i;
		if(m==0){
			return 0;
		}
	}
	return 1;
}
