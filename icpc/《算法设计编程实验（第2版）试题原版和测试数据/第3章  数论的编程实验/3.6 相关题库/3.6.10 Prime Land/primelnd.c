/*
	Problem: 	Prime land
	Author:		Jan Kotas
	Algorithm:	table of greatest prime divisors
	Complexity:	N/A
*/

#include <stdio.h>

int int_pow(int a, int b)
{
	int r;

	for(r = 1; b; b >>= 1)
	{
		if(b & 1) r *= a;
		a *= a;
	}

	return r;
}

int primes[32768];

void main()
{
	int a, b, i, j, x, y;
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

	for(;;)
	{
		scanf("%d%d%c", &a, &b, &c);
		if(!a) break;

		x = int_pow(a, b);

		while(c == ' ')
		{
			scanf("%d%d%c", &a, &b, &c);
			x *= int_pow(a, b);
		}

		x--;

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
}
