var
 b			:	array[0..10000,'a'..'z']of integer;
 c			:	array[0..10000,'a'..'z']of integer;
 fn			:	array[0..10000]of boolean;
 st			:	string;
 n,m,k,i,len,cur	:	longint;

Procedure add(st : string);
var
 j  :  longint;
begin
 cur := 0;
  for j := 1 to length(st) do
     if b[cur,st[j]] <> 0 then 
        begin
          inc(c[cur,st[j]]);
          cur := b[cur,st[j]];
        end
     else 
        begin
          inc(len);
          b[cur,st[j]] := len;
          inc(c[cur,st[j]]);
          cur := len;
        end;
 fn[cur] := true;
end;

Function find(k : longint) : string;
var
 s	:	string;
 ch	:	char;
 cur	:	longint;
begin
 cur := 0;
 while true do begin
 	for ch := 'a' to 'z' do
 		if k <= c[cur,ch] then 
 				break else 
 				k := k - c[cur,ch];

	if fn[cur] then break;
 	cur := b[cur,ch];
 	s := s + ch;
 end;
 find := s;
end;

begin
 reset(input,'a.in');
 rewrite(output,'a.out');

  readln(n,m); //n - nunmber of string
  len := 0;    //m - kolichestvo zaprosov na k-th string

  for i := 1 to n do
    begin
      readln(st);
      add(st);
    end;

  for i := 1 to m do
    begin
      readln(k);
      writeln(find(k));
    end;


 close(output);
end.
