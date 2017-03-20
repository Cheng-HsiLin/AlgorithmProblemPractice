//
//  151_ReverseWordsInAString.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// // Naive Not In-Place Method
// class Solution {
// public:
//     void reverseWords(string &s) { // time: O(n); space: O(n)
//         string res;
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == ' ') {
//                 continue;
//             }
//             int pos = i;
//             while (i < s.length() && s[i] != ' ') {
//                 i++;
//             }
//             res = s.substr(pos, i - pos) + ' ' + res;
//         }
//         s = res.substr(0, res.length() - 1);
//     }
// };

// // In-Place Method I
// class Solution {
// public:
//     void reverseWords(string &s) { // time: O(n); space: O(1)
//         // i is the current scanning position
//         // j is the current storing position
//         int i = 0, j = 0;
//         int n = s.length(), wordCount = 0;
//         while (i < n) {
//             while (i < n && s[i] == ' ') { // skip leading whitespaces
//                 i++;
//             }
//             if (i == n) {
//                 break;
//             }
//             if (wordCount > 0) {
//                 s[j++] = ' ';
//             }
//             // record the starting position of the current word
//             int start = j;
//             while (i < n && s[i] != ' ') {
//                 s[j++] = s[i++];
//             }
//             reverseWord(s, start, j - 1);
//             wordCount++;
//         }
//         // erase s[j...n-1]
//         s.resize(j);
//         reverseWord(s, 0, j - 1);
//     }
// private:
//     void reverseWord(string& s, int start, int end) {
//         while (start < end) {
//             char temp = s[start];
//             s[start++] = s[end];
//             s[end--] = temp;
//         }
//     }
// };

// In-Place II
class Solution {
public:
    void reverseWords(string &s) { // time: O(n); space: O(1)
        // reverse the whole string
        reverse(s.begin(), s.end());
        int storeIdx = 0, n = s.length();
        // reverse each word
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (storeIdx > 0) {
                s[storeIdx++] = ' ';
            }
            int j = i;
            while (j < n && s[j] != ' ') {
                s[storeIdx++] = s[j++];
            }
            reverse(s.begin() + storeIdx - (j - i), s.begin() + storeIdx);
            i = j;
        }
        s.resize(storeIdx);
    }
};

// Test
int main () {
    Solution solution;
    string str = "the sky is blue";
    solution.reverseWords(str);
    cout << str << endl;
    return 0;
}
