#include <iostream>
#include <string>
#include <fstream>
#include <bencode/bencode.hpp>
#include <cpr/cpr.h>
#include <crypto/sha1.h>
#include "utils.h"
#include "TorrentFile.h"

namespace bc = bencode;

void test()
{
    cpr::Response r = cpr::Get(
        cpr::Url{"https://tracker.avistaz.to/6d4665f2fa001b54204c822377978373/announce"},
        cpr::Parameters{{"user", "test"}},
        cpr::Timeout{500});
    // std::cout << "Status code: " << r.status_code << '\n';
    // std::cout << "Header:\n";
    // for (const std::pair<const std::basic_string<char>, std::basic_string<char>>& kv : r.header) {
    //     std::cout << '\t' << kv.first << ':' << kv.second << '\n';
    // }
    std::cout << "Text: " << r.text << '\n';
}

int main()
{
    // namespace bc = bencode;

    // std::fstream f("test.torrent");

    // if (!f.is_open())
    // {
    //     std::cout << "file not found" << std::endl;
    // }

    // std::stringstream iss;
    // iss << f.rdbuf();
    // std::string entireFile = iss.str();

    // bc::bvalue b = bc::decode_value(entireFile);

    // // check if the first list element is a string
    // if (holds_dict(b))
    // {
    //     std::cout << "dict" << std::endl;
    // }
    // else if (bc::holds_list(b))
    // {
    //     std::cout << "dict" << std::endl;
    // }
    // else if (bc::holds_string(b))
    // {
    //     std::cout << "string" << std::endl;
    // }
    // else
    // {
    //     std::cout << "no type" << std::endl;
    // }

    // print_dict(b);

    // test();
    
    TorrentFile file("test.torrent");

    std::cout<<file.getDecodedData()<<"\n";

    return 0;
}
