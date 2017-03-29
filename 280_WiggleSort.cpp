//
//  280_WiggleSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/29/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//// Sort Method
//class Solution {
//public:
//    void wiggleSort(vector<int>& nums) { // time: O(nlogn); space: O(1)
//        sort(nums.begin(), nums.end());
//        if (nums.size() <= 2) {
//            return;
//        }
//        for (int i = 2; i < nums.size(); i += 2) {
//            swap(nums[i], nums[i - 1]);
//        }
//    }
//};

// O(n) Method
class Solution {
public:
    void wiggleSort(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.size() <= 1) {
            return;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (((i & 1) == 1 && nums[i] < nums[i - 1]) || ((i & 1) == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({3, 5, 2, 1, 6, 4});
    solution.wiggleSort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
