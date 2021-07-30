#include <stdio.h>
#include <iostream>

using namespace std;
int dd[1000];
int DQ(int n, int k)
{
  if (n == 1)
    return 1;
  else  return (DQ(n - 1, k) + k-1) % n + 1;
}
int main()
{
    int n,k,s;
    int res1,res2=0;
    cin>>n>>s>>k;
    res1=DQ(n,s);
    if (res1<=k) res2=1+(k-res1); else res2=n+1-(res1-k);
    cout<<res2;
}
