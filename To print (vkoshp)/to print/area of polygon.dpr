Var
  i,j,n  : longint;
  x,y    : array [ 0..100000 ] of integer;
  ans,res: extended;
Begin
 Assign(Input,'a.in');Reset(Input);
 Assign(Output,'a.out');Rewrite(Output);
  Readln(n);
  For i:=1 to n do
  Readln(x[i],y[i]);
  x[n+1]:=x[1];
  y[n+1]:=y[1];
  For i:=1 to n do
  ans:= ans + ((x[i]*y[i+1])-(y[i]*x[i+1]));
  res:= abs(ans) / 2;
  write(res:0:1);
 Close(Input);
 Close(Output);
End.