//
//  350_IntersectionOfTwoArraysII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/17/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Hashmap Method
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // time: O(max(m, n)); space: O(max(m, n))
        if (nums1.empty() || nums2.empty()) {
            return vector<int>();
        }
        vector<int> res;
        unordered_map<int, int> mp;
        for (int& num : nums1) {
            mp[num]++;
        }
        for (int& num : nums2) {
            if (mp[num]-- > 0) {
                res.push_back(num);
            }
        }
        return res;
    }
};

// // Follow-Up 1: What if the given array is already sorted? How would you optimize your algorithm?
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // time: O(max(mlogm, nlogn)); space: O(max(m, n))
//         if (nums1.empty() || nums2.empty()) {
//             return vector<int>({});
//         }
//         vector<int> res;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int m = nums1.size(), n = nums2.size();
//         int i = 0, j = 0;
//         while (i < m && j < n) {
//             if (nums1[i] == nums2[j]) {
//                 res.push_back(nums1[i]);
//                 i++;
//                 j++;
//             } else if (nums1[i] < nums2[j]) {
//                 i++;
//             } else {
//                 j++;
//             }
//         }
//         return res;
//     }
// };

// Follow-Up 2: What if nums1's size is small compared to nums2's size? Which algorithm is better?
// Ans2: The second solution would be better.

// Follow-Up 3: What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
/*
 Ans: If only nums2 cannot fit in memory, put all elements of nums1 into a Hashmap, read chunks of array that fit into memory,
 and record the intersections. If both nums1 and nums2 are too large to fit in memory, sort them individually (external sort),
 then read 2 elements from each array at a time in memory, and record intersections.
 */

// Test
int main () {
    Solution solution;
    vector<int> nums1({1, 2, 2, 1});
    vector<int> nums2({2, 2});
    vector<int> res = solution.intersect(nums1, nums2);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
