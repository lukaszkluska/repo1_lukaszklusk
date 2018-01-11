program prg;

const N = 80;

var
  Z : array[0..N-1] of integer;
  i,L,W : integer;
  t : boolean;

begin
  randomize;

  // Wype³niamy tablicê

  W := random(100);
  for i := 0 to N - 1 do
    if random(2) = 1 then Z[i] := random(100)
    else                  Z[i] := W;

  // Wyszukujemy lidera

  L := 0;
  for i := 0 to N - 1 do
    if L = 0 then
    begin
      W := Z[i]; L := 1;
    end
    else if W = Z[i] then inc(L)
         else             dec(L);

  // Sprawdzamy, czy mamy lidera

  if L = 0 then t := false
  else
  begin
    L := 0;
    for i := 0 to N - 1 do if W = Z[i] then inc(L);
    t := L > N div 2;
  end;

  // Wyœwietlamy tablicê

  for i := 0 to N - 1 do
    if t and (Z[i] = W) then write(' >',Z[i]:2)
    else                     write(Z[i]:4);

  // Wyœwietlamy wyniki

  writeln;
  if t then writeln(W,' : ',L)
  else      writeln('BRAK LIDERA');
  writeln

end. 