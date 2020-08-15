#include <stdio.h>
#include <stdlib.h>

int primes[32768];

void main()
{
	int i, j, x, y, z;
	char c;

	primes[1] = 1;

	for(i = 2; i <= 32768; i++)
	{
		x = i;

		for(j = 2; j * j <= x; j++)
		{
			if(primes[j] != j) /* only primes */
				continue;

			while(x % primes[j] == 0)
				x /= (y = primes[j]);
		}

		primes[i] = (x == 1) ? y : x;
	}

	for(z = 0; z < 2000; z++)
	{
		x = 3 + rand() % 32765;

		c = 0;

		while(x > 1)
		{
			i = primes[x];
			j = 0;

			while(i == primes[x])
			{
				x /= i;
				j++;
			}

			if(c) printf(" ");
			else c = 1;

			printf("%d %d", i, j);			
		}

		printf("\n");
	}

	printf("0\n");
}
