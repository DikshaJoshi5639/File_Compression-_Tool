#include "huffman.h"

HuffmanNode::HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

bool Compare::operator()(HuffmanNode* a, HuffmanNode* b) {
    return a->freq > b->freq;
}

HuffmanNode* buildHuffmanTree(const std::unordered_map<char, int>& freqMap) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    return pq.top();
}

void generateCodes(HuffmanNode* root, const std::string& code, std::unordered_map<char, std::string>& huffCodes) {
    if (!root) return;
    if (!root->left && !root->right) huffCodes[root->ch] = code;
    generateCodes(root->left, code + "0", huffCodes);
    generateCodes(root->right, code + "1", huffCodes);
}

void freeTree(HuffmanNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
