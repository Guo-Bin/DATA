/*******************************************************************
	Pgm:	Function Run Fun
   file:	fun.c source code     	ver:	01/11/1999A
   		fun.dat input data
         fun.out expected results
   Pgmr:	RAude email: jpsmith@ior.com

Description:  See 1999 Pacific Northwest Regional Programming Contest.
Problem was submitted by Matthew Merzbacher (matthew@mills.edu).
********************************************************************/
#include<stdio.h>
#include<stdlib.h>				//used for 'exit' in error statements

#define INPUT "C.txt"

FILE *ifp;
int funcW[21][21][21];
int a, b, c;

void
main(void)
{  //Initialize a lookup "cube".  For each set of coordinates (a,b,c) in the
	//compute the value of the cell according to the rules of function w(a,b,c).
   //		1.  If {a,b, or c} = 0, then w(a,b,c) = 1.
   //		2.  If a<b<c, then w(a,b,c) = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c) else
   //			 w(a,b,c) = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
	for (c=0;c<=20;c++)
   	for (b=0;b<=20;b++)
      	for (a=0;a<=20;a++)
         	if (a==0 || b==0 || c==0)
            	funcW[a][b][c] = 1;
            else
            	if (a<b && b<c)
            		funcW[a][b][c] = funcW[a][b][c-1] + funcW[a][b-1][c-1]
                   - funcW[a][b-1][c];
               else
                  funcW[a][b][c] = funcW[a-1][b][c] + funcW[a-1][b-1][c]
                   + funcW[a-1][b][c-1] - funcW[a-1][b-1][c-1];

	if ( (ifp=fopen(INPUT,"r")) == NULL)
   	{printf("Cannot open %s file.\n",INPUT); exit;}

   //read the triplet from input and output its value from the cube
   fscanf(ifp,"%d%d%d", &a, &b, &c);
   while (!(a==-1 && b==-1 && c==-1))
   {	if (a<=0 || b<=0 || c<=0)
   		printf("w(%d, %d, %d) = 1\n", a, b, c);
   	else
      	if (a>20 || b>20 || c>20)
         	printf("w(%d, %d, %d) = %d\n", a, b, c, funcW[20][20][20]);
         else
         	printf("w(%d, %d, %d) = %d\n", a, b, c, funcW[a][b][c]);
      fscanf(ifp,"%d%d%d", &a, &b, &c);
   }
}
