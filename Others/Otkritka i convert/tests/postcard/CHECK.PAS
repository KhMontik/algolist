{
Written by Fyodor Menshikov during NEERC 2002
Modified for trainings 26.01.2003
Modified into checker 15.12.2003
}
{38}
{$N+,E-}
   procedure ac;
   begin
      writeln('a');
      halt(0);
   end;

   procedure wa;
   begin
      writeln('wa');
      halt(1);
   end;

   procedure pe;
   begin
      writeln('pe');
      halt(2);
   end;

   procedure check(correct:string);
   var
      answer:string;
   begin
      readln(answer);
      if not eof then
         pe;
      if (answer<>'Possible')and(answer<>'Impossible') then
         pe;
      if answer<>correct then
         wa;
      ac;
   end;

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
         check('Possible');
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
         check('Possible');
         halt;
      end;
   end;

var
   a,b,c,d,e:real;
begin
   assign(input,'postcard.in');
   reset(input);
   readln(a,b,d,e);
   assign(input,'postcard.out');
   reset(input);
   find(d,e,a,b);
   check('Impossible');
end.