{ VERIFICATION PROGRAM for BRACKET problem for NEERC'2001 }
{ (C) Roman Elizarov }
{$APPTYPE CONSOLE}
program BRACKET_CHECK;
uses
  sysutils, testlib in '..\testlib.pas';

var
  sinf, souf, sans: string;

function IsProper(s: string): boolean;
var
  i: integer;
  stack: string;
begin
  IsProper := False;
  for i := 1 to length(s) do begin
    case s[i] of 
      '(': begin
             SetLength(stack, length(stack) + 1);
             stack[length(stack)] := '(';
           end;
      '[': begin
             SetLength(stack, length(stack) + 1);
             stack[length(stack)] := '[';
           end;
      ')': begin
             if (length(stack) = 0) or (stack[length(stack)] <> '(') then 
               exit;
             SetLength(stack, length(stack) - 1);
           end;
      ']': begin
             if (length(stack) = 0) or (stack[length(stack)] <> '[') then
               exit;
             SetLength(stack, length(stack) - 1);
           end;
      else exit;
    end;
  end;
  IsProper := length(stack) = 0;
end;

function IsSubseq(s1, s2: string): boolean;
var
  i, j: integer;
begin
  IsSubseq := False;
  j := 0;
  for i := 1 to length(s1) do begin
    inc(j);
    while (j <= length(s2)) and (s1[i] <> s2[j]) do 
      inc(j);
    if j > length(s2) then
      exit;
  end;
  IsSubseq := True;
end;

begin
  try 
    sinf := inf.readString;
    souf := ouf.readString;
    sans := ans.readString;
    if not ouf.seekeof then
      Quit(_PE, 'Extra data in file');
    { Check is proper sequence }
    if length(souf) > length(sans) then
      Quit(_WA, 'Too long: ' + souf);
    if not IsProper(souf) then 
      Quit(_WA, 'Is not proper: ' + souf);
    if not IsSubseq(sinf, souf) then
      Quit(_WA, 'Is not subsequence: ' + souf);
    if length(souf) < length(sans) then
      Quit(_FAIL, 'Better answer: ' + souf);
    Quit(_OK, 'Ok');
  except on e: Exception do 
    Quit(_FAIL, e.Message);
  end;
end.
