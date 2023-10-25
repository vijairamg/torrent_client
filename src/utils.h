#ifndef UTILS_H
#define UTILS_H
#include <bencode/bencode.hpp>


inline unsigned char to_hex(unsigned char x)
{
    return x + (x > 9 ? ('A' - 10) : '0');
}

std::string hexDecode(const std::string& value)
{
    int hashLength = value.length();
    std::string decodedHexString;
    for (int i = 0; i < hashLength; i += 2)
    {
        std::string byte = value.substr(i, 2);
        char c = (char) (int) strtol(byte.c_str(), nullptr, 16);
        decodedHexString.push_back(c);
    }
    return decodedHexString;
}

const std::string urlencode(const std::string &s)
{
    std::ostringstream os;

    for (std::string::const_iterator ci = s.begin(); ci != s.end(); ++ci)
    {
        if ((*ci >= 'a' && *ci <= 'z') ||
            (*ci >= 'A' && *ci <= 'Z') ||
            (*ci >= '0' && *ci <= '9'))
        { // allowed
            os << *ci;
        }
        else if (*ci == ' ')
        {
            os << '+';
        }
        else
        {
            os << '%' << to_hex(*ci >> 4) << to_hex(*ci % 16);
        }
    }

    return os.str();
}

inline unsigned char from_hex(unsigned char ch)
{
    if (ch <= '9' && ch >= '0')
        ch -= '0';
    else if (ch <= 'f' && ch >= 'a')
        ch -= 'a' - 10;
    else if (ch <= 'F' && ch >= 'A')
        ch -= 'A' - 10;
    else
        ch = 0;
    return ch;
}

const std::string urldecode(const std::string &str)
{
    using namespace std;
    string result;
    string::size_type i;
    for (i = 0; i < str.size(); ++i)
    {
        if (str[i] == '+')
        {
            result += ' ';
        }
        else if (str[i] == '%' && str.size() > i + 2)
        {
            const unsigned char ch1 = from_hex(str[i + 1]);
            const unsigned char ch2 = from_hex(str[i + 2]);
            const unsigned char ch = (ch1 << 4) | ch2;
            result += ch;
            i += 2;
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}

namespace bc = bencode;

void print_dict(bc::bvalue &b)
{

    auto dict_view = bc::get_dict(b);

    for (auto el : dict_view)
    {
        std::cout << el.first << std::endl;

        // if (el.first == "pieces")
        // {
        //     std::ofstream myfile;
        //     myfile.open("example.txt");

        //     int input = 0;

        //     SHA1 tool;
        //     tool.update(bencode::encode(b));
        //     myfile << tool.final();
            
        //     std::cout<<hexDecode(tool.final())<<"\n";
        //     std::cin>>input;

        //     myfile.close();
        //     continue;
        // }

        if (bc::holds_string(el.second))
        {
            std::string annouce = bc::get_string(el.second);
            std::cout << annouce << std::endl;
        }
        else if (bc::holds_integer(el.second))
        {
            std::cout << bc::get_integer(el.second) << std::endl;
        }
        else if (bc::holds_dict(el.second))
        {
            print_dict(el.second);
        }
    }
}

#endif /*UTLIS_H*/