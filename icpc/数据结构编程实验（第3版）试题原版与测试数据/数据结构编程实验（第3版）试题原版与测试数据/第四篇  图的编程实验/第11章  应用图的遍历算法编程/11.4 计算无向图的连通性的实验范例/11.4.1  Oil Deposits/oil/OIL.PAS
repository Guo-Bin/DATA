program oil_deposits;

const
  OIL = -1;
  NO_OIL = 0;
  
var
  input_file: text;
  output_file: text;
  rows, columns: integer;
  deposits: integer;
  grid: array [0..101, 0..101] of integer;


procedure mark_deposit (i: integer; j: integer; marker: integer);
begin
  grid[i,j] := marker;
  if grid[i-1, j  ] = OIL then mark_deposit (i-1, j  , marker);
  if grid[i-1, j+1] = OIL then mark_deposit (i-1, j+1, marker);
  if grid[i  , j+1] = OIL then mark_deposit (i  , j+1, marker);
  if grid[i+1, j+1] = OIL then mark_deposit (i+1, j+1, marker);
  if grid[i+1, j  ] = OIL then mark_deposit (i+1, j  , marker);
  if grid[i+1, j-1] = OIL then mark_deposit (i+1, j-1, marker);
  if grid[i  , j-1] = OIL then mark_deposit (i  , j-1, marker);
  if grid[i-1, j-1] = OIL then mark_deposit (i-1, j-1, marker);
end;


procedure count_deposits;
var i,j: integer;
begin
  deposits := 0;
  for i := 1 to rows do
    for j := 1 to columns do
      if grid[i,j] = OIL then begin
        deposits := deposits + 1;
        mark_deposit (i, j, deposits);
      end;
end;

procedure read_grid;
var i,j: integer; ch: char;
begin
  for i := 0 to 101 do begin
    grid[i,0] := NO_OIL; grid[i,101] := NO_OIL;
    grid[0,i] := NO_OIL; grid[101,i] := NO_OIL;
  end;    
  for i := 1 to rows do begin
    for j := 1 to columns do begin
      read (input_file, ch);
      if ch = '*'
        then grid[i,j] := NO_OIL
        else grid[i,j] := OIL;
    end;
    readln (input_file);
  end;
end;


procedure write_grid;
var i,j: integer;
begin
  for i := 1 to rows do begin
    for j := 1 to columns do
      write (grid[i,j]:3, ' ');
    writeln;
  end;
  writeln;
end;


begin
  assign (input_file, 'oil.in'); reset (input_file);
  assign (output_file, 'oil.out'); rewrite (output_file);
  readln (input_file, rows, columns);
  while (rows > 0) do begin
    read_grid;
    count_deposits;
    write_grid;
    writeln (output_file, deposits);
    readln (input_file, rows, columns);
  end;
  close (input_file); close (output_file);
end.
