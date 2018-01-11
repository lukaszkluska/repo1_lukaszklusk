
program rsa;

// Procedura oczekuje na naciœniêcie klawisza Enter
// po czym czyœci ekran okna konsoli
//-------------------------------------------------
procedure Czekaj;
var
  i : integer;
begin
  writeln;
  writeln('Zapisz te dane i nacisnij Enter');
  readln;
  for i := 1 to 500 do writeln;
end;

// Funkcja obliczaj¹ca NWD dla dwóch liczb
//----------------------------------------
function nwd(a,b : integer) : integer;
var
  t : integer;
begin
  while b <> 0 do
  begin
    t := b;asdasdasd
    b := a mod b;
    a := t
  end;
  nwd := a
end;

// Funkcja obliczania odwrotnoœci modulo n
//----------------------------------------
function odwr_mod(a,n : integer) : integer;
var
  a0,n0,p0,p1,q,r,t : integer;
begin
  p0 := 0; p1 := 1; a0 := a; n0 := n;
  q  := n0 div a0;
  r  := n0 mod a0;
  while r > 0 do
  begin
    t := p0 - q * p1;
    if t >= 0 then
      t := t mod n
    else
      t := n - ((-t) mod n);
    p0 := p1; p1 := t;
    n0 := a0; a0 := r;
    q  := n0 div a0;
    r  := n0 mod a0;
  end;
  odwr_mod := p1;
end;

// Procedura generowania kluczy RSA
//---------------------------------
procedure klucze_RSA;
const
  tp : array[0..9] of integer = (11,13,17,19,23,29,31,37,41,43);
var
  p,q,phi,n,e,d : integer;
begin
  writeln('Generowanie kluczy RSA');
  writeln('----------------------');
  writeln;

// generujemy dwie ró¿ne, losowe liczby pierwsze

  repeat
    p := tp[random(10)];
    q := tp[random(10)];
  until p <> q;

  phi := (p - 1) * (q - 1);
  n   := p * q;

// wyznaczamy wyk³adniki e i d

  e := 3;
  while nwd(e,phi) <> 1 do inc(e,2);
  d := odwr_mod(e,phi);

// gotowe, wypisujemy klucze

  writeln('KLUCZ PUBLICZNY');
  writeln('wykladnik e = ',e);
  writeln('    modul n = ',n);
  writeln;
  writeln('KLUCZ PRYWATNY');
  writeln('wykladnik d = ',d);
  Czekaj;
end;

// Funkcja oblicza modulo potêgê podanej liczby
//---------------------------------------------
function pot_mod(a,w,n : integer) : integer;
var
  pot,wyn,q  : integer;
begin

  // wyk³adnik w rozbieramy na sumê potêg 2. Dla reszt
  // niezerowych tworzymy iloczyn potêg a modulo n.

  pot := a; wyn := 1; q := w;
  while q > 0 do
  begin
    if (q mod 2) = 1 then wyn := (wyn * pot) mod n;
    pot := (pot * pot) mod n;    // kolejna potêga
    q := q div 2;
  end;
  pot_mod := wyn;
end;

// Procedura kodowania danych RSA
//-------------------------------
procedure kodowanie_RSA;
var
  e,n,t : integer;
begin
  writeln('Kodowanie danych RSA');
  writeln('--------------------');
  writeln;
  write('Podaj wykladnik = '); readln(e);
  write('    Podaj modul = '); readln(n);
  writeln('----------------------------------');
  writeln;
  write('Podaj kod RSA   = '); readln(t);
  writeln;
  writeln('Wynik kodowania = ',pot_mod(t,e,n));
  Czekaj;
end;

// ********************
// ** Program g³ówny **
// ********************

var
  w : integer;

begin
  randomize;
  repeat
    writeln('System szyfrowania danych RSA');
    writeln('-----------------------------');
    writeln(' (C)2012 mgr Jerzy Walaszek ');
    writeln;
    writeln('MENU');
    writeln('====');
    writeln('[ 0 ] - Koniec pracy programu');
    writeln('[ 1 ] - Generowanie kluczy RSA');
    writeln('[ 2 ] - Kodowanie RSA');
    writeln;
    write('Jaki jest twoj wybor? (0, 1 lub 2) : ');
    readln(w);
    writeln; writeln; writeln;
    case w of
      1 : klucze_RSA;
      2 : kodowanie_RSA;
    end;
    writeln; writeln; writeln;
  until w = 0;
end. 