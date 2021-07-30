#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cassert>
#ifdef __unix__
#include <clocale>
#elif defined _WIN32 || defined _WIN64
#include <fcntl.h> //_O_WTEXT
#include <io.h> //_setmode()
#endif

const std::wstring CHU_SO[] = {
    L"không", L"một", L"hai", L"ba", L"bốn",
    L"năm", L"sáu", L"bảy", L"tám", L"chín"
};
const std::wstring MUOIF = L"mười"; //muoi` co' dau'
const std::wstring MUOI = L"mươi";
const std::wstring TRAM = L"trăm";
const std::wstring NGAN_TR[] = { L"nghìn", L"triệu" };
const std::wstring TY = L"tỷ";
const std::wstring MOTS = L"mốt"; //mot' co dau sac
const std::wstring TU = L"tư"; //tu
const std::wstring LAM = L"lăm"; //lam
const std::wstring LINH = L"linh";
const wchar_t SPACE = L' ';
const std::wstring COMMA = L", ";

std::wstring toVnStr(const std::string& num);

int main()
{

    std::string testCases[] = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "20", "21", "22", "24", "90", "91", "97",
        "300", "999", "121", "215", "5121", "39500",
        "1025217", "51105500", "51000000", "999999999",
        "5120625952200", "12000000000000000000", "18446744073709551615",
        "18000000000709551615",
        "1000015", "1002015", "1000000024",
        "03215", "", "0000", "00001", "00100",
        "1844674407370955161518000000000000000000709551615",
        "0321", "000345", "15", "40430203", "3209", "3500", "3901", "21",
        "3005", "3055", "9031", "9330",
        "9000005", "9001005",
    };
    for (auto const& s : testCases)
        std::wcout << s.c_str() << " = " << toVnStr(s) << "\n";

    //http://giaibaitaptoan.net/giai-toan-4-bai-trieu-va-lop-trieu-tiep-theo-35-1681.html
    std::pair<std::string, std::wstring> testCaseWithAnswers[] = {
        {"32000000", L"ba mươi hai triệu"},
        {"32516000", L"ba mươi hai triệu năm trăm mười sáu nghìn"},
        {"32516497", L"ba mươi hai triệu năm trăm mười sáu nghìn bốn trăm chín mươi bảy"},
        {"834291712", L"tám trăm ba mươi tư triệu hai trăm chín mươi mốt nghìn bảy trăm mười hai"},
        {"308250705", L"ba trăm linh tám triệu hai trăm năm mươi nghìn bảy trăm linh năm"},
        {"500209037", L"năm trăm triệu hai trăm linh chín nghìn không trăm ba mươi bảy"},
        {"7312836", L"bảy triệu ba trăm mười hai nghìn tám trăm ba mươi sáu"},
        {"57602511", L"năm mươi bảy triệu sáu trăm linh hai nghìn năm trăm mười một"},
        {"351600307", L"ba trăm năm mươi mốt triệu sáu trăm nghìn ba trăm linh bảy"},
        {"900370200", L"chín trăm triệu ba trăm bảy mươi nghìn hai trăm"},
        {"400070192", L"bốn trăm triệu không trăm bảy mươi nghìn một trăm chín mươi hai"},
        {"10250214", L"mười triệu hai trăm năm mươi nghìn hai trăm mười bốn"},
        {"253564888", L"hai trăm năm mươi ba triệu năm trăm sáu mươi tư nghìn tám trăm tám mươi tám"},
        {"400036105", L"bốn trăm triệu không trăm ba mươi sáu nghìn một trăm linh năm"},
        {"700000231", L"bảy trăm triệu không nghìn hai trăm ba mươi mốt"},
    };
    std::wcout << "\n";
    for (auto const& p : testCaseWithAnswers)
    {
        assert(p.second == toVnStr(p.first));
        std::wcout << p.first.c_str() << "\n"
                   << p.second << "\n"
                   << toVnStr(p.first) << "\n\n";
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
