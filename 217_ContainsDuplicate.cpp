//
//  217_ContainsDuplicate.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { // time: O(n); space: O(n)
        unordered_set<int> record;
        for (int num : nums) {
            if (record.count(num)) {
                return true;
            }
            record.insert(num);
        }
        return false;
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) { // time: O(n); space: O(n)
//         unordered_set<int> record(nums.begin(), nums.end());
//         return nums.size() != record.size();
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({1,2,2,3,4,5,6,7});
    cout << (solution.containsDuplicate(nums) ? "True" : "False") << endl;
    return 0;
}
