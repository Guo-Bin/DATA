(*
 * ACM NEERC 2001 Northern Subregion Quaterfinals
 *
 * Problem:  Stripies
 * Author:   Nikolay Durov
 * Solution: Andrew Stankevich
 *)

{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P+,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}

program stripies;

const
    maxn = 100;

var
    i, n: longint;
    a: array [0..maxn] of double;
    
procedure sort(l, r: longint);
var
    i, j: longint;
    x, t: double;
begin
    i := l;
    j := r;
    x := a[(l + r) div 2];
    while i <= j do
    begin
        while a[i] < x do inc(i);
        while a[j] > x do dec(j);
        if i <= j then
        begin
            t := a[i]; a[i] := a[j]; a[j] := t;
            inc(i);
            dec(j);
        end;
    end;
    if (l < j) then
        sort(l, j);
    if (i < r) then
        sort(i, r);
end;

begin
    assign(input, 'input.txt');
    reset(input);
    assign(output, 'output.txt');
    rewrite(output);
    
    read(n);
    for i := 1 to n do
        read(a[i]);
        
    for i := 1 to n - 1 do
    begin
        sort(1, n - i + 1);
        a[n - i] := 2 * sqrt(a[n - i] * a[n - i + 1]);
    end;
    
    writeln(a[1] :0 :4);
    
    close(input);
    close(output);
end.