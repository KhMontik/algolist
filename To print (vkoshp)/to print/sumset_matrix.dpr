E:\olymp\algo\dynamic\sumset_matrix.dpr
uses math;
const   maxn    =       524288 * 2;
        maxlogn =       19 + 1;
        md	=	1000000000;
var
	d	:	array[0..maxn,-1..maxlogn]of longint;
	log	:	array[1..maxn]of word;
	power	:	array[0..maxlogn]of longint;
	i,j,n	:	longint;

begin
	reset(input,'sumset.in');
	rewrite(output,'sumset.out');
	read(n);

	if n > maxn then
		begin
			write(n);
			close(input);
			close(output);
			halt;
		end;

	for i := 1 to n do begin
		log[i] := trunc(log2(i));
	end;

	for i := 0 to log[n] do begin
		power[i] := 1 shl i;
	end;

	d[0][0] := 1;

	for i := 1 to n do begin
		for j := 0 to log[i] do begin
			d[i][j] := (d[i][j-1] + d[ i-power[j] ][ min(j , log[i-power[j]]) ]) mod md;
		end;
	end;

	writeln(d[n][log[n]]);

	close(input);
	close(output);
end.