//初识高精度 
#include <stdio.h>
#include <string.h>

struct num {
	char s[101];
	int ls;
};
struct num a[20];

int main()
{
	int n,flag = 0;
	scanf("%d",&n); //读入总人数n 
	//读入票数 
	for(int i = 0; i < n; i++) {
		scanf("%s",&a[i].s);
		a[i].ls = strlen(a[i].s);
	}
	//取第一个 
	int t = 0;
	//从第二个开始遍历 
	for(int i = 1; i < n; i++) {
		if(a[t].ls < a[i].ls) t = i; //位数小，更新下标 
		else if(a[t].ls == a[i].ls){ //位数相等，再判断 
			//逐个位数判断 
			for(int j = 0; j < a[t].ls; j++) { 
				if(a[t].s[j]-'0' > a[i].s[j]-'0'){
					flag = 1;//t大则标记 
					break;
				} else if(a[t].s[j]-'0' < a[i].s[j]-'0') {
					break;
				}
			}
			//判断是如何退出循环 
			if(flag == 1){
				flag = 0;
				continue;
			} else if(flag == 0) t = i;//更新t 
		}
		else if(a[t].ls > a[i].ls) continue;
	}
	printf("%d\n",t+1);
	printf("%s",a[t].s);
	return 0;
}

