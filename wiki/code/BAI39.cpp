#include <iostream>
#include <stdio.h>
/* Ý tưởng là nếu lớn hơn số 9 thì mod 10 rồi nhân vô tiếp tục đến khi nhỏ hơn 10
mỗi lần nhân vô thì đếm tăng lên 1 đơn vị */
using namespace std;
int n,dem=0;
int m,u,Tich;
int main()
{
    freopen("BAI39.INP","r",stdin);
    freopen("BAI39.OUT","w+",stdout);
    cin>>n;
    while(n>9)
    {
        Tich=1; u=n;

        while(u>0)
        {
              m=u%10;
              Tich=Tich*m;
              u=u/10;
        }
        dem++;
        n=Tich;
    }
  cout<<dem;
}
