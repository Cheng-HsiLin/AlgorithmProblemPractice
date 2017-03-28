//
//  mergeSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Merge Sort
// time: O(nlogn)
// space: O(n)

void merge(vector<int>& nums, int left, int right, int mid) {
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (i = 0; i < k; i++) {
        nums[left + i] = temp[i];
    }
}

void mergesort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    // Split the array into two equal sections
    mergesort(nums, left, mid); // left
    mergesort(nums, mid + 1, right); // right
    merge(nums, left, right, mid);
}

void mergesort(vector<int>& nums) {
    mergesort(nums, 0, nums.size() - 1);
}

// Test
int main () {
    vector<int> nums({3,2,5,1,6,4});
    mergesort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
