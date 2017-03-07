//
//  5_LongestPalindromicSubstring.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//// Brute Force Method (Unaccepted on OJ due to TLE)
//class Solution {
//public:
//    string longestPalindrome(string s) { // time: O(n^2); space: O(n)
//        if (s.empty()) {
//            return "";
//        }
//        int n = s.size(), curMax = 1;
//        string res;
//        for (int i = 0; i < n; i++) {
//            for (int len = curMax; i + len <= n; len++) {
//                string tmp = s.substr(i, len);
//                if (isPalindrome(tmp)) {
//                    curMax = len;
//                    res = tmp;
//                }
//            }
//        }
//        return res;
//    }
//private:
//    bool isPalindrome(string str) {
//        int n = str.size();
//        int start = 0, end = n - 1;
//        while (start < end) {
//            if (str[start] != str[end]) {
//                return false;
//            }
//            start++;
//            end--;
//        }
//        return true;
//    }
//};

//// Three-Pointers Sliding Window Method
//class Solution {
//public:
//    string longestPalindrome(string s) { // time: O(n^2); space: O(1)
//        int len = s.size();
//        if (len < 2) {
//            return s;
//        }
//        int minStart = 0, maxLen = 1, mid = 0, left = 0, right = 0;
//        while (mid < len) {
//            // cannot find a longer palindrome if the right part is shorter than half maxLen
//            if ((len - mid) <= maxLen / 2) { // pruning
//                break;
//            }
//            left = mid, right = mid;
//            // Skip duplicates
//            while (right < len - 1 && s[right] == s[right + 1]) {
//                right++;
//            }
//            mid = right + 1; // update mid for the next loop
//            while (right < len - 1 && s[right + 1] == s[left - 1]) {
//                right++;
//                left--;
//            }
//            int newLen = right - left + 1;
//            if (newLen > maxLen) {
//                maxLen = newLen;
//                minStart = left;
//            }
//        }
//        return s.substr(minStart, maxLen);
//    }
//};

// Expand From the Center of String
class Solution {
public:
    string longestPalindrome(string s) { // time: O(n^2); space: O(1)
        int start = 0, maxLen = 1, len1 = 0, len2 = 0, len = 0;
        for (int i = 0; i < s.size(); i++) { // mid loop
            len1 = expandFromCenter(s, i, i); // odd length case
            len2 = expandFromCenter(s, i, i + 1); // even length case
            len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
private:
    int expandFromCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.longestPalindrome("babad") << endl; // aba
    cout << solution.longestPalindrome("cbbd") << endl; // bb
    return 0;
}
