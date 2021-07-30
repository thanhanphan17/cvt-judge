#include <bits/stdc++.h>
#define fi freopen("BDTONG.inp", "r", stdin)
#define fo freopen("BDTONG.out", "w", stdout)
using namespace std;
int UCLN(int a, int b)
{
    if(a == b)
        return a;
    int mi = min(a, b), res = 1;
    for(int i = 1; i <= mi; ++i)
        if(a % i == 0 && b % i == 0)
            res = i;
    return res;
}

int BCNN(int a, int b)
{
    long long ma = a*b, lcm;
    int t = max(a, b);
    for(int i = t; i <= ma; i += t)
        if(i % a == 0 && i % b == 0)
        {
            lcm = i;
            break;
        }
    return lcm;
}

int main()
{
    fi;fo;
    double m, n;
    while(cin >> m >> n)
    {
        double p = m/UCLN(m, n), q = n/UCLN(m, n);
        double k, tmp, tmp1, tmp2;
        for(double i = 1; i <= 100000; ++i)
        {
            tmp = 1/i;
            if(tmp <= p/q)
            {
                k = i;
                break;
            }
        }
        tmp1 = p;
        tmp2 = q;
        vector <int> v;
        for(double i = k; i <= 100000; ++i)
        {
            tmp = 1/i;
            if(tmp <= tmp1/tmp2)
            {
                if(tmp1 != 1)
                {
                    tmp1 = tmp1*i - tmp2;
                    tmp2 = tmp2*i;
                    v.push_back(i);
                    int tam1 = tmp1, tam2 = tmp2;
                    tmp2 = tmp2/UCLN(tam1, tam2);
                    tmp1 = tmp1/UCLN(tam1, tam2);
                }
                if(tmp1 == 1)
                {
                    v.push_back(tmp2);
                    break;
                }
            }
        }
        cout << p << " " << q << " " << k << " " << v.size() << " [";
        for(int i = 0; i < v.size(); ++i)
            if(i != v.size() - 1)
                cout << v[i] << " ";
            else cout << v[i];
        cout << "]" << "\n";
    }
}
