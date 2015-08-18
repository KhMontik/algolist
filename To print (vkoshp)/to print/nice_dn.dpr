E:\olymp\algo\dynamic\by profile\nice\nice_dn.dpr
const 	md = 1 shl 6;
type	massiv = array[0..31]of byte;
var
        ans : int64;
	n, m, i, j, k : longint;
	was : array[0..md, 0..md]of byte;
	d : array[0..31, 0..31]of int64;

function bi(i : word) : massiv;
begin
	fillchar(result, sizeof(result), 0);
	while i <> 0 do begin
	   inc(result[0]);
	   result[result[0]] := i mod 2;
	   i := i div 2;
	end;
end;

function calc(i,j : word) : byte;
var	a, b : massiv;
begin
	a := bi(i);
	b := bi(j);
	for i := 1 to n - 1 do
	  if (a[i] + a[i+1] + b[i] + b[i+1]) mod 4 = 0 then begin
	     calc := 0;
	     exit;
	  end;
	calc := 1;
end;

begin
	reset(input,'nice.in');
	rewrite(output,'nice.out');
	readln(n,m);
	if n > m then begin i := n; n := m; m := i;end;
	for i := 0 to (1 shl n) - 1 do
	  for j := 0 to (1 shl n) - 1 do
	    was[i,j] := calc(i, j);

	for i := 0 to (1 shl n) - 1 do
	    d[1, i] := 1;

	for i := 2 to m + 1 do
	  for k := 0 to (1 shl n) - 1 do
	    for j := 0 to (1 shl n) - 1 do
	      d[i, j] := Int64(d[i, j] + was[k, j] * d[i-1, k]);

       for i := 0 to (1 shl n) - 1 do
          ans := Int64(ans + d[m,i]);

	writeln(Int64(ans));
end.