#include <stdio.h>
#include <stdlib.h>
struct rect;
struct point
  {
    double x, y;
    int index;
    struct rect *rect;
  };
struct rect
  {
    struct point p1;
    struct point p2;
  }
rect[100];
int nrect;
struct point *xpoints[200];
struct point *ypoints[200];
int used[201];
void 
addrectangle (double x1, double x2, double y1, double y2)
{
  rect[nrect].p1.x = x1;
  rect[nrect].p1.y = y1;
  rect[nrect].p2.x = x2;
  rect[nrect].p2.y = y2;
  rect[nrect].p1.rect = rect + nrect;
  rect[nrect].p2.rect = rect + nrect;
  xpoints[nrect * 2] = &rect[nrect].p1;
  xpoints[nrect * 2 + 1] = &rect[nrect].p2;
  ypoints[nrect * 2] = &rect[nrect].p1;
  ypoints[nrect * 2 + 1] = &rect[nrect].p2;
  nrect++;
}
int
cmpx (const void *p1, const void *p2)
{
  struct point *const *pp1 = p1;
  struct point *const *pp2 = p2;
  if ((*pp1)->x > (*pp2)->x)
    return 1;
  if ((*pp1)->x < (*pp2)->x)
    return -1;
  return 0;
}
int
cmpy (const void *p1, const void *p2)
{
  struct point *const *pp1 = p1;
  struct point *const *pp2 = p2;
  if ((*pp1)->y > (*pp2)->y)
    return 1;
  if ((*pp1)->y < (*pp2)->y)
    return -1;
  return 0;
}
int main ()
{
  int n;
  int p;
  double total, current;
  int num = 1;
  while (1)
    {
      scanf ("%i\n", &n);
      if (!n) return 0;
      nrect=0;
      while (n)
	{
	  double x, y, d;
	  scanf ("%lf %lf %lf", &x, &y, &d);
	  addrectangle (x - d, x + d, y - d, y + d);
	  n--;
	}
      qsort (xpoints, nrect * 2, sizeof (struct point *), cmpx);
      qsort (ypoints, nrect * 2, sizeof (struct point *), cmpy);
      memset (used, 0, (nrect * 2 + 1) * sizeof (int));
      total = current = 0;
      for (p = 0; p < nrect * 2; p++)
	ypoints[p]->index = p;

      for (p = 0; p < nrect * 2 - 1; p++)
	{
	  struct rect *r = xpoints[p]->rect;
	  if (xpoints[p] == &r->p1)
	    {
	      int i;
	      for (i = r->p1.index; i < r->p2.index; i++)
		{
		  if (!used[i])
		    current += ypoints[i + 1]->y - ypoints[i]->y;
		  used[i]++;
		}
	    }
	  else
	    {
	      int i;
	      for (i = r->p1.index; i < r->p2.index; i++)
		{
		  if (used[i] == 1)
		    current -= ypoints[i + 1]->y - ypoints[i]->y;
		  used[i]--;
		}
	    }
	  total += (xpoints[p + 1]->x - xpoints[p]->x) * current;
	}
      printf ("%i %.2f\n", num, total);
      num ++;
    }
  return 0;
}
