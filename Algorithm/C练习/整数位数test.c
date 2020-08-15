/*判断整数位数*/ 
#include <stdio.h>

int main(){
    int number;
    int a,i=0;
    
    scanf("%d",&number);
    do{
    	a=number%10;
    	a=number-a;
    	i++;
    }while(a>10);
    printf("%d",i);
	return 0;
}
