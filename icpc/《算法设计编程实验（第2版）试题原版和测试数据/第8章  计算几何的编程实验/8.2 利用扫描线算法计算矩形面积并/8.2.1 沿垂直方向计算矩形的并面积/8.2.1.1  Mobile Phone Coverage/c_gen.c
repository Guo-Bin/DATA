#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("3\n"
	       "4.0 4.0 3.0\n"
	       "5.0 6.0 3.0\n"
	       "5.5 4.5 1.0\n"
	       "2\n"
	       "3.0 3.0 3.0\n"
	       "1.5 1.5 1.0\n"
	       "2\n"
	       "1.0 1.0 0.0\n"
	       "1.0 1.0 0.0\n"
	       "90\n");
	for (i=0 ; i<90; i++)
	  printf("100 100 %i\n",i);
	printf("90\n");
	for (i=0 ; i<90; i++)
	  printf("%i 100 0.1\n",i+1);

	for(n=0;n<1000;n++)
	{
		int i;
		i=rand()%98+2;
		printf("%i\n",i);
		while(i)
		{
			printf("%.1f %.1f %.1f\n",
					(rand()%2000)/10.0,
					(rand()%2000)/10.0,
					(rand()%2000)/10.0);
			i--;
		}
	}
	printf("0\n");
	return 0;
}
