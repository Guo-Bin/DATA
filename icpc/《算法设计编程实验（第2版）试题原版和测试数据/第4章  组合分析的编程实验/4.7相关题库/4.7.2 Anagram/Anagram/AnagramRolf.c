/*

1995-96 ACM International Collegiate Programming Contest
Southwestern European Regional Contest
ETH Zurich, Switzerland
December 9, 1995


Problem: Anagram

Idea:			Rolf Strebel, ETH Zurich
Implementation:	Manuel Bleichenbacher, Head Judge

Source file: anagram.c / anagram.p
Input file: anagram.in
Output file: anagram.out

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096

int no, nofchars;
char chars[256];
int cnt[256];
int incnt[256];
char line[BUFSIZE+1];
char pat[BUFSIZE+1];

FILE *fin, *fout;

void permute (int pos)
{
  int k;

  if (pos == nofchars) {
    pat[pos] = '\0'; fprintf (fout, "%s\n", pat);
  } else {
    for (k = 0; k < no; k++) {
      if (cnt[k] > 0) {
       pat[pos] = chars[k]; 
       cnt[k]--; permute (pos+1); cnt[k]++;
      }
    }
  }
}
  
int main (int argc, char **argv)
{
  int i, no_in;
  char *str;

  if ((fin = fopen ("anagram.in","r")) == NULL) exit (1);
  if ((fout = fopen ("anagram.out","w")) == NULL) exit (1);
  
  fscanf (fin, "%i", &no_in);
  while (no_in-- > 0) {
    for (i = 0; i < 256; i++) incnt[i] = 0;
    fscanf (fin, "%s", line);
    for (str = line; isalpha(*str); str++) {
      incnt[(int)*str] += 1;
    }
    for (no = 0, nofchars = 0, i = 0; i < 256; i++) {
      if (incnt[i] > 0) {
       chars[no] = i; cnt[no] = incnt[i]; no++;
       nofchars += incnt[i];
      }
    }
    permute (0);
  }

  fclose (fout);
  fclose (fin);
  return (0);
}
