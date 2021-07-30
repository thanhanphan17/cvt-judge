#include <iostream>

using namespace std;
bool palin(int n)
{
    int m,u;
    u=n;
    m=0;
    do
    {
        m=m*10+u%10;
        u=u/10;
    }
    while(u=0);
    return n;
}
int main()
{
    int m,n,u;
    cin>>n;
    do
    {
        m=0; u=n;
        do
        {
            m=m*10+u%10;
            u=u/10;
        }
        while(u=0);
        n=n+m;
    }
    while(palin(n));
    cout<<n;
}
