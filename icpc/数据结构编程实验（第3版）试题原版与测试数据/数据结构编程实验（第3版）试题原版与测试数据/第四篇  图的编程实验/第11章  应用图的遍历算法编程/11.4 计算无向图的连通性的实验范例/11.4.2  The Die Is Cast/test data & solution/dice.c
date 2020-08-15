/* SWERC'98 - The die is cast */
/* 10/17/98 - Matthias Ruhl   */

#include <stdio.h>

#define MAXWIDTH 50
#define MAXHEIGHT 50

FILE *inp;
int w,h,case_no=1;
char data[MAXHEIGHT][MAXWIDTH+1];

int read_data()
{
  int i;

  fscanf(inp,"%d %d",&w,&h);
  if(w == 0 && h == 0) return 0;
  for(i=0;i<h;i++)
    fscanf(inp,"%s",data[i]);
  return 1;
}

int delete_dice(int x, int y, char d)
{
  if(x < 0 || x >= w || y < 0 || y >= h) return 0;
  if(data[y][x] == '.') return 0;
  if(data[y][x] == d)
    {
      data[y][x] = d=='*'?'.':'*';
      return delete_dice(x+1,y,d)+
	delete_dice(x-1,y,d)+
	delete_dice(x,y+1,d)+
	delete_dice(x,y-1,d);
    }
  if(d == 'X') return 0;
  delete_dice(x,y,'X');
  return 1+delete_dice(x,y,'*');
}

void process_data()
{
  int freq[6],i,j,x,y;

  for(i=0;i<6;i++) freq[i] = 0;
  for(x=0;x<w;x++)
    for(y=0;y<h;y++)
      if(data[y][x] == '*')
	freq[delete_dice(x,y,'*')-1]++;
  printf("Throw %d\n",case_no++);
  for(i=0;i<6;i++)
    for(j=0;j<freq[i];j++) printf("%d ",i+1);
  printf("\n\n");
}

int main()
{
  inp = fopen("dice.in","r");
  while(read_data())
    process_data();
  fclose(inp);
  return 0;
}
