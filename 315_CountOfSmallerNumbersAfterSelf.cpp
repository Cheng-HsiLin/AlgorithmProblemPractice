//
//  315_CountOfSmallerNumbersAfterSelf.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Search Method
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) { // time: O(nlogn); space: O(n)
        vector<int> tmp, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int left = 0, right = tmp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tmp[mid] >= nums[i]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = right;
            tmp.insert(tmp.begin() + right, nums[i]);
        }
        return res;
    }
};

// // Binary Search Tree Method
// struct Node {
//     int val;
//     int smaller;
//     Node* left;
//     Node* right;
//     Node(int v, int s) : val(v), smaller(s), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) { // time: O(n^2); space: O(n)
//         vector<int> res(nums.size());
//         Node* root = nullptr;
//         for (int i = nums.size() - 1; i >= 0; i--) {
//             res[i] = insert(root, nums[i]);
//         }
//         return res;
//     }
// private:
//     int insert(Node* &root, int v) {
//         if (root == nullptr) {
//             root = new Node(v, 0);
//             return 0;
//         } else if (root->val > v) {
//             root->smaller++;
//             return insert(root->left, v);
//         } else {
//             return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
//         }
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({5, 2, 6, 1});
    vector<int> res = solution.countSmaller(nums);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
