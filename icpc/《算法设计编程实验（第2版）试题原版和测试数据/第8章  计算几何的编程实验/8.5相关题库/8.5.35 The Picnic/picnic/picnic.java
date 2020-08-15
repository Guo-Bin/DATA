/*
 *  Solution to the problem "Picnic"
 *  Joris van Rantwijk, Sep 2002
 */

import java.io.StreamTokenizer;
import java.io.FileReader;
import java.io.IOException;

class picnic
{

	// Input limits
	static final int MAX_OBJECTS = 99;
	static final int MAX_COORD = 1000;

	// Problem data
	static int m;
	static int[] xcoord;
	static int[] ycoord;

	// Answer
	static int maxArea;


	// Read an integer from the input stream and return its value.
	static int getInt(StreamTokenizer f) throws IOException
	{
		f.nextToken();
		return Integer.parseInt(f.sval);
	}


	// Calculate the area of the triangle i,j,k. The result will be
	// positive if i,j,k is counter-clockwise, negative if clockwise.
	static int triArea(int i, int j, int k)
	{
		return (xcoord[k] - xcoord[j]) * (ycoord[i] - ycoord[j]) +
		       (ycoord[k] - ycoord[j]) * (xcoord[j] - xcoord[i]);
	}


	// Check that the triangle i,j,k contains no points from sel[].
	// Return true if the triangle is empty. Points on the boundary
	// are not counted as inside the triangle.
	static boolean triEmpty(int i, int j, int k, int nsel, int[] sel)
	{
		for (int r = 0; r < nsel; r++) {
			int p = sel[r];
			if ( triArea(i, j, p) > 0 &&
			     triArea(j, k, p) > 0 &&
				 triArea(k, i, p) > 0 )
				return false;
		}
		return true;
	}


	// Check if a point from sel[] falls on the line segment a-b.
	static boolean pointOnLine(int a, int b, int nsel, int[] sel)
	{
		for (int r = 0; r < nsel; r++) {
			int p = sel[r];
			if (triArea(a, b, p) == 0) {
				// p falls on the infinite line through a and b
				int xa = xcoord[a], ya = ycoord[a];
				int xb = xcoord[b], yb = ycoord[b];
				int xp = xcoord[p], yp = ycoord[p];
				if ( (xa > xp && xp > xb) || (xa < xp && xp < xb) ||
				     (ya > yp && yp > yb) || (ya < yp && yp < yb) )
					return true;
			}
		}
		return false;
	}


	// Scan through the sorted points and return the area of the
	// largest possible convex poly with the given starting point.
	static void polyScan(int p0, int nsorted, int[] sorted)
	{
		// We maintain a set of "contexts" in the cLastPoint, cPrevPoint,
		// cArea arrays. A context is defined by the last two points added
		// to a convex polygon, and labeled with the area of the polygon.
		// This is done because the last two points are needed to determine
		// whether some new point can be added to the polygon. The list of
		// contexts is kept grouped by cLastPoint, and then by cPrevPoint.
		int ncontext = 0;
		int[] cLastPoint = new int[m*m/2];
		int[] cPrevPoint = new int[m*m/2];
		int[] cArea      = new int[m*m/2];


		// The triEmpty check has O(m) complexity so we can not call
		// it unlimited in the inner loop. We cache the results so that
		// the function is called at most once for each (pl, px) pair
		// instead of once for each (pp, pl, px) triplet. The grouping
		// property of the context list helps us here.
		int cache_empty_px = -1;
		int cache_empty_pl = -1;
		boolean cache_empty = false;

		// The pointOnLine check has O(m) complexity so we can not call
		// it unlimited in the inner loop. We pre-calculate its results
		// so that the function is called exactly once for each point.
		boolean[] pointonline = new boolean[m];
		for (int i = 0; i < nsorted; i++) {
			int px = sorted[i];
			pointonline[px] = pointOnLine(p0, px, nsorted, sorted);
		}

		// Scan through the sorted list of points
		for (int i = 0; i < nsorted; i++) {

			int px = sorted[i];
			int oldn = ncontext;

			// Add the 2-point poly from p0, px as a new context
			cLastPoint[ncontext] = px;
			cPrevPoint[ncontext] = p0;
			cArea[ncontext] = 0;
			ncontext++;

			// Scan through all existing contexts
			for (int j = 0; j < oldn; j++) {

				int pl = cLastPoint[j];
				int pp = cPrevPoint[j];

				// If we add px, would the poly remain convex ?
				if (triArea(pp, pl, px) <= 0)
					continue;

				// If we add px, would the poly remain empty ?
				if (cache_empty_pl != pl || cache_empty_px != px) {
					cache_empty_pl = pl;
					cache_empty_px = px;
					cache_empty = triEmpty(p0, pl, px, nsorted, sorted);
				}
				if (!cache_empty)
					continue;

				// Points on the edge p0-pl are also not allowed, unless
				// this is the first real triangle (then p0-pl is a boundary
				// of the polygon).
				if (pp != p0 && pointonline[pl])
					continue;

				// Ok, we can add px to this poly
				// Calculate the new area
				int a = cArea[j] + triArea(p0, pl, px);

				// Perhaps the context (pl, px) already exists.
				// If so, then it must be the curent last element of the
				// context set. This is a result of the grouping property.
				if (cLastPoint[ncontext-1] == px && cPrevPoint[ncontext-1] == pl) {
					// Context already exists -> update the area
					if (a > cArea[ncontext-1])
						cArea[ncontext-1] = a;
				} else {
					// Context is new -> add it
					cLastPoint[ncontext] = px;
					cPrevPoint[ncontext] = pl;
					cArea[ncontext] = a;
					ncontext++;
				}
			}

		}

		// Get the largest area of all contexts and update global maximum
		for (int i = 0; i < ncontext; i++) {
			if (cArea[i] > maxArea)
				maxArea = cArea[i];
		}

	}


	// Sort the selected points by angle (insertion sort)
	static void sortPoints(int p0, int nsorted, int[] sorted)
	{
		for (int i = 1; i < nsorted; i++) {
			int t = sorted[i];
			int j = i;
			while (j > 0 && triArea(p0, t, sorted[j-1]) > 0) {
				sorted[j] = sorted[j-1];
				j--;
			}
			sorted[j] = t;
		}
	}


	// Solve the problem
	static void solveProblem()
	{
		// Start with zero area
		maxArea = 0;

		// Try all points once as a starting point for the algorithm
		for (int i = 0; i < m; i++) {

			int x0 = xcoord[i];
			int y0 = ycoord[i];

			// Select all points for which (x > x0) || (x == x0 && y > y0)
			int nsorted = 0;
			int[] sorted = new int[m];
			for (int j = 0; j < m; j++) {
				if (xcoord[j] > x0 || (xcoord[j] == x0 && ycoord[j] > y0))
					sorted[nsorted++] = j;
			}

			// Need at least one other point
			if (nsorted == 0)
				continue;

			// Sort the selected points by angle
			sortPoints(i, nsorted, sorted);

			// Scan through the points and find best area
			polyScan(i, nsorted, sorted);

		}
	}


	// Main program
	public static void main(String args[])
	{
		try {

			StreamTokenizer f = new StreamTokenizer(
			  new FileReader("e.in"));
			f.resetSyntax();
			f.whitespaceChars(0, 32);
			f.wordChars(33, 127);

			int runs = getInt(f);

			for (int r = 1; r <= runs; r++) {

				// Read input
				m = getInt(f);
				if (m <= 2 || m > MAX_OBJECTS)
					throw new Error("Out of range value for m in run " + r);
				xcoord = new int[m];
				ycoord = new int[m];
				for (int i = 0; i < m; i++) {
					xcoord[i] = getInt(f);
					ycoord[i] = getInt(f);
					if ( xcoord[i] < 0 || xcoord[i] > MAX_COORD ||
					     ycoord[i] < 0 || ycoord[i] > MAX_COORD )
						throw new Error("Out of range coordinate value in run " + r);
				}

				// Solve the problem
				solveProblem();

				// Write the answer
				String astr = "" + (maxArea / 2) + "." + ((maxArea % 2) * 5);
				System.out.println(astr);
			}

		} catch (IOException e) {
			System.err.println(e);
		}
	}

}

/* End */
