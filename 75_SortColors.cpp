//
//  75_SortColors.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/15/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Naive Two-Pass Method
// class Solution {
// public:
//     void sortColors(vector<int>& nums) { // time: O(2n); space: O(1)
//         vector<int> record(3, 0);
//         for (int& num : nums) {
//             record[num]++;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (i < record[0]) {
//                 nums[i] = 0;
//             } else if (i < record[0] + record[1]) {
//                 nums[i] = 1;
//             } else {
//                 nums[i] = 2;
//             }
//         }
//     }
// };

// One-Pass Method
class Solution {
public:
    void sortColors(vector<int>& nums) { // time: O(n); space: O(1)
        int begin = 0, end = nums.size() - 1;
        int index = 0;
        while (index <= end) {
            if (nums[index] == 0) {
                swap(nums[begin++], nums[index++]);
            } else if (nums[index] == 2) {
                swap(nums[end--], nums[index]);
            } else {
                index++;
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({0,2,1,1,2,0,0,2,1,0});
    solution.sortColors(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> nums1({2,2,2,1,1,1,0,0,1,2,0,0,2,});
    solution.sortColors(nums1);
    for (int& i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
