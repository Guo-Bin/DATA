{$A+,B-,D+,E-,F-,G+,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
program macro;  {$DEFINE MULTI}
const MaxN = 100;  MinW = 1;  MaxW = 10000;
type float = extended;
var A                   : array [1..MaxN] of float;
    N, i, j, ia, ib, _  : integer;
    ma, mb              : float;
begin
  assign (input, 'input.txt');  reset (input);
  assign (output, 'output.txt');  rewrite (output);
  repeat
    inc(_); {$IFNDEF MULTI} if _ > 1 then runerror(239); {$ENDIF}
    read (N);  if (N <= 0) or (N > MaxN) then runerror (239);
    for i := 1 to N do begin
      read (j);  if (j < MinW) or (j > MaxW) then runerror (239);
      A[i] := j end;
    while N > 1 do begin
      ma := 0;  mb := 0;  ia := 0;  ib := 0;
      for i := 1 to N do
        if A[i] > ma then begin mb:=ma; ma:=A[i]; ib:=ia; ia:=i end
        else if A[i] > mb then begin mb:=A[i]; ib:=i end;
      A[ia] := 2*sqrt(ma*mb);  dec (N);
      for i := ib to N do A[i] := A[i+1]
    end;
    writeln (A[1]:3:3)
  until seekeof
end.