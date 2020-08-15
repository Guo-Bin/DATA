var i : integer;
begin
  writeln (300);
  for i := 1 to 299 do writeln (0, ' ', i);
  writeln (150, ' ', 301);
  for i := 1 to 299 do writeln (300, ' ', i); 
  writeln (150, ' ', -1);
end.