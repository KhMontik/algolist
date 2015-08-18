const   inf = int64(1000000000) * int64(1000000);
var
        x, y     : array[1..5000]of longint;
        used     : array[1..5000]of boolean;
        d        : array[1..5000]of extended;
        n, i, len: longint;
        sum      : extended;

function dist(i,j : longint) : extended;
begin
	dist := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
end;

procedure prima(i : longint);
var
        v    : extended;
        p, j : longint;
begin
        if len = n then exit;
	used[i] := true;
        d[i] := inf;
        v := inf * 2;
	for j := 1 to n do begin
	  if (not used[j]) and (dist(i,j) < d[j]) then d[j] := dist(i,j);
	  if v >  d[j] then begin
             v := d[j];
             p := j;
	  end;
        end;
	if d[p] = inf then exit;
	sum := sum + d[p];
        inc(len);
	prima(p);
end;

begin
	reset(input,'a.in');
	rewrite(output,'a.out');
	readln(n);

        for i := 1 to n do
          d[i] := inf;

        sum := 0;
        len := 0;

	for i := 1 to n do readln(x[i], y[i]);

	prima(1);

	writeln(sum : 0 : 3);
end.