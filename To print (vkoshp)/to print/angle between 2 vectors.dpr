uses math;
Var
 x1,x2,y1,y2 : integer;
 t,ans : real;
Begin
 Assign(Input,'a.in');Reset(Input);
 Assign(Output,'a.out');Rewrite(Output);
  Read(x1,y1,x2,y2);
  t:=(x1*x2+y1*y2) / ((sqrt(sqr(x1)+sqr(y1)))*(sqrt(sqr(x2)+sqr(y2)))); //(a, b) = |a| * |b| * cos(w); // w = angle between two vectors
  t:=arccos(t);
  write(t:0:5);
 Close(Input);
 Close(Output);
End.