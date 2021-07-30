#include <bits/stdc++.h>
#define fi freopen("SQROOT.inp", "r", stdin)
#define fo freopen("SQROOT.out", "w", stdout)
using namespace std;

string NumtoString(int n)
{
    string res;
    ostringstream convert;
    convert << n;
    res = convert.str();
    return res;
}

int stringtoNum(char a)
{
    return a - '0';
}

char numtoString(int n)
{
    return (char)(n + 48);
}

int StringtoNum(string s)
{
    stringstream s1(s);
    int x = 0;
    s1 >> x;
    return x;
}

void chuan_hoa(string &a, string &b)
{
    while(a.length() < b.length())
        a = "0" + a;
    while(a.length() > b.length())
        b = "0" + b;
}

string sum(string a, string b)
{
    chuan_hoa(a, b);
    string s = "";
    int tmp = 0, n = 0;
    for(int i = a.length() - 1; i >= 0; --i)
    {
        tmp = stringtoNum(a[i]) + stringtoNum(b[i]) + tmp;
        n = tmp%10;
        s.insert(0, 1, numtoString(n));
        tmp /= 10;
    }
    if(tmp > 0)
        s.insert(0, 1, numtoString(tmp));
    return s;
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

string mul(string a, string b)
{
    string s = "";
    int len = a.length();
    string s1[len];
    for(int i = len - 1; i >= 0; --i)
    {
        s1[i] = Nhan_so_1_chu_so_voi_so_nhieu_chu_so(a[i], b);
        s1[i].insert(s1[i].length(), len - i - 1, '0');
        s = sum(s, s1[i]);
    }
    while(s.length() > 1 && s[0] == '0')
        s.erase(0, 1);
    return s;
}

int main()
{
    fi;fo;
    string s, s1 = "";
    cin >> s;
    int a[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 99};
    vector <string> v;
    if(s.length() % 2 == 1)
    {
        v.push_back(s.substr(0, 1));
        for(int i = 1; i < s.length(); i += 2)
            v.push_back(s.substr(i, 2));
    }else {
        for(int i = 0; i < s.length(); i += 2)
            v.push_back(s.substr(i, 2));
    }
    for(int i = 0; i < v.size(); ++i)
    {
        if(i == 0)
        {
            for(int j = 0; j < 9; ++j)
                if(StringtoNum(v[i]) > a[j] && StringtoNum(v[i]) < a[j+1])
                    s1 += NumtoString(j + 1);
                else if(StringtoNum(v[i]) == a[j])
                    s1 += NumtoString(j + 1);
        }else {
            for(int j = 0; j < 10; ++j)
            {
                string s2 = s1 + NumtoString(j);
                string m = mul(s2, s2);
                if(m > v[i] && m.length() >= v[i].length())
                {
                    s1 += NumtoString(j - 1);
                    break;
                }else if(m == v[i])
                {
                    s1 += NumtoString(j);
                    break;
                }
            }
        }
        if(i < v.size() - 1)
            v[i+1] = v[i] + v[i+1];
    }
    cout << s1;
}
