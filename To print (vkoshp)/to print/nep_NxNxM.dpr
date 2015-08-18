E:\olymp\algo\dynamic\nep_NxNxM.dpr
//naibolshii edinichnii pryamougolnik
uses	math;
const	maxn	=	100;
	maxm	=	100;
var
	a,d		:	array[0..maxn,0..maxm]of longint;
	i,j,k,n,m	:	longint;
	maxi, q		:	int64;

begin
	reset(input,'a.in');
	rewrite(output,'a.out');

	read(n,m); 

	for i := 1 to n do
	   for j := 1 to m do
	      begin
	      	read(a[i,j]);
	      	if a[i,j] = 0 then a[i,j] := -(n * m + 1);
	      end;

	for i := 1 to n do
	   for j := 1 to m do
	      d[i,j] := d[i-1,j] + a[i,j];

	maxi:= - maxlongint;

	for i := 1 to n do begin
	   for j := 1 to n-i+1 do begin
	     q := d[i+j-1,1]-d[j-1,1];
	     maxi:= max(maxi, q);
	      for k := 2 to m do begin
	      	q := max(q + d[i+j-1,k]-d[j-1,k], d[i+j-1,k]-d[j-1,k]);
	      	maxi:= max(maxi, q);
	      end;
	   end;
	end;

	write(maxi);
end.