//
//  66_PlusOne.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/14/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { // time: O(n); space: O(n)
        int n = digits.size(), carry = 0;
        vector<int> res(digits.begin(), digits.end());
        res[n - 1] += 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        if (carry != 0) {
            res.insert(res.begin(), carry);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({1, 9, 9}), nums2({0}), nums3({1, 2, 3});
    vector<int> res1 = solution.plusOne(nums1);
    vector<int> res2 = solution.plusOne(nums2);
    vector<int> res3 = solution.plusOne(nums3);
    for (auto& i : res1) {
        cout << i << " ";
    }
    cout << endl;
    for (auto& i : res2) {
        cout << i << " ";
    }
    cout << endl;
    for (auto& i : res3) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
