//
//  3_LongestSubstringWithoutRepeatingCharacters.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//// Two Pointers Method with vector record
//// Two pointers serve as the sliding window
//// Vector table records the occurrence of the character in ASCII code
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) { // time: O(2n); space: O(1)
//        vector<int> record(128, 0);
//        int start = 0, end = 0, res = 0, counter = 0;
//        while (end < s.size()) {
//            if (record[s[end++]]++ > 0) { // duplicate occurs
//                counter++; // duplicate counter
//            }
//            while (counter > 0) {
//                if (record[s[start++]]-- > 1) {
//                    counter--;
//                }
//            }
//            res = max(res, end - start);
//        }
//        return res;
//    }
//};

// One-Pass Two Pointers Method with vector record
// To reduce the number of operations:
// If the character which the end pointer points to has already occurred (end') before,
// the start pointer can skip the position before end' and points to end' + 1.
class Solution {
public:
    int lengthOfLongestSubstring(string s) { // time: O(n); space: O(n)
        int res = 0;
        vector<int> record(128, -1); // the position where start pointer should go if the char where end points occurred before
        for (int start = 0, end = 0; end < s.size(); end++) {
            start = max(start, record[s[end]]);
            res = max(res, end - start + 1);
            record[s[end]] = end + 1;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl; // abc
    cout << solution.lengthOfLongestSubstring(("bbbbb")) << endl; // b
    cout << solution.lengthOfLongestSubstring(("pwwkew")) << endl; // wke
    return 0;
}
