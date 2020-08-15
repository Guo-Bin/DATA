var i : integer;
begin
  writeln (100);
  for i := 1 to 100 do writeln (0, ' ', i * 100);
  for i := 1 to 100 do writeln (100 * 100, ' ', 100 * 100 - i * 100); 
end.