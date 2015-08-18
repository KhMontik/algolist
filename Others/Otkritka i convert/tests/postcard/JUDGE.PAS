{
Written by Fyodor Menshikov during NEERC 2002
Modified for trainings 26.01.2003
}
{38}
{$N+,E-}
type
   real=extended;
const
   eps=1e-15;

   procedure find(w,h,w0,h0:real);
   var
      buf,d,l,alpha,beta,gamma,width:real;
   begin
      if h>w then begin
         buf:=h;
         h:=w;
         w:=buf;
      end;
      if h0>w0 then begin
         buf:=h0;
         h0:=w0;
         w0:=buf;
      end;
      if (h0<=h+eps)and(w0<=w+eps) then begin
         writeln('Possible');
         halt;
      end;
      if h0>=h-eps then
         exit;
      d:=sqrt(sqr(h0)+sqr(w0));
      l:=sqrt(sqr(d)-sqr(h));
      alpha:=arctan(h/l);
      beta:=arctan(h0/w0);
      gamma:=alpha-beta;
      width:=h0*sin(gamma)+w0*cos(gamma);
      if width<=w+eps then begin
         writeln('Possible');
         halt;
      end;
   end;

var
   a,b,c,d,e:real;
begin
   assign(input,'postcard.in');
   reset(input);
   readln(a,b,d,e);
   assign(output,'postcard.out');
   rewrite(output);
   find(d,e,a,b);
   writeln('Impossible');
end.