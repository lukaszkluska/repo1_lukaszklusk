
program mpow;

// definiujemy typy dla macierzy dynamicznych

type
  NReal = array of double; // typ wierszy
  MReal = array of NReal;  // typ macierzy

// procedura mno¿enia macierzy
// C = A x B
//----------------------------
procedure mnoz(n : integer; A,B,C : MReal);
var
  i,j,k : integer;
  s     : double;
begin

 for i := 0 to n - 1 do
    for j := 0 to n - 1 do
    begin
      s := 0;
      for k := 0 to n - 1 do s := s + A[i][k] * B[k][j];
      C[i][j] := s;
    end;
end;

// procedura przepisuje macierz A do macierzy B
//---------------------------------------------
procedure przepisz(n : integer; A,B : MReal);
var
  i,j : integer;
begin
  for i := 0 to n - 1 do
    for j := 0 to n - 1 do B[i][j] := A[i][j];
end;

// procedura ustawia w macierzy A macierz jednostkow¹
//---------------------------------------------------
procedure jednostkowa(n : integer; A : MReal);
var
  i,j : integer;
begin
  for i := 0 to n - 1 do
  begin
    for j := 0 to n - 1 do A[i][j] := 0;
    A[i][i] := 1;
  end;
end;

// procedura wylicza potêgê k-t¹ macierzy A
//-----------------------------------------
procedure potega(k,n : integer; A : MReal);
var
  P,W : MReal;
  i   : integer;
begin
  if k = 0 then jednostkowa(n,A)
  else if k > 1 then
  begin

    // tworzymy macierze pomocnicze P i W

    SetLength(P,n);
    SetLength(W,n);
    for i := 0 to n - 1 do
    begin
      SetLength(P[i],n);
      SetLength(W[i],n);
    end;

    // macierz A zapamiêtujemy w P

    przepisz(n,A,P);

    // w pêtli wykonujemy kolejne mno¿enia - wynik zawsze w A

    for i := 2 to k do
    begin
      mnoz(n,P,A,W);     // W <- P x A
      przepisz(n,W,A);   // A <- P x A
    end;

    // usuwamy macierze P i W

    for i := 0 to n - 1 do
    begin
      SetLength(P[i],0);
      SetLength(W[i],0);
    end;
    SetLength(P,0);
    SetLength(W,0);
  end;
end;

//*** PROGRAM G£ÓWNY ***
//----------------------

var
  A : MReal;
  n,i,j,k : integer;

begin

  // wczytujemy wyk³adnik k oraz stopieñ macierzy n

  read(k,n);

  // tworzymy macierz dynamiczn¹ i wczytujemy dane wierszami

  SetLength(A,n);
  for i := 0 to n - 1 do
  begin
    SetLength(A[i],n);
    for j := 0 to n - 1 do read(A[i][j]);
  end;

  // obliczamy k-t¹ potêgê A

  potega(k,n,A);

  // wyœwietlamy wyniki

  writeln;

  for i := 0 to n - 1 do
  begin
    for j := 0 to n - 1 do write(A[i][j]:10:2,' ');
    writeln;
  end;

  // usuwamy macierz A

  for i := 0 to n - 1 do SetLength(A[i],0);
  SetLength(A,0);

end. 