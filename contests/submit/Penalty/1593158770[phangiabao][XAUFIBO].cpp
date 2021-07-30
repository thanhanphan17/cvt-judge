#include <bits/stdc++.h>
#define fi freopen("XAUFIBO.inp", "r", stdin)
#define fo freopen("XAUFIBO.out", "w", stdout)
using namespace std;

int main()
{
    fi;fo;
    int n, m, l;
    while(cin >> n >> m >> l)
    {
        string s[n];
        s[0] = "b";
        s[1] = "a";
        for(int i = 2; i < n; ++i)
            s[i] = s[i-1] + s[i-2];
        if(m > s[n-1].length())
        {
            cout << 0 << " [0]" << "\n";
            continue;
        }
        int d;
        if(m + l > s[n-1].length())
            d = (s[n-1].length() - m + 1);
        else d = l;
        cout << d << " [";
        for(int i = m - 1; i < m + d - 1; ++i)
            cout << s[n-1][i];
        cout << "]" << "\n";
    }
}
