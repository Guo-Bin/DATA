PROGRAM circle(input, output);
 
(* Circle Through Three Points *)

VAR
  ax, bx, cx, ay, by, cy,     (* Coordinates of three points *)
  mid1x, mid1y, mid2x, mid2y, (* Coordinates of side midpoints *)
  c1, c2,
  s1, s2,
  xi, yi, r : REAL;           (* Centre and radius of circle *)


PROCEDURE Writenum(num:real);
(* Write out a signed number correctly *)
BEGIN
IF (num >= 0) THEN
  write('+ ')
ELSE
  write('- ');
write(ABS(num):0:3);
END;


FUNCTION Eq(a, b : REAL) : BOOLEAN;
(* Test for equality of two reals, allowing for precision errors *)
BEGIN
Eq := ABS(a-b) < 1E-5;
END;


BEGIN
WHILE NOT eof DO
  BEGIN
  readln(ax, ay, bx, by, cx, cy);    (* Read next three points *)
  (* Find midpoint and slope of two non-vertical bisectors *)
  IF Eq(ay,by) THEN                  (* AB is horizontal so use AC *)
    BEGIN
    mid1x := (ax + cx) / 2;
    mid1y := (ay + cy) / 2;
    s1 := (cx - ax) / (ay - cy);     (* Slope of bisector *)
    END
  ELSE
    BEGIN
    mid1x := (ax + bx) / 2;
    mid1y := (ay + by) / 2;
    s1 := (bx - ax) / (ay - by);     (* Slope of bisector *)
    END;

  IF Eq(cy,by) THEN                  (* BC is horizontal so use AC *)
    BEGIN
    mid2x := (ax + cx) / 2;
    mid2y := (ay + cy) / 2;
    s2 := (cx - ax) / (ay - cy);     (* Slope of bisector *)
    END
  ELSE
    BEGIN
    mid2x := (cx + bx) / 2;
    mid2y := (cy + by) / 2;
    s2 := (cx - bx) / (by - cy);     (* Slope of bisector *)
    END;

  (* Now find the intersection to give the midpoint *)
  c1 := mid1y - (s1 * mid1x);
  c2 := mid2y - (s2 * mid2x);
  xi := (c2 - c1) / (s1 - s2);       (* x coordinate of centre *)
  yi := (s1 * xi) + c1;              (* y coordinate of centre *)

  (* The radius is then the distance to any one of the points *)
  r := sqrt( (ax - xi)*(ax - xi) + (ay - yi)*(ay - yi) );

  (* Now we have the circle data in (xi,yi) and r
     xi is the same as h and yi is the same as k.  Our program
     uses different variables just to be confusing. *)

  (* First form of equation: *)
  write('(x ');
  WriteNum(-xi);
  write(')^2 + (y ');
  WriteNum(-yi);
  writeln(')^2 = ', abs(r):0:3, '^2');

  (* Second form of equation: do the conversion in line *)
  write('x^2 + y^2 ');
  WriteNum(-2*xi);                   (* c = -2h *)
  write('x ');
  WriteNum(-2*yi);                   (* d = -2k *)
  write('y ');
  WriteNum(-r*r + xi*xi + yi * yi);  (* Fixed error here *)
  writeln(' = 0');
  writeln;

  END;  (* of while loop to read all points *)
END.
