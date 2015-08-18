var
    i,j,n,l,m : longint;
    den : array[0..1000000] of longint;
    sum,k : int64;

procedure fact(n,p : longint);
begin
 l:=2;
 while sqr(l)<=n do begin
   if n mod l=0 then begin
     inc(den[l],p);
     n:=n div l;
   end else
   if l=2 then inc(l) else inc(l,2);
 end;
 if n>1 then inc(den[n],p);
end;

begin

  read(n,k);

  for i:=n+2 to 2*n do fact(i,1);

  for i:=1 to n do fact(i,-1);

  sum:=1 mod k;

  for i:=1 to 2*n do 
    for j:=1 to den[i] do 
      sum:=int64(int64(int64(sum) * int64(int64(i) mod int64(k))) mod int64(k));

  write(sum);    
end.



    readln(n);
    a[1, 0] := 1;
    a[1, 1] := 1;
    for i := 2 to n do begin
        for j := 0 to i do begin
            a[i, j] := int64(a[i, j - 1] + a[i - 1, j]);
        end;
    end;
    writeln(a[n, n]);


    readln(n);
    a[0] := 1;
    for i := 1 to n do begin
        for j := 0 to i - 1 do begin
            a[i] := a[i] + (a[i - j - 1] * a[j]);
        end;
    end;
    writeln(a[n]);
