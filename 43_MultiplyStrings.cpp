//
//  43_MultiplyStrings.cpp
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
    string multiply(string num1, string num2) { // time: O(m * n); space: O(m + n)
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for (int i = m - 1; i >=0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            res[i] += carry;
        }
        size_t startPos = res.find_first_not_of("0");
        if (startPos != string::npos) {
            return res.substr(startPos);
        } else {
            return "0";
        }
    }
};

// Test
int main () {
    Solution solution;
    string num1 = "123", num2 = "45";
    cout << solution.multiply(num1, num2) << endl; // 5535
    return 0;
}
