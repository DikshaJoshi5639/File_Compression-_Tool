#include "frequency.h"
#include <fstream>
#include <stdexcept>

std::unordered_map<char, int> buildFrequencyTable(const std::string& filename) {
    std::unordered_map<char, int> freq;
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file");

    char ch;
    while (file.get(ch)) freq[ch]++;
    file.close();
    return freq;
}
