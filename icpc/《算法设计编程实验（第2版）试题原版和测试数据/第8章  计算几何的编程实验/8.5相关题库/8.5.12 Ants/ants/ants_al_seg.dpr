(*--------------------------------------------------------------*)
(* ACM ICPC 2007-2008                                           *)
(* Northeastern European Regional Contest                       *)
(* St Petersburg - Barnaul - Tashkent - Batumi, November 28, 200*)
(*--------------------------------------------------------------*)
(* Problem A. Ants                                              *)
(*--------------------------------------------------------------*)
(* Solution                                                     *)
(*                                                              *)
(* Author                Andey Lopatin                          *)
(*--------------------------------------------------------------*)
 
{$O-,Q+,R+}
uses Math;
const MaxN = 100;

function intersect (x1, y1, x2, y2, x3, y3, x4, y4 : integer) : boolean;
var mx1, my1, mx2, my2, mx3, my3, mx4, my4 : integer;
    v1, v2 : int64;
begin
  mx1 := min (x1, x2);
  my1 := min (y1, y2);
  mx2 := max (x1, x2);
  my2 := max (y1, y2);
  mx3 := min (x3, x4);
  my3 := min (y3, y4);
  mx4 := max (x3, x4);
  my4 := max (y3, y4);
  if (mx4 < mx1) or (mx2 < mx3) or (my4 < my1) or (my2 < my3) then begin
    Result := false; exit
  end;
  v1 := (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
  v2 := (x4 - x1) * (y2 - y1) - (x2 - x1) * (y4 - y1);
  if v1 * v2 > 0 then begin
    Result := false; exit
  end;
  v1 := (x1 - x3) * (y4 - y3) - (x4 - x3) * (y1 - y3);
  v2 := (x2 - x3) * (y4 - y3) - (x4 - x3) * (y2 - y3);
  Result := v1 * v2 <= 0;
end;


var i, j, n, t : integer;
    A, x1, y1, x2, y2 : array [1..MaxN] of integer;
    changes : boolean;


begin
  reset (input, 'ants.in');
  rewrite (output, 'ants.out');
  read (n);
  for i := 1 to n do read (x1[i], y1[i]);
  for i := 1 to n do read (x2[i], y2[i]);
  for i := 1 to n do A[i] := i;
  repeat
    changes := false;
    for i := 1 to n do
      for j := i + 1 to n do
        if intersect (x1[i], y1[i], x2[A[i]], y2[A[i]],  x1[j], y1[j], x2[A[j]], y2[A[j]]) then begin
          //writeln (i, ' ', j);
          t := A[i]; A[i] := A[j]; A[j] := t; changes := true
        end;
  until not changes;
  for i := 1 to n do writeln (A[i]);
  

end.