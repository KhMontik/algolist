E:\olymp\algo\dynamic\nsp_n^3.dpr
//naibolshii summarnii pryamougolnik
uses	math;
const	maxn	=	100;
	maxm	=	100;
var
	a,d		:	array[0..maxn,0..maxm]of longint;
	q		:	array[0..maxm]of longint;
	i,j,k,n,m	:	longint;
	maxi		:	int64;

begin
	reset(input,'a.in');
	rewrite(output,'a.out');
	
	read(n,m); q[0] := -maxlongint;
	
	for i := 1 to n do
	   for j := 1 to m do
	      read(a[i,j]);

	for i := 1 to n do
	   for j := 1 to m do
	      d[i,j] := d[i-1,j] + a[i,j];

	for i := 1 to n do
	   for j := 0 to i-1 do
	      for k := 1 to m do
	         begin
	            q[k] := max(d[i,k]-d[j,k],q[k-1]+d[i,k]-d[j,k]);
	            if q[k] > maxi then maxi := q[k];
	         end;

	write(maxi);
end.