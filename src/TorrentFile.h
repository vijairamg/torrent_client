#ifndef TorrentFile_H
#define TorrentFile_H

#include <string>
#include <fstream>
#include <bencode/bencode.hpp>
#include "utils.h"

class TorrentFile {

    public:

    TorrentFile(const std::string &fileLocation):fileLocation(fileLocation)
    {
        processFile();
    }
    
    const std::string getDecodedData(){
        return this->data;
    }

    private:
        const std::string fileLocation;
        std::string data;

    bool processFile(){ 

        namespace bc = bencode;

        std::fstream f(this->fileLocation);

        if (!f.is_open())
        {
            std::cout << "file not found" << std::endl;
            return false;
        }

        std::stringstream iss;
        iss << f.rdbuf();
        std::string entireFile = iss.str();

        bc::bvalue b = bc::decode_value(entireFile);

        return true;
    }
};

#endif