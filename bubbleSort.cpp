//
//  bubbleSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithms>

using namespace std;

// Bubble Sort
// time: O(n^2)
// space: O(1)
void bubbleSort(vector<int>& nums) {
    bool isSorted = false;
    int lastUnsorted = nums.size() - 1;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < lastUnsorted; i++) {
            if (nums[i] > nums[i + 1]) {
                isSorted = false;
                swap(nums[i], nums[i + 1]);
            }
        }
        lastUnsorted--; // at least, nums[lastUnsorted] gets correct after each round
    }
}

// Test
int main () {
    vector<int> nums({3,2,5,1,6,4});
    bubbleSort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
