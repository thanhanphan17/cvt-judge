#include <bits/stdc++.h>
#define fi freopen("AROWMAX.inp", "r", stdin)
#define fo freopen("AROWMAX.out", "w", stdout)
using namespace std;

int stringtoNum(char a)
{
    return a - '0';
}

char numtoString(int n)
{
    return (char)(n + 48);
}

string Nhan_so_1_chu_so_voi_so_nhieu_chu_so(char a, string b)
{
    string s = "";
    int tmp = 0;
    for(long long i = b.length() - 1; i >= 0; --i)
    {
        tmp = stringtoNum(a) * stringtoNum(b[i]) + tmp;
        s.insert(0, 1, numtoString(tmp%10));
        tmp /= 10;
    }
    if(tmp > 0)
        s.insert(0, 1, numtoString(tmp));
    return s;
}

string Xu_Ly_So_Lon(string s)
{
    vector <char> a;
    long long l = s.length();
    while(l != 0)
    {
        a.push_back(s[l - 1]);
        l--;
    }
    string s1 = "";
    s1 = a[0];
    for(long long i = 1; i < a.size(); ++i)
        s1 = Nhan_so_1_chu_so_voi_so_nhieu_chu_so(a[i], s1);
    return s1;
}

string Chia_so_co_nhieu_chu_so_cho_so_1_chu_so(char a, string b, string c)
{
    string s = "";
    int n = 0, m = 0;
    if(c[1] != '0' && a == '0')
    {
        c.erase(0, 1);
        return Xu_Ly_So_Lon(c);
    }else if(c[1] == '0' && a == '0')
    {
        return "0";
    }
    for(int i = 0; i < b.length(); ++i)
    {
        n = n*10 + stringtoNum(b[i]);
        m = n / stringtoNum(a);
        n %= stringtoNum(a);
        s += numtoString(m);
    }
    while(s.length() > 1 && s[0] == '0')
        s = s.erase(0, 1);
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    fi;fo;
    long long n, k;
    cin >> n >> k;
    string s, s1, s2;
    cin >> s;
    vector <string> v, b;
    vector <long long> a;
    s1 = s.substr(0, k);
    v.push_back(Xu_Ly_So_Lon(s1));
    int d = 0;
    for(int i = k; i < s.length(); ++i)
    {
        s1 = s.substr(d, k);
        s2 = Chia_so_co_nhieu_chu_so_cho_so_1_chu_so(s[d], v[v.size()-1], s1);
        s2 = Nhan_so_1_chu_so_voi_so_nhieu_chu_so(s[i], s2);
        v.push_back(s2);
        a.push_back(s2.length());
        d++;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < v.size(); ++i)
        if(v[i].length() == a[a.size()-1])
            b.push_back(v[i]);
    sort(b.begin(), b.end());
    cout << b[b.size()-1];
}
