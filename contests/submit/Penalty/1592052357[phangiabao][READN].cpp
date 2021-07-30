#include <bits/stdc++.h>
#define fi freopen("READN.inp", "r", stdin)
#define fo freopen("READN.out", "w", stdout)
using namespace std;
string doc_so(char s, int pos)
{
    if(s == '1')
        return "mot";
    if(s == '2')
        return "hai";
    if(s == '3')
        return "ba";
    if(s == '4')
        return "bon";
    if(s == '5' && pos % 3 != 0)
        return "nam";
    else if(s == '5' && pos % 3 == 0)
        return "lam";
    if(s == '6')
        return "sau";
    if(s == '7')
        return "bay";
    if(s == '8')
        return "tam";
    if(s == '9')
        return "chin";
    if(s == '0')
        return "khong";
}
int main()
{
    fi;fo;
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        string a[3] = {"nghin", "trieu", "ty"};
        cin >> s;
        if(s.length() == 1 && s == "0")
        {
            cout << "khong" << "\n";
            continue;
        }
        while(s[0] == '0')
            s = s.erase(0, 1);
        long long len = s.length();
        if(len % 3 == 0)
        {
            vector <string> v, s1;
            int d;
            for(int i = 0; i < len/3; ++i)
                v.push_back(s.substr(i*3, 3));
            d = v.size() - 2;
            for(int i = 0; i < v.size(); ++i)
            {
                for(int j = 0; j < v[i].length(); ++j)
                {
                    if(v[i][j] == v[i][j+1] && v[i][j+1] == v[i][j+2] && v[i][j] == '0')
                        break;
                    if(v[i][j] == v[i][j+1] && j == 1 && v[i][j] == '0')
                        break;
                    if(v[i][j] == '0' && j == 2)
                        break;
                    s1.push_back(doc_so(v[i][j], j + 1));
                    if((j + 1) % 3 == 1)
                        s1.push_back("tram");
                    if(s1[s1.size()-1] == "mot" && j == 1)
                        s1.pop_back();
                    if(s1[s1.size()-1] == "khong")
                    {
                        s1.pop_back();
                        s1.push_back("le");
                    }
                    if(s1[s1.size()-1] == "le")
                        continue;
                    if((j + 1) % 3 == 2)
                        s1.push_back("muoi");
                    if(s1[s1.size()-1] == "lam")
                    {
                        if(s1[s1.size()-2] == "le")
                        {
                            s1.pop_back();
                            s1.push_back("nam");
                        }
                    }
                }
                if(s1[s1.size()-1] == "khong")
                    s1.pop_back();
                if(d >= 0 && s1[s1.size()-1] != a[d + 1])
                    s1.push_back(a[d]);
                d--;
            }
            for(int i = 0; i < s1.size(); ++i)
                cout << s1[i] << " ";
            cout << "\n";
        }else if(len % 3 == 1)
        {
            vector <string> v, s1;
            int d;
            v.push_back(s.substr(0, 1));
            s = s.erase(0, 1);
            len = s.length();
            for(int i = 0; i < len/3; ++i)
                v.push_back(s.substr(i*3, 3));
            d = v.size() - 2;
            for(int i = 0; i < v.size(); ++i)
            {
                if(v[i].length() == 1)
                    s1.push_back(doc_so(v[i][0], 1));
                for(int j = 0; j < v[i].length(); ++j)
                {
                    if(v[i].length() == 1)
                        break;
                    if(v[i][j] == v[i][j+1] && v[i][j+1] == v[i][j+2] && v[i][j] == '0')
                        break;
                    if(v[i][j] == v[i][j+1] && j == 1 && v[i][j] == '0')
                        break;
                    if(v[i][j] == '0' && j == 2)
                        break;
                    s1.push_back(doc_so(v[i][j], j + 1));
                    if((j + 1) % 3 == 1)
                        s1.push_back("tram");
                    if(s1[s1.size()-1] == "mot" && j == 1)
                        s1.pop_back();
                    if(s1[s1.size()-1] == "khong")
                    {
                        s1.pop_back();
                        s1.push_back("le");
                    }
                    if(s1[s1.size()-1] == "le")
                        continue;
                    if((j + 1) % 3 == 2)
                        s1.push_back("muoi");
                    if(s1[s1.size()-1] == "lam")
                    {
                        if(s1[s1.size()-2] == "le")
                        {
                            s1.pop_back();
                            s1.push_back("nam");
                        }
                    }
                }
                if(s1[s1.size()-1] == "khong")
                    s1.pop_back();
                if(d >= 0 && s1[s1.size()-1] != a[d + 1])
                    s1.push_back(a[d]);
                d--;
            }
            for(int i = 0; i < s1.size(); ++i)
                cout << s1[i] << " ";
            cout << "\n";
        }else if(len % 3 == 2)
        {
            vector <string> v, s1;
            int d;
            v.push_back(s.substr(0, 2));
            s = s.erase(0, 2);
            len = s.length();
            for(int i = 0; i < len/3; ++i)
                v.push_back(s.substr(i*3, 3));
            d = v.size() - 2;
            for(int i = 0; i < v.size(); ++i)
            {
                if(v[i].length() == 2)
                {
                    for(int j = 0; j < v[i].length(); ++j)
                    {
                        s1.push_back(doc_so(v[i][j], j + 1));
                        if(s1[s1.size()-1] == "mot" && j == 0)
                            s1.pop_back();
                        if((j + 1) % 3 == 1)
                            s1.push_back("muoi");
                    }
                    if(s1[s1.size()-1] == "nam")
                    {
                        s1.pop_back();
                        s1.push_back("lam");
                    }
                }
                for(int j = 0; j < v[i].length(); ++j)
                {
                    if(v[i].length() == 2)
                        break;
                    if(v[i][j] == v[i][j+1] && v[i][j+1] == v[i][j+2] && v[i][j] == '0')
                        break;
                    if(v[i][j] == v[i][j+1] && j == 1 && v[i][j] == '0')
                        break;
                    if(v[i][j] == '0' && j == 2)
                        break;
                    s1.push_back(doc_so(v[i][j], j + 1));
                    if((j + 1) % 3 == 1)
                        s1.push_back("tram");
                    if(s1[s1.size()-1] == "mot" && j == 1)
                        s1.pop_back();
                    if(s1[s1.size()-1] == "khong")
                    {
                        s1.pop_back();
                        s1.push_back("le");
                    }
                    if(s1[s1.size()-1] == "le")
                        continue;
                    if((j + 1) % 3 == 2)
                        s1.push_back("muoi");
                    if(s1[s1.size()-1] == "lam")
                    {
                        if(s1[s1.size()-2] == "le")
                        {
                            s1.pop_back();
                            s1.push_back("nam");
                        }
                    }
                }
                if(s1[s1.size()-1] == "khong")
                    s1.pop_back();
                if(d >= 0 && s1[s1.size()-1] != a[d + 1])
                    s1.push_back(a[d]);
                d--;
            }
            for(int i = 0; i < s1.size(); ++i)
                cout << s1[i] << " ";
            cout << "\n";
        }
    }
}
