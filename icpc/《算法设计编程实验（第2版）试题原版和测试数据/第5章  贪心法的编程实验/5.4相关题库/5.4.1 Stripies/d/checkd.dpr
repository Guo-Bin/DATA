{$n+}

program check_d;

uses
    testlib, symbols;
    
var
    ja, pa: extended;    
    
begin
    ja := ans.readreal;
    pa := ouf.readreal;
    
    if abs(ja - pa) > 1.1e-2 then
        quit(_wa, 'expected: ' + realstr(ja, 0, 2) + ', found: ' + realstr(pa, 0, 2));
    quit(_ok, realstr(ja, 0, 2));
end.    