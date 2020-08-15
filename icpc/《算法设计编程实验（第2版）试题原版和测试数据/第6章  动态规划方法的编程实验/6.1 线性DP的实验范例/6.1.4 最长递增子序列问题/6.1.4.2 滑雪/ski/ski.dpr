program ski;
{$R+,Q+,O-}
{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  max_size = 100;
  dr: array [1..4] of integer = (-1, 1, 0, 0);
  dc: array [1..4] of integer = (0, 0, -1, 1);

var
  fn: string;
  fin: text;
  row, col: integer;
  point: integer;
  height, len: array [1..max_size, 1..max_size] of integer;
  inq: array [1..max_size, 1..max_size] of boolean;
  queue: array [0..max_size * max_size, 1..2] of integer;
  head, tail: integer;
  r1, c1, r2, c2, k, i, j: integer;

procedure Enq(r, c, newl: integer);
begin
  if newl > len[r, c] then
  begin
    len[r, c] := newl;
    if not inq[r, c] then
    begin
      Inc(tail);
      if tail > point then tail := 0;
      queue[tail, 1] := r;
      queue[tail, 2] := c;
      inq[r, c] := true;
    end;
  end;
end;

begin
  repeat

  Write('Input file: ');
  Readln(fn);
  if fn = '' then Break;

  { Input the test case }
  Assign(fin, fn);
  Reset(fin);
  Readln(fin, row, col);
  for i := 1 to row do
    for j := 1 to col do
      Read(fin, height[i, j]);
  Close(fin);

  { Initialize queue and len }
  point := row * col;
  head := 0;
  tail := 0;
  FillChar(inq, SizeOf(inq), false);
  FillChar(len, SizeOf(len), 0);
  for i := 1 to row do
    for j := 1 to col do
      Enq(i, j, 1);

  { Find the longest run }
  while head <> tail do
  begin
    Inc(head);
    if head > point then head := 0;
    r1 := queue[head, 1];
    c1 := queue[head, 2];
    inq[r1, c1] := false;
    for k := 1 to 4 do
    begin
      r2 := r1 + dr[k];
      c2 := c1 + dc[k];
      if (r2 > 0) and (c2 > 0) and (r2 <= row) and (c2 <= col) then
        if height[r2, c2] > height[r1, c1] then
          Enq(r2, c2, len[r1, c1] + 1);
    end;
  end;

  { Output }
  k := 0;
  for i := 1 to row do
    for j := 1 to col do
      if len[i, j] > k then k := len[i, j];
  Writeln('The length of the longest run:');
  Writeln(k);
  Writeln;

  until False;
end.
