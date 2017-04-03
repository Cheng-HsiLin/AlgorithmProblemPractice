//
//  67_AddBinary.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) { // time: O(max(m, n)); space: O(max(m, n))
        int m = a.size(), n = b.size();
        string res;
        int carry = 0;
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int tmp = (i >= 0 ? (a[i] - '0') : 0) + (j >= 0 ? (b[j] - '0') : 0) + carry;
            carry = tmp / 2;
            tmp %= 2;
            res.insert(res.begin(), tmp + '0');
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    string a = "11", b = "1";
    cout << solution.addBinary(a, b) << endl; // 100
    return 0;
}
