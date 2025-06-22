#ifndef FILEIO_H
#define FILEIO_H

#include <unordered_map>
#include <string>

void compressFile(const std::string& inputFile, const std::string& outputFile, const std::unordered_map<char, std::string>& huffCodes);

#endif