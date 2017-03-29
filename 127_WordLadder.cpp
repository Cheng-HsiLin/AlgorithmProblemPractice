//
//  127_WordLadder.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// // One-End BFS Method
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // time: O(n*wordLength); space: O(n)
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         queue<string> toVisit; // record non-visited neighbors
//         addNextWords(beginWord, dict, toVisit);
//         int res = 2; // at least including beginWord and endWord
//         while (toVisit.empty() == false) {
//             int num = toVisit.size();
//             for (int i = 0; i < num; i++) {
//                 string word = toVisit.front();
//                 toVisit.pop();
//                 if (word == endWord) {
//                     return res;
//                 }
//                 addNextWords(word, dict, toVisit);
//             }
//             res++;
//         }
//         return 0; // no such transformation sequence
//     }
// private:
//     void addNextWords(string& word, unordered_set<string>& dict, queue<string>& toVisit) {
//         dict.erase(word);
//         for (int p = 0; p < word.size(); p++) {
//             char letter = word[p]; // record the original letter temporarily
//             for (int k = 0; k < 26; k++) {
//                 word[p] = 'a' + k;
//                 if (dict.count(word) != 0) {
//                     toVisit.push(word);
//                     dict.erase(word); // erase a word from dict once it is visited
//                 }
//             }
//             word[p] = letter; // reset to the original one
//         }
//     }
// };

// Two-End BFS Method
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // time: O(res * maxSetNum * maxWordLen); space: O(n)
        unordered_set<string> dict(wordList.begin(), wordList.end()), startSet, endSet;
        if (dict.count(endWord) == 0) {
            return 0;
        }
        startSet.insert(beginWord);
        endSet.insert(endWord);
        dict.erase(endWord);
        int res = 2;
        while (startSet.empty() == false && endSet.empty() == false) {
            if (startSet.size() > endSet.size()) {
                swap(startSet, endSet);
            }
            unordered_set<string> temp;
            for (string word : startSet) {
                for (int p = 0; p < word.size(); p++) { // iterate the characters in the current word
                    char letter = word[p];
                    for (char c = 'a'; c <= 'z'; c++) { // try all 26 alphabets
                        word[p] = c;
                        if (endSet.count(word) != 0) {
                            return res;
                        }
                        if (dict.count(word) != 0) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            startSet = temp;
            res++;
        }
        return 0;
    }
};

// Test
int main () {
    Solution solution;
    vector<string> wordList({"hot","dot","dog","lot","log","cog"});
    // "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    cout << solution.ladderLength("hit", "cog", wordList) << endl; // 5
    return 0;
}
