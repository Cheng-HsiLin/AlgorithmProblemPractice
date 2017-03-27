//
//  215_KthLargestElementInAnArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Sort Method
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // time: O(nlogn); space: O(1)
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// // Naive Priority_Queue Method
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) { // time: O(nlogn); space: O(n)
//         priority_queue<int> pq(nums.begin(), nums.end());
//         int res;
//         while (k-- > 1) {
//             pq.pop();
//         }
//         res = pq.top();
//         return res;
//     }
// };

// // Optimized Priority_Queue Method
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) { // time: O(nlogk); space: O(k)
//         priority_queue<int, vector<int>, greater<int> > pq;
//         for (int i = 0; i < nums.size(); i++) {
//             if (pq.size() == k) {
//                 int smallest = pq.top();
//                 if (nums[i] > smallest) {
//                     pq.pop();
//                     pq.push(nums[i]);
//                 }
//             } else {
//                 pq.push(nums[i]);
//             }
//         }
//         return pq.top();
//     }
// };

// // Similar QuickSort Method
// // T(n) = T(n/2) + O(n)
// // O(n): partition time
// // Only need to consider one half of the array => time complexity: O(n)
// // If we need to consider both the two halves of the array, like quicksort,
// // then the recursion will be T(n) = 2T(n/2) + O(n) => time complexity: O(nlogn)
// // If the input array is sorted, T(n) = T(n - 1) + O(n), time complexity: O(n^2)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) { // time: O(n) for average, O(n^2) for the worst; space: O(1)
//         int left = 0, right = nums.size() - 1;
//         while (true) {
//             int pos = partition(nums, left, right);
//             if (pos == k - 1) {
//                 return nums[k - 1];
//             } else if (pos > k - 1) {
//                 right = pos - 1;
//             } else { // pos < k - 1
//                 left = pos + 1;
//             }
//         }
//     }
// private:
//     int partition(vector<int>& nums, int left, int right) {
//         // set the first element in the range as the pivot
//         int pivot = nums[left];
//         int l = left + 1, r = right;
//         while (l <= r) {
//             if (nums[l] < pivot && nums[r] > pivot) {
//                 swap(nums[l++], nums[r--]);
//             }
//             if (nums[l] >= pivot) {
//                 l++;
//             }
//             if (nums[r] <= pivot) {
//                 r--;
//             }
//         }
//         swap(nums[left], nums[r]);
//         return r;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({3,2,1,5,6,4});
    cout << solution.findKthLargest(nums, 2) << endl;
    return 0;
}
