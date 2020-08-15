PROGRAM IDCodes;

VAR   codelength: integer;
      oldcode, newcode: string;
      LeftPart, RightPart: string;
      x: char;
      i,j: integer;

FUNCTION GetString:Boolean;
VAR i: integer;
    sep: char;
    good, finished: Boolean;

begin
repeat
  readln(oldcode);
  finished := oldcode = '#';
  if not finished
    then begin
      good := length(oldcode) <= 50;
      for i := 1 to length(oldcode) do
        if not (oldcode[i] in ['a' .. 'z']) then good := false;
      if not good
        then begin writeln(oldcode); writeln('-> ':10, 'Bad string or length') end;
    end;
  until good or finished;
 GetString := not finished;
end; {Get String}

FUNCTION Omit(s:string; i,j:integer): string;
begin Delete(s, i, j); Omit := s end;

FUNCTION StringSort(s: string): string;
VAR  i,j, min: integer;
     x:char;

begin
for i := 1 to length(s)-1 do begin
  min := i;
  for j := i+1 to length(s) do if s[j] < s[min] then min := j;
  if min <> i
    then begin x := s[i]; s[i] := s[min]; s[min] := x end;
  end;
StringSort := s;
end;

begin  {Main}

while GetString do begin
  i := length(oldcode)+1;
  repeat i := i-1;
    x := oldcode[i]; j := i-1;
    while (j>0) and (x <= oldcode[j]) do j := j - 1;
    until (j > 0) or (i=1);
  if j = 0
    then writeln('No Successor')
    else begin
      LeftPart := Copy(oldcode, 1, j-1);
      RightPart := Copy(Omit(oldcode,i,1), j, length(oldcode));
      newcode :=  LeftPart + x + StringSort(RightPart);
      writeln(newcode) end;
  end;  {while Get String}
end. {of program}
