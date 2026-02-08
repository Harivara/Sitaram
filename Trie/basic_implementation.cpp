#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    // Constructor: initialize everything
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    // Search a full word
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    // Check if any word starts with the prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
