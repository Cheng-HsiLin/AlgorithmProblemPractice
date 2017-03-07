//
//  1TwoSum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//// Two Pass Method with Hashmap
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) { // time: O(2n); space: O(n)
//        vector<int> res;
//        if (nums.empty()) { // Inval input
//            return res;
//        }
//        unordered_map<int, int> mp; // number to index
//        
//        // Build the hashmap
//        for (int i = 0; i < nums.size(); i++) {
//            mp[nums[i]] = i;
//        }
//        
//        int searchVal;
//        
//        for (int i = 0; i < nums.size(); i++) {
//            searchVal = target - nums[i];
//            if (mp.count(searchVal) && mp[searchVal] > i) {
//                res.push_back(i);
//                res.push_back(mp[searchVal]);
//                break; // assume only one solution
//            }
//        }
//        return res;
//    }
//};

// One Pass Method with Hashmap (More Efficient)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // time: O(n); space: O(n)
        vector<int> res;
        
        if (nums.empty()) { // Inval input
            return res;
        }
        
        unordered_map<int, int> mp; // number to index
        
        int searchVal;
        
        for (int i = 0; i < nums.size(); i++) {
            searchVal = target - nums[i];
            if (!mp.count(searchVal)) {
                mp[nums[i]] = i;
            } else {
                res.push_back(mp[searchVal]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({2, 7, 11, 15});
    vector<int> res = solution.twoSum(nums, 9);
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}
