#include <iostream>
#include <stdio.h>
using namespace std;
int d,m,y,res,i;
bool NamNhuan(int x)
{
    if(x % 400== 0) return true;
    if(x%100!=0 && x%4==0) return true;
    return false;
}
int main()
{
    freopen("BAI27.INP","r",stdin);
    freopen("BAI27.OUT","w+", stdout);
    cin>>d>>m>>y;
    for(i=1;i<=y-1;i++)
    if(NamNhuan(i)) res=res+366; else res=res+365;
    for(i=1;i<=m-1;i++)
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
          res=res+31;
        if(i==2)
        {
            if(NamNhuan(y)) res=res+29; else res=res+28;
        }
        if(i==4||i==6||i==9||i==11)
            res=res+30;
    }

    res=res+d;
    cout<<res;


}
