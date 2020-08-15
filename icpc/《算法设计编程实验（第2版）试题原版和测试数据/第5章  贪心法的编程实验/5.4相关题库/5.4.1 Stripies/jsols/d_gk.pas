{$n+}
var
    i, j, k, l, m, n: longint;
    w: array [1..101] of double;
    t, z: double;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);

    read(n);

    for i := 1 to n do begin
        read(w[i]);
    end;
    w[n + 1] := 1e100;

    for i := 1 to n do begin
        for j := i + 1 to n do begin
            if (w[i] < w[j]) then begin
                t := w[i]; w[i] := w[j]; w[j] := t;
            end;
        end;
    end;

    for i := 2 to n do begin
        w[i] := 2 * sqrt(w[i - 1] * w[i]);
    end;

    writeln(w[n]:0:2);

    close(input);
    close(output);
end.