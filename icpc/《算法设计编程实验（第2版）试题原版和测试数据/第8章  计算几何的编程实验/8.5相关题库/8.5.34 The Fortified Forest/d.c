#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXT 16
#define INFTY 1e20
#define VINFTY 2000000000

#define sqr(X) ((X)*(X))

struct point {
  int x, y;
};

struct tree {
  struct point pos;
  int cost, len;
  int n;
};

int t;
struct tree forest[MAXT];
int hn;
int hull[MAXT];
double flen, restlen, treelen;
int cn;
int cut[MAXT];
int actprice, minprice;
int actcut[MAXT], acn;
char used[MAXT];

void ReadInp(void)
{
  int i;

  scanf("%d", &t);
  if (!t)
    exit(0);
  for (i = 0; i < t; i++) {
    scanf("%d %d %d %d", &forest[i].pos.x, &forest[i].pos.y, &forest[i].cost, &forest[i].len);
    forest[i].n = i;
  }
}

int tree_cmp(const void *pt1, const void *pt2)
{
  const struct tree *t1 = pt1, *t2 = pt2;
  if (t1->cost/(float)t1->len == t2->cost/(float)t2->len)
    return 0;
  else if (t1->cost/(float)t1->len < t2->cost/(float)t2->len)
    return -1;
  else
    return 1;
}

void Hull(int *hn, int *hull, int *forn, int t)
{
  int startv, actv, midv;
  int i, minx, maxx, minv;
  double mins;
  int run;

/*  printf("Going to hull vertices: ");
  for (i = 0; i < t; i++)
    printf("%d ", forest[forn[i]].n);
  printf("\n");*/
  maxx = minx = forest[forn[0]].pos.x;
  midv = startv = 0;
  *hn = 0;
  for (i = 0; i < t; i++)
    if (minx > forest[forn[i]].pos.x) {
      startv = i;
      minx = forest[forn[i]].pos.x;
    }
    else if (maxx < forest[forn[i]].pos.x) {
      midv = i;
      maxx = forest[forn[i]].pos.x;
    }
  hull[(*hn)++] = forn[startv];
  actv = startv;
  for (run = 1; run != -3; run -= 2, midv = startv) {
    do {
      mins = INFTY;
      minv = 0;
      for (i = 0; i < t; i++)
       if (i != actv && run*forest[forn[i]].pos.x >= run*forest[forn[actv]].pos.x) {
         if (forest[forn[i]].pos.x == forest[forn[actv]].pos.x) {
           if (run*forest[forn[i]].pos.y < run*forest[forn[actv]].pos.y) {
             mins = -INFTY;
             minv = i;
           }
           else if (mins >= INFTY) {
             mins = INFTY;
             minv = i;
           }
         }
         else {
           if (mins > (forest[forn[i]].pos.y - forest[forn[actv]].pos.y) / (double)(forest[forn[i]].pos.x - forest[forn[actv]].pos.x)) {
             mins = (forest[forn[i]].pos.y - forest[forn[actv]].pos.y) / (double)(forest[forn[i]].pos.x - forest[forn[actv]].pos.x);
             minv = i;
           }
         }
       }
      hull[(*hn)++] = forn[minv];
      actv = minv;
    }
    while (actv != midv);
  }
  flen = 0;
  for (i = 0; i < (*hn)-1; i++)
    flen += sqrt(sqr(forest[hull[i]].pos.x-forest[hull[i+1]].pos.x)+sqr(forest[hull[i]].pos.y-forest[hull[i+1]].pos.y));
/*  printf("Vertices in hull: ");
  for (i = 0; i < *hn; i++)
    printf("%d ", forest[hull[i]].n);
  printf("\n");*/
}

void Track(int fv, int hn, int *hull)
{
  int tfn, i, j;
  int tfor[MAXT];
  int thull[MAXT], thn;
  double oflen;

/*  printf("Tracking: hn=%d, hull: ", hn);
  for (i = 0; i < hn; i++)
    printf("%d ", hull[i]);
  printf("\n");*/
  for (i = fv; i < t; i++) {
    oflen = flen;
    actcut[acn++] = i;
    used[i] = 1;
    for (j = 0; j < hn-1 && hull[j] != i; j++);
    if (j < hn-1) {	/* Point in hull? */
      tfn = 0;
      for(j = 0; j < t; j++)
	if (!used[j])
          tfor[tfn++] = j;
      Hull(&thn, thull, tfor, tfn);
    }
    else {
      thn = hn;
      memcpy(thull, hull, hn*sizeof(int));
    }
    actprice += forest[i].cost;
    treelen += forest[i].len;
/*    printf("Cut tree %d[%d] - treelen=%f flen=%f, price=%d\n", forest[i].n, i, treelen, flen, actprice);*/
    if (flen <= treelen && actprice < minprice) {
      cn = acn;
      memcpy(cut, actcut, acn*sizeof(int));
      minprice = actprice;
      restlen = treelen - flen;
    }
    if (flen > treelen && actprice < minprice && i < t-1 && thn > 1)
      Track(i+1, thn, thull);
    actprice -= forest[i].cost;
    treelen -= forest[i].len;
    flen = oflen;
    used[i] = 0;
    acn--;
  }
}

int cut_cmp(const void *ap, const void *bp)
{
  int a = *(const int *)ap, b = *(const int *)bp;
  if (a < b)
    return -1;
  else if (a > b)
    return 1;
  return 0;
}

int main(void)
{
  int n = 1, i;
  int tfor[MAXT];

  while (1) {
    ReadInp();
    flen = 0;
    acn = actprice = hn = cn = 0;
    minprice = VINFTY;
    qsort(forest, t, sizeof(struct tree), tree_cmp);
    for (i = 0; i < t; i++)
      tfor[i] = i;
    memset(used, 0, sizeof(used));
    Hull(&hn, hull, tfor, t);
    Track(0, hn, hull);
    for (i = 0; i < cn; i++)
      cut[i] = forest[cut[i]].n+1;
    qsort(cut, cn, sizeof(int), cut_cmp);
    if (n != 1)
      printf("\n");
    printf("Forest %d\n", n);
    printf("Cut these trees:");
    for (i = 0; i < cn; i++)
      printf(" %d", cut[i]);
    printf("\nExtra wood: %.2f\n", restlen);
/*    printf("Price: %d\n", minprice);*/
    n++;
  }

  return 0;
}

