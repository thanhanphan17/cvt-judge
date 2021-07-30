#include <bits/stdc++.h>
#define fi freopen("MATKHAU.inp", "r", stdin)
#define fo freopen("MATKHAU.out", "w", stdout)
using namespace std;
int kt_xau(string s)
{
    int n = 1, h = 1, t = 1;
    vector <char> S, H, T;
    for(int i = 0; i < s.length(); ++i)
    {
        if((int)s[i] <= 57)
            S.push_back(s[i]);
        else if((int)s[i] >= 65 && (int)s[i] <= 90)
            H.push_back(s[i]);
        else if((int)s[i] >= 97 && (int)s[i] <= 122)
            T.push_back(s[i]);
    }
    sort(S.begin(), S.end());
    sort(H.begin(), H.end());
    sort(T.begin(), T.end());
    if(S.size() != 0)
    {
        for(int i = 0; i < S.size() - 1; ++i)
            if(S[i] != S[i+1])
                n++;
    }
    else n = 0;
    if(H.size() != 0)
    {
        for(int i = 0; i < H.size() - 1; ++i)
            if(H[i] != H[i+1])
                h++;
    }
    else h = 0;
    if(T.size() != 0)
    {
        for(int i = 0; i < T.size() - 1; ++i)
            if(T[i] != T[i+1])
                t++;
    }
    else t = 0;
    if(n >= 2 && h >= 2 && t >= 2)
        return 2;
    else if(n >= 1 && h >= 1 && t >= 1)
        return 1;
    else return 0;
}
int main()
{
    fi;fo;
    string s;
    while(cin >> s)
    {
        string s1;
        s1 = s;
        sort(s1.begin(), s1.end());
        int nH = 1, nT = 1, nS = 1;
        vector <char> H, T, S;
        for(int i = 0; i < s1.length(); ++i)
        {
            if((int)s1[i] <= 57)
                S.push_back(s1[i]);
            else if((int)s1[i] >= 65 && (int)s1[i] <= 90)
                H.push_back(s1[i]);
            else if((int)s1[i] >= 97 && (int)s1[i] <= 122)
                T.push_back(s1[i]);
        }
        sort(S.begin(), S.end());
        sort(H.begin(), H.end());
        sort(T.begin(), T.end());
        for(int i = 0; i < S.size() - 1; ++i)
            if(S[i] != S[i+1])
                nS++;
        for(int i = 0; i < H.size() - 1; ++i)
            if(H[i] != H[i+1])
                nH++;
        for(int i = 0; i < T.size() - 1; ++i)
            if(T[i] != T[i+1])
                nT++;
        string k1, k2;
        if(nH == 1 || nT == 1 || nS == 1)
            k2 = "0";
        else if(nH == 0 || nT == 0 || nS == 0)
        {
            k1 = "0";
            k2 = "0";
        }
        if(s.length() >= 6)
        {
            int len1 = 999, len2 = 999;
            for(int i = 0; i < s.length(); ++i)
            {
                for(int j = 6; j <= s.length() - i; ++j)
                {
                    string s2 = s.substr(i, j);
                    int kt;
                    if(s2.length() >= 6)
                    {
                        kt = kt_xau(s2);
                        if(kt == 1)
                        {
                            if(s2.length() < len1)
                            {
                                k1 = s2;
                                len1 = s2.length();
                            }
                        }
                        else if(kt == 2)
                        {
                            if(s2.length() < len2)
                            {
                                k2 = s2;
                                len2 = s2.length();
                            }
                        }
                    }
                }
            }
        }
        if(s.length() < 6)
        {
            k1 = "0";
            k2 = "0";
        }
        cout << nH << " " << nT << " " << nS << " " << k1 << " " << k2 << "\n";
    }
}
