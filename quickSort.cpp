//
//  quickSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Quick Sort
// time: O(nlogn) for average, O(n^2) for the worst
// space: O(1)

int partition(vector<int>& nums, int left, int right) {
    int pi = left;
    int pivot = nums[left];
    do {
        while (left <= right && nums[left] <= pivot) {
            left++;
        }
        while (nums[right] > pivot) {
            right--;
        }
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    } while (left < right);
    swap(nums[pi], nums[right]);
    pi = right;
    return pi;
}

void quicksort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex;
    pivotIndex = partition(nums, left, right);
    quicksort(nums, left, pivotIndex - 1);
    quicksort(nums, pivotIndex + 1, right);
}

void quicksort(vector<int>& nums) {
    quicksort(nums, 0, nums.size() - 1);
}

// Test
int main () {
    vector<int> nums({3,2,1,5,6,4});
    quicksort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
