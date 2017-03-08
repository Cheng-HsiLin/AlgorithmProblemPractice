//
//  38_CountAndSay.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) { // time: O(n * len); space: O(len)
        if (n <= 0) {
            return "";
        }
        string res = "1"; // 1st sequence, so we have to decrement n before going into while loop
        string cur;
        while (--n > 0) {
            cur = "";
            int len = res.size();
            // scan all digits in res
            for (int i = 0; i < len ; i++) {
                int count = 1; // at least 1 occurrence of each digit
                while (i + 1 < len && res[i] == res[i + 1]) { // duplicate => increment count and move on pointer
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur; // store the current res
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.countAndSay(5) << endl;
    cout << solution.countAndSay(6) << endl;
    return 0;
}
