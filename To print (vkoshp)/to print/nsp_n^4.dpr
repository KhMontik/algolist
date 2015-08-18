E:\olymp\algo\dynamic\nsp_n^4.dpr
//naibolshii summarnii pryamougolnik
const	maxn			=	100;
	maxm			=	100;
var
	i,j,i1,j1,i2,j2,n,m	:	longint;
	maxi			:	int64;
	a			:	array[0..maxn,0..maxm]of longint;

begin
	reset(input,'a.in');
	rewrite(output,'a.out');
	read(n,m);
	for i := 1 to n do
	   for j := 1 to m do
	      read(a[i,j]);

	for i := 2 to n do
	   a[i,1] := a[i,1] + a[i-1,1];

	for j := 2 to m do
	   a[1,j] := a[1,j] + a[1,j-1];

	for i := 2 to n do
	   for j := 2 to m do
	      a[i,j] := a[i,j] + a[i-1,j] + a[i,j-1] - a[i-1,j-1];

	for i1 := 1 to n do
	   for j1 := 1 to n do
	      for i2 := i1 to n do
	         for j2 := j1 to n do
	            if maxi <  a[i2,j2] - a[i1-1,j2] - a[i2,j1-1] + a[i1-1,j1-1] then
	               maxi := a[i2,j2] - a[i1-1,j2] - a[i2,j1-1] + a[i1-1,j1-1];

	write(maxi);
end.