#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    int count;
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode() : count(0), isEnd(false) {}
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
            node->count++;
        }
        node->isEnd = true;
    }

    int countPrefix(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch]) return 0;
            node = node->children[ch];
        }
        return node->count;
    }
};
