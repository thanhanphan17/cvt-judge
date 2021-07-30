const
   tfi='sqroot.in';
   tfo='sqroot.out';

type
   sn=string;

function sub(a,b: sn): sn;
var i, nho, hieu: longint;
    c: sn;
begin
   while length(b)<length(a) do b:='0'+b;
   c:='';
   nho:=0;
   for i:=length(a) downto 1 do
      begin
         hieu:=ord(a[i])-ord(b[i])-nho;
         if hieu<0 then
            begin
               inc(hieu,10);
               nho:=1;
            end
         else nho:=0;
         c:=chr(hieu+48)+c;
      end;
   while (length(c)>1) and (c[1]='0') do delete(c,1,1);
   exit(c);
end;

function divk(a: sn; k: longint): sn;
var b: sn;
    i, du: longint;
begin
   b:='';
   du:=0;
   for i:=1 to length(a) do
      begin
         du:=du*10+ord(a[i])-48;
         b:=b+chr(du div k+48);
         du:=du mod k;
      end;
   while (length(b)>1) and (b[1]='0') do delete(b,1,1);
   exit(b);
end;

function add(a, b: sn): sn;
var c: sn;
    i, nho, tong: longint;
begin
   while length(a)<length(b) do a:='0'+a;
   while length(b)<length(a) do b:='0'+b;
   c:='';
   nho:=0;
   for i:=length(a) downto 1 do
      begin
         tong:=nho+ord(a[i])+ord(b[i])-96;
         c:=chr(tong mod 10+48)+c;
         nho:=tong div 10;
      end;
   if nho>0 then c:='1'+c;
   exit(c);
end;

function mul(a, b: sn): sn;
var c: sn;
    cn, i, nho, tong, j, k: longint;
begin
   cn:=length(a)+length(b);
   while length(a)<cn do a:='0'+a;
   while length(b)<cn do b:='0'+b;
   c:='';
   nho:=0;
   for i:=0 to cn-1 do
      begin
         tong:=nho;
         for j:=0 to i do
            begin
               k:=i-j;
               tong:=tong+(ord(a[cn-j])-48)*(ord(b[cn-k])-48);
            end;
         c:=chr(tong mod 10+48)+c;
         nho:=tong div 10;
      end;
   while (length(c)>1) and (c[1]='0') do delete(c,1,1);
   exit(c);
end;

function cmp(a,b: sn): longint;
begin
   if length(a)<length(b) then exit(-1);
   if length(a)>length(b) then exit(1);
   if a=b then exit(0);
   if a<b then exit(-1);
   exit(1);
end;

procedure r_sqr(x: sn; var y: sn; var ok: boolean);
var d, c, g: sn;
begin
   d:='1'; c:='2';
   while cmp(mul(c,c),x)<>1 do
      begin
         d:=c;
         c:=add(c,c);
      end;
   repeat
      g:=divk(add(c,d),2);
      if cmp(mul(g,g),x)=1 then c:=g else d:=g;
   until sub(c,d)='1';
   y:=d;
   ok:=cmp(mul(y,y),x)=0;
end;

var n, m: sn;
    ok: boolean;

BEGIN
  assign(input,tfi); reset(input);
   assign(output,tfo); rewrite(output);
   readln(n);
   r_sqr(n,m,ok);
   writeln(m);
   close(input); close(output);
END.
