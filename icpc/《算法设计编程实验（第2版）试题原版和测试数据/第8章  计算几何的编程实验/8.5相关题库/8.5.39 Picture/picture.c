/*

  PICTURE - C version

  Author: Michel Wermelinger (mw@di.fct.unl.pt)

*/



#include <stdio.h>



#define max(a, b) ((a) > (b) ? (a) : (b))

#define min(a, b) ((a) > (b) ? (b) : (a))



typedef struct

{

int sign, x, y, X, Y; /* odd/even level, lower left, upper right corner  */

} pict;



#define MAX_PICT 10000

/*   memory: 1O*MAX-PICT bytes;

*/



void intersect (pict p1, pict p2, pict *p3)

{

p3->x = max(p1.x, p2.x); p3->y = max(p1.y, p2.y);

p3->X = min(p1.X, p2.X); p3->Y = min(p1.Y, p2.Y);

p3->sign = -p1.sign * p2.sign;

}



int main ()

{

long perim = 0;

long npf, npt = 0; /* number of pictures in file and total */

FILE *f;

pict p[MAX_PICT];

int i, j, k;



if ((f = fopen("PICTURE.IN", "r")) == NULL)

    {printf("Empty file!\n");

     return 0;}



fscanf (f, "%d\n", &npf);



for (i = 0; i < npf ; i++) {

     k = npt++;

     fscanf(f, "%d %d %d %d\n", &p[k].x, &p[k].y, &p[k].X, &p[k].Y);

     p[k].sign = 1;

     for (j = 0;  j < k; j++)  {

       intersect  (p[j] , p[k] , &p[npt]);

       if ((p[npt].X > p[npt].x && p[npt].Y >= p[npt].y) ||

           (p[npt].X == p[npt].x && p[npt].Y > p[npt].y))  /* p[npt] exists */

         if (p[npt].x == p[k].x && p[npt].X == p[k].X &&

             p[npt].y == p[k].y && p[npt].Y == p[k].Y)  {  /* identical
pictures */

            npt = k;

            break;

         }  else npt++;

     }

}

fclose(f);



for (i = 0; i < npt; i++)

   perim += p[i].sign * 2 * (p[i].X - p[i].x + p[i].Y - p[i].y);



printf ("Perimeter=%ld\n", perim);



f = fopen("PICTURE.OUT", "w");

fprintf (f, "%ld\n", perim);

fclose(f);



}





