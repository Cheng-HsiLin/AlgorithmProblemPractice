//
//  76_MinimumWindowSubstring.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/02/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) { // time: O(n); space: O(1)
        vector<int> map(128, 0);
        // build the record map
        for (char& c : t) {
            map[c]++;
        }
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - begin;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

// Test
int main () {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << solution.minWindow(s, t) << endl;
    return 0;
}
