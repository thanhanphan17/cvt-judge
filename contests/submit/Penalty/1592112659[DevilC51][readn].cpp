#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <exception>
#include <cassert>
#include <clocale>
const std::wstring CHU_SO[] = {
    L"khong", L"mot", L"hai", L"ba", L"bon",
    L"nam", L"sau", L"bay", L"tam", L"chin"
};
const std::wstring MUOIF = L"muoi"; 
const std::wstring MUOI = L"muoi";
const std::wstring TRAM = L"tram";
const std::wstring NGAN_TR[] = { L"nghin", L"trieu" };
const std::wstring TY = L"ty";
const std::wstring MOTS = L"mot";
const std::wstring TU = L"bon";
const std::wstring LAM = L"lam"; 
const std::wstring LINH = L"le";
const wchar_t SPACE = L' ';
const std::wstring COMMA = L" ";
std::wstring toVnStr(const std::string& num);

int main()
{
    freopen("readn.inp","r",stdin);
   freopen("readn.out","w+",stdout);
   int t;
    std::cin>>t;
    while(t--){
        std:: string s;
        std:: cin>>s;
        std::wcout << toVnStr(s) << "\n";
    }
}
std::wstring toVnStrLt100(const std::string& num)
{
    if (num.size() == 1) return CHU_SO[num[0] - '0'];
    auto result = num[0] == '1' ? MUOIF : (CHU_SO[num[0] - '0'] + SPACE + MUOI);
    if (num[1] == '0') return result;
    result += SPACE;
    if (num[1] == '1' && num[0] != '1') result += MOTS;
    else if (num[1] == '4' && num[0] != '1') result += TU;
    else if (num[1] == '5') result += LAM;
    else result += CHU_SO[num[1] - '0'];
    return result;
}
std::wstring toVnStrLt1000(const std::string& num)
{
    if (num.size() < 3) return toVnStrLt100(num);
    auto result = CHU_SO[num[0] - '0'] + SPACE + TRAM;
    if (num[1] == '0' && num[2] == '0') //[0-9]00
        return num[0] == '0' ? std::wstring{} : result;
    if (num[1] == '0')  //[1-9]0[1-9]
        return result + SPACE + LINH + SPACE + CHU_SO[num[2] - '0'];
    return result + SPACE + toVnStrLt100(num.substr(1));
}

std::wstring toVnStrLt1e9(const std::string& num)
{
    if (num.size() < 4) return toVnStrLt1000(num);
    int splitIndex = num.size() % 3;
    if (!splitIndex) splitIndex = 3;
    auto left = toVnStrLt1e9(num.substr(0, splitIndex));
    auto right = toVnStrLt1e9(num.substr(splitIndex));
    if (left.empty() && right.empty()) return std::wstring{};
    auto const& hang = NGAN_TR[(num.size() - splitIndex) / 3 - 1];
    if (left.empty()) return CHU_SO[0] + SPACE + hang + SPACE + right;
    if (right.empty()) return left + SPACE + hang;
    return left + SPACE + hang + SPACE + right;
}
std::wstring toVnStrAbitrary(const std::string& num)
{
    if (num.size() < 10) return toVnStrLt1e9(num);
    int splitIndex = num.size() % 9;
    if (!splitIndex) splitIndex = 9;
    auto left = toVnStrLt1e9(num.substr(0, splitIndex));
    auto right = toVnStrAbitrary(num.substr(splitIndex));
    if (left.empty()) return right;
    auto hang = TY;
    for (auto i = (num.size() - splitIndex) / 9; i-->1; hang += SPACE + TY);
    if (right.empty()) return left + SPACE + hang;
    return left + SPACE + hang + COMMA + right;
}
std::string stripZeros(const std::string& s, size_t z=0)
{
    while (z < s.size() && s[z] == '0') ++z;
    return s[z-1] == '0' ? s.substr(z) : s;
}
std::wstring toVnStr(const std::string& num)
{
    if (std::any_of(begin(num), end(num), [](auto c) { return !isdigit(c); }))
        throw std::invalid_argument("Input string must consist of digits (0-9) only.");
    auto s = stripZeros(num);
    return toVnStrAbitrary(s.empty() ? "0" : s);
}
