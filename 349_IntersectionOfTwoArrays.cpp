//
//  349_IntersectionOfTwoArrays.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { // time: O(n); space: O(n)
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        vector<int> res;
        for (int& i : nums2) {
            if (hashSet.count(i) != 0) {
                res.push_back(i);
                hashSet.erase(i);
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({1, 2, 2, 1}), nums2({2, 2});
    vector<int> res = solution.intersection(nums1, nums2);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
