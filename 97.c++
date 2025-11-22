#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch]) return false;
            node = node->children[ch];
        }
        return true;
    }
};
