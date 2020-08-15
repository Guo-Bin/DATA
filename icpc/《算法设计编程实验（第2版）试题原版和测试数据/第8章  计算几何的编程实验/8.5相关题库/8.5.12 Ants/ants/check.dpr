{$O-,Q+,R+}
uses testlib, SysUtils, Math;

type integer = longint;

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

const MaxN = 100;


var n : integer;
    B, C : array [1..MaxN] of integer;
    x1, y1, x2, y2 : array [1..MaxN] of integer;


procedure answer (var f : instream);
var i, j : integer;
begin
  for i := 1 to n do B[i] := 0;
  for i := 1 to n do
    C[i] := f.readlongint;
  if not f.seekeof then f.quit (_PE, 'End-of-file expected');
  for i := 1 to n do begin
    if (C[i] < 1) or (C[i] > n) then f.quit (_WA, format ('Invalid tree number for colony %d: %d', [i, C[i]]));
    if B[C[i]]<>0 then f.quit (_WA, format ('Same tree number for colonies %d and %d: %d', [B[C[i]], i, C[i]]));
    B[C[i]] := i;
  end;
  for i := 1 to n do
    for j := i + 1 to n do
      if intersect (x1[i], y1[i], x2[C[i]], y2[C[i]], x1[j], y1[j], x2[C[j]], y2[C[j]]) then
        f.quit (_WA, format ('Segments [%d -> %d]: (%d, %d) - (%d, %d) and [%d -> %d]: (%d, %d) - (%d, %d) intersect',
          [i, C[i], x1[i], y1[i], x2[C[i]], y2[C[i]],
           j, C[j], x1[j], y1[j], x2[C[j]], y2[C[j]]]));
end;

var i : integer;

begin
  n := inf.readlongint;
  for i := 1 to n do begin
    x1[i] := inf.readlongint;
    y1[i] := inf.readlongint;
  end;
  for i := 1 to n do begin
    x2[i] := inf.readlongint;
    y2[i] := inf.readlongint;
  end;
  //answer (ans);
  answer (ouf);
  quit (_OK, inttostr (n) + ' segments');
end.