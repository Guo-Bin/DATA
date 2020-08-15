{$A+,B-,D+,E-,F-,G+,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}
program macro;
var a:array [1..100] of extended;

procedure qsort (l, r:integer);
var i, j:integer;
    x, y:extended;
begin
  if l>=r then exit;
  i:=l; j:=r; x:=a[(l+r) shr 1];
  repeat
    while a[i]>x do inc (i);
    while x>a[j] do dec (j);
    if i<=j then begin y:=a[i];a[i]:=a[j];a[j]:=y;inc (i); dec (j);end;
  until i>j;
  qsort (l, i-1);
  qsort (i, r);
end;

var b, i, n:integer;
begin
  assign (input, 'input.txt'); reset (input);
  assign (output, 'output.txt'); rewrite (output);
  readln (n);
  if (n<1) or (n>100) then runerror (239);
  for i:=1 to n do
    begin
      if seekeof then runerror (239);
      readln (b);
      if (b<1) or (b>10000) then runerror (239);
      a[i]:=b;
    end;
  if not eof then runerror (239);
  qsort (1, n);
  for i:=2 to n do a[i]:=2*sqrt (a[i]*a[i-1]);
  writeln (a[n]+1e-10:0:3);
end.