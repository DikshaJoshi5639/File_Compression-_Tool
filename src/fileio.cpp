#include "fileio.h"
#include <fstream>
#include <bitset>

void compressFile(const std::string& inputFile, const std::string& outputFile, const std::unordered_map<char, std::string>& huffCodes) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile, std::ios::binary);
    std::string encoded = "";

    char ch;
    while (in.get(ch)) {
        encoded += huffCodes.at(ch);
    }
    in.close();

    while (encoded.size() % 8 != 0) encoded += '0';

    for (size_t i = 0; i < encoded.size(); i += 8) {
        std::bitset<8> byte(encoded.substr(i, 8));
        out.put(static_cast<unsigned char>(byte.to_ulong()));
    }
    out.close();
}