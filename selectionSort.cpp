//
//  selectionSort.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Selection Sort
// time: O(n^2)
// space: O(1)
void selectionSort(vector<int>& nums) {
    // Select the minimum in the current range,
    // and swap with the first element
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[min] > nums[j]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

// Test
int main () {
    vector<int> nums({3,2,5,1,6,4});
    selectionSort(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
