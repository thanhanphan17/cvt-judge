#include <bits/stdc++.h>

using namespace std;
char A[2005];
int n,k;
int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}

char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
string nhanNho(char a, string b)
{
    string s = "";
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)
    {
        temp = stringToNum(a) * stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}
bool sosanh(string a, string b)//true >
{
    if(a.length()<b.length()) return false;
    else if(a.length()>b.length()) return true;
    else
    {
        for(int i=0;i<a.length();i++)
            if(a[i]<b[i]) return false;
            else if(a[i]>b[i]) return true;
        return true;
    }
}
int main()
{
    freopen("AROWMAX.inp","r",stdin);
    freopen("AROWMAX.out","w+",stdout);
    string Tich="1",res="0",temp="0",Max="0";
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n-k+1;i++)
    {
       for(int j=i;j<=i+k-1;j++)
       {
           Tich=nhanNho(A[j],Tich);
       }
      // cout<<Tich<<endl;
      if(sosanh(Tich,Max)==true) Max=Tich;
       Tich="1";
    }
    if(Max[1]=='0') cout<<0; else cout<<Max;
}
