program CDIGITS;

const
   tfi='cdigits.inp';
   tfo='cdigits.out';

var res: array[0..9] of longint;


function f(j,x: longint): longint;
var s: string[11];
    n, y, i: longint;
    t, kq: longint;
    code: integer;
begin
   str(x,s);
   n:=length(s);
   if n=1 then
      if j>x then exit(0) else exit(1);
   y:=1;
   for i:=1 to n-1 do y:=y*10;
   dec(y);
   kq:=0;
   t:=f(j,y);
   for i:=0 to ord(s[1])-49 do
      begin
         kq:=kq+t;
         if i=j then kq:=kq+y+1;
      end;
   val(copy(s,2,255),y,code);
   if ord(s[1])-48=j then inc(kq,y+1);
   kq:=kq+f(j,y);
   exit(kq);
end;

function socs(x: longint): longint;
var s: string[11];
    t,y, n,i: longint;
    kq: longint;
begin
   str(x,s);
   n:=length(s);
   if n=1 then exit(x+1);
   y:=1;
   for i:=1 to n-1 do y:=y*10;
   dec(y);
   kq:=10;
   t:=9;
   for i:=2 to n-1 do
      begin
         t:=t*10;
         kq:=kq+t*i;
      end;
   x:=x-y;
   kq:=kq+x*n;
   exit(kq);
end;

procedure main;
var a, b, tg: longint;
    j: longint;
begin
   assign(input,tfi); reset(input);
   assign(output,tfo); rewrite(output);
   while not eof do
      begin
         readln(a,b);
         if a>b then
            begin
               tg:=a;
               a:=b;
               b:=tg;
            end;
         if b=0 then break;
         for j:=1 to 9 do res[j]:=f(j,b)-f(j,a-1);
         res[0]:=socs(b)-socs(a-1);
         for j:=1 to 9 do res[0]:=res[0]-res[j];
         for j:=0 to 9 do write(res[j],' ');
         writeln;
      end;
   close(input); close(output);
end;

BEGIN
   main;
END.

