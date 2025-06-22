#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <string>
#include <queue>
#include <vector>

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f);
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b);
};

HuffmanNode* buildHuffmanTree(const std::unordered_map<char, int>& freqMap);
void generateCodes(HuffmanNode* root, const std::string& code, std::unordered_map<char, std::string>& huffCodes);
void freeTree(HuffmanNode* root);

#endif

