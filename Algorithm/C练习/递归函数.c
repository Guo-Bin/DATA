//ѭ��// 

#include <stdio.h>

/*int main(){
	int a;
	
	scanf("%d",&a);
	for(;a>0;a--)
		printf("%d\n",a);
		
	return 0;
}*/

//�ݹ�//
/*void f(int a);

int main(){
    int a;
    
    scanf("%d",&a);
    f(a);
    return 0;
}

void f(int a){
	if(a>0){
		printf("%d\n",a);
		a--;
		f(a);
	}
}*/

//�ݹ�׳�//
void g(int a,int s);

int main(){
    int a;
    int s=1;
    
    scanf("%d",&a);
    g(a,s);
	return 0;
}

void g(int a,int s){
	if(a>1){
		s*=a;
		a--;
		g(a,s);
	}else{
		printf("%d",s);
	}
}
