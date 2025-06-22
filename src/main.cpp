#include "frequency.h"
#include "huffman.h"
#include "fileio.h"
#include <iostream>

int main() {
    std::string inputFile = "data/sample.txt";
    std::string outputFile = "data/output.huff";

    try {
        auto freqMap = buildFrequencyTable(inputFile);
        HuffmanNode* root = buildHuffmanTree(freqMap);

        std::unordered_map<char, std::string> huffCodes;
        generateCodes(root, "", huffCodes);

        compressFile(inputFile, outputFile, huffCodes);

        std::cout << "Compression complete. Output saved to " << outputFile << "\n";
        freeTree(root);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
