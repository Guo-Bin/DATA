#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1100;

struct bign
{
	int s[maxn], len;
	bign () { memset(s, 0, sizeof(s)); len = 1;}
	bign (int num) { *this = num;}
	bign (const char *num) { *this = num;}
    bign operator = (const int num)  
    {
        char s[maxn];  
        sprintf(s, "%d", num);  
        *this = s;  
        return *this;  
    }
    bign operator = (const char *num)  
    {
        len = strlen(num);  
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';  
        return *this;  
    }
	bign operator + (const bign &b) const //+  
    {  
        bign c;  
        c.len = 0;  
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)  
        {  
            int x = g;  
            if(i < len) x += s[i];  
            if(i < b.len) x += b.s[i];  
            c.s[c.len++] = x % 10;  
            g = x / 10;  
        }  
        return c;  
    }
	void print()
	{
		for(int i = len-1; i >= 0; i--) printf("%d", s[i]);
		printf("\n");
	}
}f[4100];

void init()
{
	f[1] = f[2] = 1;
	for(int i = 2; i <= 4013; i++) f[i] = f[i-1] + f[i-2];
}

int main()
{
	int n;
	init();
	while(scanf("%d", &n) && n)
	{
		f[2*n].print();
	}
	return 0;
}
