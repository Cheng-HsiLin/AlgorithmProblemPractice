//
//  28_ImplementstrStr().cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// Two Pointers
class Solution {
public:
    int strStr(string haystack, string needle) { // time: O(m + n); space: O(1)
        if (needle.empty() == true) {
            return 0;
        }
        int m = haystack.length(), n = needle.length();
        for (int i = 0; i < m - n + 1; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) { // found
                return i;
            }
        }
        return -1;
    }
};

// Test
int main () {
    Solution solution;
    string H1 = "abcde", N1 = "bc";
    cout << solution.strStr(H1, N1) << endl;
    string H2 = "abbbb", N2 = "";
    cout << solution.strStr(H2, N2) << endl;
    return 0;
}
