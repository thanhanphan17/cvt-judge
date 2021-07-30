#include <bits/stdc++.h>

using namespace std;
long long i,j,n,a,dd;
string s,r;
string docso(char a,int dv)
{
    string s;
    if(a=='1') s="mot";
    else if(a=='2') s="hai";
    else if(a=='3') s="ba";
    else if(a=='4') s="bon";
    else if(a=='5')
    {
        if(dv==1)s="nam";
        if(dv>1) s="lam";
    }
    else if(a=='6') s="sau";
    else if(a=='7') s="bay";
    else if(a=='8') s="tam";
    else if(a=='9') s="chin";
    else if(a=='0') s="khong";
    return s;
}
int main()
{
    cin>>s;
    while(s[0]=='0')
    {
        r="";
        dd=dd+1;
        for(i=1;i<=s.length();i++)
            r=r+s[i];
        s=r;
    }
    n=s.length()-dd;
    j=n+1;
    for(i=0;i<=n;i++)
    {
        j=j-1;
        if(j==1)
        {
            if(n==1) cout<<docso(s[i],n)<<" ";
            if(n>1 && s[i-1]>'0' && s[i]>'0') cout<<docso(s[i],n)<<" ";
            if(n>1 && s[i-1]=='0' && s[i]>'0') cout<<docso(s[i],1)<<" ";
        }
        if(j==2 && s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
        if(j==2 && s[i]=='1') cout<<"muoi"<<" ";
        if(j==2 && s[i]=='0' && s[i+1]>'0') cout<<"le"<<" ";
        if(j==3)
        {
            if(s[i]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            if(s[i]=='0')
            {
                if(s[i+1]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
                else if(s[i+2]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            }
        }
        if(j==4)
        {
            if(n==4) cout<<docso(s[i],1)<<" "<<"nghin"<<" ";
            else if(n>4 && s[i-1]>'0' && s[i]>'0') cout<<docso(s[i],n)<<" "<<"nghin"<<" ";
            else if(n>4 && s[i-1]=='0' && s[i]>'0') cout<<docso(s[i],1)<<" "<<"nghin"<<" ";
            else if(n>4 && s[i-1]=='0' && s[i]=='0' && s[i-2]>'0') cout<<"nghin"<<" ";
            else if(n>4 && s[i-1]>'0' && s[i]=='0') cout<<"nghin"<<" ";
            else if(n>4 && s[i-2]>'0'&& s[i]=='0') cout<<"nghin"<<" ";
        }
        if(j==5)
        {
            if(n==5 && s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
            else if(n==5 && s[i]=='1') cout<<"muoi"<<" ";
            else if(n>5 && s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
            else if(n>5 && s[i]=='1') cout<<"muoi"<<" ";
            else if(n>5 && s[i]=='0' && s[i+1]>'0') cout<<"le"<<" ";
        }
        if(j==6)
        {
            if(n>6 && s[i]=='0')
            {
                if(s[i+1]>'0')cout<<docso(s[i],1)<<" "<<"tram"<<" ";
                else if(s[i+2]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            }
            if(s[i]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
        }
        if(j==7)
        {
            //if(n==4) cout<<docso(s[i],1)<<" "<<"trieu"<<" ";
            if(n>7 && s[i]=='0' && s[i-1]>'0') cout<<"trieu"<<" ";
            else if(n>7 && s[i]=='0' && s[i-2]>'0') cout<<"trieu"<<" ";
            if(s[i]>'0' && s[i-1]=='0') cout<<docso(s[i],1)<<" "<<"trieu"<<" ";
            if(s[i]>'0' && s[i-1]!='0') cout<<docso(s[i],n)<<" "<<"trieu"<<" ";
        }
        if(j==8)
        {
            if(s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
            if(s[i]=='1') cout<<"muoi"<<" ";
            if(s[i]=='0' && s[i+1]>'0' ) cout<<"le"<<" ";
        }
        if(j==9)
        {
            if(s[i]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            if(s[i]=='0')
            {
                if(s[i+1]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
                else if(s[i+2]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            }
        }
        if(j==10)
        {
            if(n>10 && s[i]=='0' && s[i-1]=='0') cout<<"ty"<<" ";
            if(n>10 && s[i]=='0' && s[i-2]=='0') cout<<"ty"<<" ";
            if(s[i]>'0' && s[i-1]>'0') cout<<docso(s[i],n)<<" "<<"ty"<<" ";
            if(s[i]>'0' && s[i-1]=='0') cout<<docso(s[i],1)<<" "<<"ty"<<" ";
        }
        if(j==11)
        {
            if(s[i]>'1') cout<<docso(s[i],1)<<" "<<"muoi"<<" ";
            if(s[i]=='1') cout<<"muoi"<<" ";
            if(s[i]=='0' && s[i+1]>'0') cout<<"le"<<" ";
        }
        if(j==12)
        {
            if(s[i]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            if(s[i]==0)
            {
                if(s[i+1]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
                else if(s[i+2]>'0') cout<<docso(s[i],1)<<" "<<"tram"<<" ";
            }
        }
    }
    return 0;
}
