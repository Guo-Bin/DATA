/*

ACM International Collegiate Programming Contest
1995-96 Southwestern European Regional Contest
ETH Zurich, Switzerland
Decmeber 9, 1995


Problem: Intersection

Idea:			Andrea Kennel, ETH Zurich
Implementation:	Manuel Bleichenbacher, Chief Judge

Source file: intersection.c or intersection.p
Input file:  intersection.in
Output file: intersection.out

*/


#include <stdio.h>
#include <assert.h>


typedef enum {
	FALSE = 0,
	TRUE = 1
} bool;

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point p1;
	Point p2;
} Line;

typedef struct {
	Point topLeft;
	Point bottomRight;
} Rectangle;


int ccw( Point p0, Point p1, Point p2 );
bool intersect( Line l1, Line l2 );
bool intersectRect( Rectangle r, Line l );


/* Taken from Robert Sedgewick, Algorithms in C++ */

/*  returns whether, in traveling from the first to the second
	to the third point, we turn counterclockwise (+1) or not (-1) */
 
int ccw( Point p0, Point p1, Point p2 )
{
	int dx1, dx2, dy1, dy2;
	
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	
	if (dx1*dy2 > dy1*dx2)
		return +1;
	if (dx1*dy2 < dy1*dx2)
		return -1;
	if ((dx1*dx2 < 0) || (dy1*dy2 < 0))
		return -1;
	if ((dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2))
		return +1;
	return 0;
}


/* Taken from Robert Sedgewick, Algoritthms in C++ */

bool intersect( Line line1, Line line2 )
{
	return (( ccw(line1.p1, line1.p2, line2.p1)
			* ccw(line1.p1, line1.p2, line2.p2)) <= 0)
		&& (( ccw(line2.p1, line2.p2, line1.p1)
			* ccw(line2.p1, line2.p2, line1.p2)) <= 0);
}


bool intersectRect( Rectangle rect, Line line )
{
	Line line1, line2, line3, line4;
	int tmp;
	
	line1.p1 = rect.topLeft;
	line1.p2 = line1.p1; line1.p2.x = rect.bottomRight.x;
	
	line2.p1 = line1.p2;
	line2.p2 = rect.bottomRight;
	
	line3.p1 = line2.p2;
	line3.p2 = rect.topLeft; line3.p2.y = rect.bottomRight.y;
	
	line4.p1 = line3.p2;
	line4.p2 = line1.p1;
	
	if (intersect(line1, line) || intersect(line2, line)
				|| intersect(line3, line) || intersect(line4, line))
		return TRUE;	/* line intersects outline of rectangle */
	
	/*	Now the line could still be completely within the rectangle.
		This would also count as an intersection. */
	
	/* Normalize rectangle */
	if (rect.bottomRight.x < rect.topLeft.x) {
		tmp = rect.bottomRight.x;
		rect.bottomRight.x = rect.topLeft.x;
		rect.topLeft.x = tmp;
	}
	if (rect.bottomRight.y < rect.topLeft.y) {
		tmp = rect.bottomRight.y;
		rect.bottomRight.y = rect.topLeft.y;
		rect.topLeft.y = tmp;
	}
	
	/* Now we have for x and y: rect.bottomRight >= rect.topLeft */
	return (line.p1.x >= rect.topLeft.x && line.p1.x <= rect.bottomRight.x
		&& line.p1.y >= rect.topLeft.y && line.p1.y <= rect.bottomRight.y);
}


int main( int argc, char* argv[] )
{
	FILE*	fin;
	FILE*	fout;
	int		n, dummy, i;
	Rectangle	rect;
	Line		line;
	
	fin = fopen("intersection.in", "r");
	assert( fin != 0 );
	fout = fopen("intersection.out", "w");
	assert( fout != 0 );
	
	dummy = fscanf( fin, "%d", &n );
	assert( dummy == 1 );
	
	for (i=0; i < n; i++) {
		dummy = fscanf( fin, "%d %d %d %d",
			&line.p1.x, &line.p1.y,
			&line.p2.x, &line.p2.y );
		assert( dummy == 4 );
		
		dummy = fscanf( fin, "%d %d %d %d",
			&rect.topLeft.x, &rect.topLeft.y,
			&rect.bottomRight.x, &rect.bottomRight.y );
		assert( dummy == 4 );
		
		fprintf( fout, "%c\n",
			intersectRect( rect, line ) ? 'T' : 'F' );
	}
	
	fclose( fin );
	fclose( fout );
	
	return 0;
}
