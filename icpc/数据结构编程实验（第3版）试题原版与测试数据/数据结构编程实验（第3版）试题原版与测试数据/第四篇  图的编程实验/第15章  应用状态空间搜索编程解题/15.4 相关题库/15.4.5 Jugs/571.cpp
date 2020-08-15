#include <stdio.h> 
#include <stdlib.h> 

#define min(a,b) (((a)<(b)) ? (a) : (b) ) 

typedef struct queueItem 
{ 
  unsigned long element; 
  struct queueItem *next; 
} queueItem; 

typedef struct Queue 
{ 
  queueItem *first, *last; 
} Queue; 

void queueinit(Queue* q) 
{ 
  queueItem *dummy = (queueItem*) malloc(sizeof(*dummy)); 
  q->first = q->last = dummy; 
  dummy->next = dummy; 
} 

void enqueue(Queue* q, unsigned long elem) 
{ 
  queueItem *nu = (queueItem*) malloc(sizeof(*nu)); 
  nu->element = elem; 
  nu->next = q->last->next; 
  q->last = q->last->next = nu; 
} 

unsigned long dequeue(Queue* q) 
{ 
  queueItem *old = q->first->next; 
  unsigned long elem = old->element; 
  q->first->next = old->next; 
  if (q->last == old) 
    { 
      q->last = q->first; 
      q->first->next = q->first; 
    } 
  free((char*) old); 
  return elem; 
} 

void queueelim(Queue* q) 
{ 
  queueItem* curr = q->first->next; 
  while (curr != q->first) 
    { 
      queueItem* old = curr; 
      curr = curr->next; 
      free((char*) old); 
    } 
  free((char*) curr); 
} 

#define FILL_A       0 
#define FILL_B       1 
#define EMPTY_A      2 
#define EMPTY_B      3 
#define POUR_A_B     4 
#define POUR_B_A     5 

#define UNVISITED (unsigned long)(-1) 

unsigned long *initialize(unsigned a, unsigned b) 
{ 
  unsigned long sz = (a+1)*(b+1); 
  unsigned long* p = (unsigned long*) malloc(sz*sizeof(*p)); 
  while (sz--) 
    p[sz] = UNVISITED; 
  return p; 
} 

int compute_soln(unsigned a, unsigned b, unsigned n, unsigned long *parent) 
{ 
  Queue q; 
  unsigned long stat; 
  if (n == 0) 
    return 0; 

  queueinit(&q); 
  enqueue(&q,0); 
  parent[0] = 0; 
  while (1) 
    { 
      unsigned long jugStat = dequeue(&q); 
      int action; 
      for (action = FILL_A; action <= POUR_B_A; ++action) 
        { 
          unsigned long cb = jugStat % (b+1); 
          unsigned long ca = jugStat / (b+1); 
          switch (action) 
            { 
            case FILL_A: 
              ca = a; 
              break; 
            case FILL_B: 
              cb = b; 
              break; 
            case EMPTY_A: 
              ca = 0; 
              break; 
            case EMPTY_B: 
              cb = 0; 
              break; 
            case POUR_A_B: 
              { 
                unsigned sum = ca + cb; 
                cb = min(sum,b); 
                ca = sum - cb; 
              } break; 
            case POUR_B_A: 
              { 
                unsigned sum = ca + cb; 
                ca = min(sum,a); 
                cb = sum - ca; 
              } break; 
            } 
          stat = ca * (b+1) + cb; 
          if (parent[stat] == UNVISITED) 
            { 
              parent[stat] = jugStat; 
              if (stat%(b+1) == n) 
                { 
                  queueelim(&q); 
                  return stat; 
                } 
              enqueue(&q, stat); 
            } 
        } 
    } 
} 

void print_soln(FILE *outfp, unsigned long stat, 
                unsigned a, unsigned b, 
                unsigned long *parent) 
{ 
  if (stat == 0) 
    return; 
  print_soln(outfp, parent[stat], a, b, parent); 

  { 
    unsigned long jugStat = parent[stat]; 
    unsigned long cb = jugStat % (b+1); 
    unsigned long ca = jugStat / (b+1); 
    unsigned long nb = stat % (b+1); 
    unsigned long na = stat / (b+1); 

    if (na + nb == ca + cb) 
      { 
        if (na > ca) 
          fprintf(outfp, "pour B A\n"); 
        else 
          fprintf(outfp, "pour A B\n"); 
      } 
    else if (na != ca) 
      { 
        if (na == 0) 
          fprintf(outfp, "empty A\n"); 
        else 
          fprintf(outfp, "fill A\n"); 
      } 
    else if (nb != cb) 
      { 
        if (nb == 0) 
          fprintf(outfp, "empty B\n"); 
        else 
          fprintf(outfp, "fill B\n"); 
      } 
  } 
} 

int main(void) 
{ 
  FILE *infp = fopen("jugs.dat", "r"); 
  FILE *outfp= fopen("jugs.out", "w"); 
  
  while (!feof(infp)) 
    { 
      unsigned long* parent; 
      unsigned long stat; 
      unsigned a,b,n; 
      fscanf(infp, "%d %d %d\n", &a, &b, &n); 
      parent = initialize(a,b); 
      stat = compute_soln(a,b,n,parent); 
      print_soln(outfp, stat, a, b, parent); 
      fprintf(outfp, "success\n"); 
      free((char*) parent); 
    } 
  fclose(infp); 
  fclose(outfp); 
  return(0); 
} 
