var p, xc, yc, i : integer;
    x1, y1, x2, y2 : array [1..300] of integer;
begin
  xc := -900;
  yc := -900;
  p := 1;
  for i := 1 to 149 do begin
    x1[p] := xc;
    y1[p] := yc;
    x2[p] := xc + 4;
    y2[p] := yc + 4;
    inc (p);
    x1[p] := xc + 6;
    y1[p] := yc + 5;
    x2[p] := xc;
    y2[p] := yc + 5;
    inc (p);
    inc (xc, 5);
    inc (yc, 3);
  end;
  x1[p] := xc;
  y1[p] := yc;
  x2[p] := xc + 4;
  y2[p] := xc + 4;
  inc (p);
  x1[p] := xc;
  y1[p] := yc + 4;
  x2[p] := xc + 4;
  y2[p] := yc;

  writeln (300);
  for i := 1 to 300 do writeln (x1[i], ' ', y1[i]);
  for i := 1 to 300 do writeln (x2[i], ' ', y2[i]);


end.