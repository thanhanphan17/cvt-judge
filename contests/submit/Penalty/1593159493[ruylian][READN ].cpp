#include <bits/stdc++.h>

using namespace std;
int i,j,n,dd,t,k;
string s,r;
string docso(char a,int th)
{
    if(a=='0') return "khong";
    if(a=='1') return "mot";
    if(a=='2') return "hai";
    if(a=='3') return "ba";
    if(a=='4') return "bon";
    if(a=='5') if(th==1) return "nam";else return "lam";
    if(a=='6') return "sau";
    if(a=='7') return "bay";
    if(a=='8') return "tam";
    if(a=='9') return "chin";
}
void chuc(int i)
{
    if(s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
    if(s[i]=='1') cout<<"muoi"<<" ";
    if(s[i]=='0' && s[i+1]>'0') cout<<"le"<<" ";
}
void tram(int i)
{
    if(s[i]>'0')  cout<<docso(s[i],1)<<" "<<"tram"<<" ";
    if(s[i]=='0')
    {
        if(s[i+1]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
        else if(s[i+2]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
    }
}
void donvi(int i,string hang)
{
    if(n==1) cout<<docso(s[i],1);
    if(n>1)
    {
        if(s[i]>'0')
        {
            if(s[i-1]>'0') cout<<docso(s[i],2)<<" "<<hang<<" ";
            else cout<<docso(s[i],1)<<" "<<hang<<" ";
        }
        //if(s[i]>'0' && s[i-1]==0) cout<<docso(s[i],1)<<" "<<hang<<" ";
        if(s[i]=='0')
        {
            if(s[i-1]>'0') cout<<hang<<" ";
            else if(s[i-2]>'0') cout<<hang<<" ";
        }
    }
}
int main()
{
    freopen("READN.inp","r",stdin);
    freopen("READN.out","w",stdout);
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>s;
        dd=0;
        while(s[0]=='0')
        {
            r="";
            for(i=1;i<=s.length();i++)
                r=r+s[i];
            s=r;
            dd=dd+1;
        }
        n=s.length()-dd;
        j=n+1;
        for(i=0;i<=n;i++)
        {
            j=j-1;
            if(j==1) donvi(i,"");
            if(j==4) donvi(i,"nghin");
            if(j==7) donvi(i,"trieu");
            if(j==10) donvi(i,"ty");
            if((j+1)%3==0) chuc(i);
            if(j%3==0) tram(i);
        }
        cout<<endl;
    }
    return 0;
}
