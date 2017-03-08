//
//  412_FizzBuzz.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) { // time: O(n); space: O(n)
        if (n <= 0) { // invalid input
            return vector<string>({});
        }
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                res[i - 1] += "Fizz";
            }
            if (i % 5 == 0) {
                res[i - 1] += "Buzz";
            }
            if (res[i - 1] == "") {
                res[i - 1] = to_string(i);
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<string> res = solution.fizzBuzz(15);
    for (auto& str : res) {
        cout << str << endl;
    }
    return 0;
}
