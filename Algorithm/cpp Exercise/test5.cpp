#include <stdio.h>
int main()
{
	int i,j,a,t;
	scanf("%d%d",&i,&j);
	if(i>j)
	{a=i;
	i=j;
	j=a;
	}
	for(t=i;t>0;t--)
	{if(i%t==0&&j%t==0)
	 printf("GCD=%d\n",t);
	 break;
	}
	return 0;
}
