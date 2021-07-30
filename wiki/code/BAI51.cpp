// Ý tưởng là: Vì số tiền bằng 1 thì end game nên đặt end game 1
// Đặt max bằng n
// Cho 1 while n>1 thì kiểm tra chẳn lẻ, chẳn thì n=n+2*n+1, lẻ thì n=n/2
// Sau khi thực hiện thì kiểm tra max và n biến nào lớn hơn
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define EndGame 1

int n,MAXX=0;
bool XetChanLe(int x)
{
    if(x%2!=0) return true;
    return false;
}
int main()
{
    freopen("BAI51.INP","r",stdin);
    freopen("BAI51.OUT","w+",stdout);
    cin>>n;
    MAXX=n;
    while(n>EndGame)
    {
        if (XetChanLe(n)==true) n=n+2*n+1; else n=n/2;
        if (n>MAXX) MAXX=n;
    }
    cout<<MAXX;
}
