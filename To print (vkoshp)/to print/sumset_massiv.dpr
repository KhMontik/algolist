E:\olymp\algo\dynamic\sumset_massiv.dpr
//kolichestvo sposobov slozhit' chislo N stepenyami dvoiki
uses math;
const   maxn    =       1048576;
        maxlogn =       20;
        md	=	1000000000;
var
	d	:	array[0..maxn]of longint;
	power	:	array[0..maxlogn]of longint;
	i,j,n	:	longint;
        logn    :       word;

begin
	reset(input,'sumset.in');
	rewrite(output,'sumset.out');
	read(n);

	logn := trunc(log2(n));

	for i := 0 to logn do begin
		power[i] := 1 shl i;
	end;

	d[0] := 1;

	for j := 0 to logn do begin
   	   for i := 1 to n do begin
   	      if i-power[j] >= 0 then
   	      d[i] := (d[i] + d[i-power[j]]) mod md;
	   end;
	end;
	write(d[n]);

	close(input);
	close(output);
end.