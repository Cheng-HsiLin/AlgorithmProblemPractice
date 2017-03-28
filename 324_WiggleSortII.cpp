//
//  324_WiggleSortII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // Naive Sort Method + an additional vector
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) { // time: O(nlogn); space: O(n)
//         if (nums.empty() == true) {
//             return;
//         }
//         vector<int> tmp = nums;
//         sort(tmp.begin(), tmp.end());
//         int n = nums.size(), j = (n - 1) / 2, k = n - 1;
//         for (int i = 0; i < n; i++) {
//             nums[i] = (i & 1) == 1 ? tmp[k--] : tmp[j--];
//         }
//     }
// };

// Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
// Index Rewiring Method with STL function
// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing/2
class Solution {
public:
    void wiggleSort(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.empty() == true) {
            return;
        }
        int n = nums.size();
        
        // According to http://en.cppreference.com/w/cpp/algorithm/nth_element,
        // nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
        // 1. The element pointed at by nth is changed to whatever element would occur in that position if [first, last) was sorted
        // 2. All of the elements before this new nth element are less than or equal to the elements after the new nth element
        
        // Find the median
        vector<int>::iterator midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index Wiring
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        
        // Dutch National Flag (DNF) 3-way partition algorithm
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid) {
                swap(A(i++), A(j++));
            } else if (A(j) < mid) {
                swap(A(j), A(k--));
            } else {
                j++;
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({1, 5, 1, 1, 6, 4}), nums2({1, 3, 2, 2, 3, 1});
    solution.wiggleSort(nums1);
    for (int& i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    solution.wiggleSort(nums2);
    for (int& j : nums2) {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}
