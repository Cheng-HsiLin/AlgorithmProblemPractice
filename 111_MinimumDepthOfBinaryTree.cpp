//
//  111_MinimumDepthOfBinaryTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// // Recursive Method I
// class Solution {
// public:
//     int minDepth(TreeNode* root) { // time: O(n); space: O(n)
//         if (root == nullptr) {
//             return 0;
//         }
//         int distance = 1, res = INT_MAX;
//         depth(root, distance, res);
//         return res;
//     }
// private:
//     void depth(TreeNode* node, int& distance, int& res) {
//         if (!node->left && !node->right) {
//             res = min(distance, res);
//             return;
//         }
//         if (node->left) {
//             distance++;
//             depth(node->left, distance, res);
//             distance--;
//         }
//         if (node->right) {
//             distance++;
//             depth(node->right, distance, res);
//             distance--;
//         }
//     }
// };

// Recursive Method II
class Solution {
public:
    int minDepth(TreeNode* root) { // time: O(n); space: O(n)
        if (!root) {
            return 0;
        }
        if (!root->left) {
            return 1 + minDepth(root->right);
        }
        if (!root->right) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// // Iterative Method
// class Solution {
// public:
//     int minDepth(TreeNode* root) { // time: O(n); space: O(n)
//         if (!root) {
//             return 0;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         int d = 0;
//         while (!q.empty()) {
//             int len = q.size();
//             d++;
//             for (int i = 0; i < len; i++) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if (node->left) {
//                     q.push(node->left);
//                 }
//                 if (node->right) {
//                     q.push(node->right);
//                 }
//                 if (!node->left && !node->right) {
//                     return d;
//                 }
//             }
//         }
//         return -1;
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    cout << solution.minDepth(root) << endl;
    return 0;
}
