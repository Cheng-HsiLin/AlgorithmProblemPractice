//
//  insertionSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Insertion Sort
// time: O(n^2)
// space: O(1)
void insertionSort(vector<int>& nums) {
    // Search for first several numbers
    // Use a temp variable to record the last element in current range
    // Compare with previous elements
    // Shift previous to the right if they are not sorted
    int n = nums.size(), j, temp;
    for (int i = 1; i < n; i++) {
        temp = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = temp;
    }
}

// Test
int main () {
    vector<int> nums({3,2,5,1,6,4});
    insertionSort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
