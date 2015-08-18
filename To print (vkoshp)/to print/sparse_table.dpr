E:\olymp\algo\data structure\sparse table\sparse_table.dpr
{$O-}
Uses Math;
const   maxn = 100000;
var
	n, m, i, j, l, r, ans, d, nn : longint;
	sp : array[0..maxn, 0..17]of longint;
        log, deg : array[0..17]of longint;
begin
	reset(input,'a.in');
	rewrite(output,'a.out');
	readln(n, m);

        for i := 1 to n do
          for j := 1 to log[n] do
            sp[i,j]:= maxlongint;

	for i := 1 to n do begin
	  log[i] := trunc(log2(i));
	end;

	for i := 0 to n do begin
	  deg[i] := 1 shl i;
	end;

	for i := 1 to n do begin
	  read(sp[i, 0]);
	end;

        for i := 1 to n do
          for j := 1 to log[n] do
	    sp[i, j] := min(sp[i, j - 1], sp[i + deg[j - 1], j - 1]);

	for i := 1 to m do begin
	  readln(l, r);
	  d := r - l + 1; nn := 1;
	  ans := min(sp[l, log[d]], sp[r - deg[log[d]] + 1, log[d]]);
          //while deg[nn] <= d do inc(nn);
          //dec(nn);
          //writeln(min(sp[l,nn],sp[r - deg[nn] + 1,nn]));
          writeln(ans);
	end;
end.