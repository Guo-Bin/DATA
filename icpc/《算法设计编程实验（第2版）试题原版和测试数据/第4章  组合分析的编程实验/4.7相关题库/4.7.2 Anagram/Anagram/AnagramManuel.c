/*

1995-96 ACM International Collegiate Programming Contest
Southwestern European Regional Contest
ETH Zurich, Switzerland
December 9, 1995


Problem: Anagram

Idea and Implementation:	Manuel Bleichenbacher, Head Judge

Source file: anagram.c / anagram.p
Input file: anagram.in
Output file: anagram.out

*/

#include <stdio.h>
#include <assert.h>

int dummy;

void sort_str(char* str);
void permute_str(FILE* fout, char* str, int pos);


int main(int argc, char* argv[])
{
	FILE *fin, *fout;
	int i, n;
	char str[1000];
	
	fin = fopen("anagram.in", "r");
	assert( fin != 0 );
	fout = fopen("anagram.out", "w");
	assert( fin != 0 );
	
	dummy = fscanf(fin, "%d", &n);
	assert( dummy == 1 );
	for (i=0; i < n; i++) {
	   dummy = fscanf(fin, "%s", str);
	   assert(dummy == 1);
	   sort_str( str );
	   permute_str( fout, str, 0 );
	}
	
	fclose(fout);
	fclose(fin);
	
	return 0;
}


void sort_str(char* str)
{
	/* brute force sorting */
	char *p, c;
	while (*str) {
		p = str + 1;
		while (*p) {
			if (*p < *str) {
				c = *p;
				*p = *str;
				*str = c;
			}
			p++;
		}
		str++;
	}
}

void permute_str(FILE* fout, char *str, int pos)
{
	char c;
	int i;
	
	if (!str[pos]) {
		fprintf(fout, "%s\n", str);
		return;
	}
	
	permute_str(fout, str, pos+1);
	for (i=pos+1; str[i]; i++) {
		if (str[pos] != str[i]) {
			c = str[pos]; str[pos] = str[i]; str[i] = c;	/* swap */
			permute_str(fout, str, pos+1);
		}
	}
	c = str[pos];
	for (i=pos+1; str[i]; i++)
		str[i-1] = str[i];
	str[i-1] = c;
}
