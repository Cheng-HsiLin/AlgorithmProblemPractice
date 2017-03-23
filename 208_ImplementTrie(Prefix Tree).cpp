//
//  208_ImplementTrie(Prefix Tree).cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define ALPHABETIC_SIZE 26
struct TrieNode {
    vector<TrieNode*> next;
    bool is_word;
    TrieNode(bool b = false) {
        next.resize(ALPHABETIC_SIZE, nullptr);
        is_word = b;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->next[idx] == nullptr) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, true);
    }
private:
    TrieNode* root;
    bool find(string& word, bool isPrefix) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->next[idx] == nullptr) {
                return false;
            }
            p = p->next[idx];
        }
        return isPrefix || p->is_word;
    }
};

// Test
int main () {
    Trie* obj = new Trie();
    obj->insert("genius");
    cout << (obj->search("geniu") ? "True" : "False") << endl; // False
    cout << (obj->startsWith("ge") ? "True" : "False") << endl; // True
    return 0;
}
