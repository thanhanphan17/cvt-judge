// Ý tưởng là dùng duyệt trâu 2 for. Vì giới hạn và 1000 nên độ phức tạp sẽ là
// O(10e6). Nếu mà i+j=n và i,j không có ước chung tức ước chung bằng 1 thì xuất
// i,j.Nhưng như vậy sẽ có nhiều i,j nên đưa vô mãng lấy phần tử cuối.
#include <bits/stdc++.h>
using namespace std;
int n,i,j,dem=0;
int a[1000],b[1000];
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("BAI55.INP","r",stdin);
    freopen("BAI55.OUT","w+",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
           if(i+j==n && gcd(i,j)==1 && i<j)
           {
               a[dem]=i;
               b[dem]=j;
                dem++;
           }
        }
    }
     cout<<a[dem-1]<<"/"<<b[dem-1];
}
