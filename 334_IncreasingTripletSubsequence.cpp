//
//  334_IncreasingTripletSubsequence.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/21/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) { // time: O(n); space: O(1)
        int x = INT_MAX, y = INT_MAX;
        for (int num : nums) {
            if (num <= x) {
                x = num;
            } else if (num <= y) {
                y = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({2, 3, 1, 4});
    cout << (solution.increasingTriplet(nums) ? "True" : "Fasle") << endl;
    vector<int> nums1({1, 2, 3, 4, 5});
    cout << (solution.increasingTriplet(nums1) ? "True" : "Fasle") << endl;
    vector<int> nums2({5, 4, 3, 2, 1});
    cout << (solution.increasingTriplet(nums2) ? "True" : "Fasle") << endl;
    return 0;
}
