//
//  88_MergeSortedArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/12/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // time: O(m + n); space: O(1)
        // scan from the back of each array
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        // copy the rest of elements in nums2 to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1(7);
    nums1[0] = 1, nums1[1] = 3, nums1[2] = 5;
    vector<int> nums2(3);
    nums2[0] = 2, nums2[1] = 4, nums2[2] = 6;
    solution.merge(nums1, 3, nums2, 3);
    for (int& i : nums1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
