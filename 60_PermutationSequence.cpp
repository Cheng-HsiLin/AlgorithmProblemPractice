//
//  60_PermutationSequence.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/04/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) { // time: O(n); space: O(n)
        vector<int> factorial(n + 1, 1); // factorial lookup table
        vector<char> numbers; // available digits
        for (int i = 1; i <= n; i++) {
            factorial[i] = i * factorial[i - 1];
            numbers.push_back(i + '0');
        }
        string res;
        while (n > 0) {
            int index = (k - 1) / factorial[n - 1]; // decrementing k first is because of 0-based index
            res += numbers[index];
            numbers.erase(numbers.begin() + index);
            k = k - index * factorial[n - 1];
            n--;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.getPermutation(3, 5) << endl; // 312
    return 0;
}
