#include <bits/stdc++.h>
#define fi freopen("ARROWMAX.inp", "r" stdin)
#define fo freopen("ARROWMAX.out", "w", stdout)
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
    for(int i = b.length() - 1; i >= 0; --i)
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
    int l = s.length();
    while(l != 0)
    {
        a.push_back(s[l - 1]);
        l--;
    }
    string s1 = "";
    s1 = a[0];
    for(int i = 1; i < a.size(); ++i)
    {
        s1 = Nhan_so_1_chu_so_voi_so_nhieu_chu_so(a[i], s1);
    }
    return s1;
}

int main()
{
    fi;fo;
    int n, k;
    cin >> n >> k;
    string s, s1, s2 = "0";
    cin >> s;
    vector <string> v;
    for(int i = 0; i < s.length() - k; ++i)
    {
        s1 = s.substr(i, k);
        v.push_back(s1);
    }
    vector <string> a;
    for(int i = 0; i < v.size(); ++i)
        a.push_back(Xu_Ly_So_Lon(v[i]));
    for(int i = 0; i < a.size() - 1; ++i)
    {
        for(int j = i + 1; j < a.size(); ++j)
        {
            if(a[i].length() > a[j].length())
                swap(a[i], a[j]);
            else if(a[i].length() == a[j].length())
            {
                for(int h = 0; h < a[i].length(); ++h)
                {
                    if(a[i][h] > a[j][h])
                    {
                        swap(a[i], a[j]);
                        break;
                    }else if(a[i][h] < a[j][h])
                        break;
                    else if(a[i][h] == a[j][h])
                        continue;
                }
            }
        }
    }
    cout << a[a.size()-1];
}
