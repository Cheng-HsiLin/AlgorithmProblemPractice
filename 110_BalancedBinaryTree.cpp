//
//  110_BalancedBinaryTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // DFS Recursive Top-Down Method
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) { // time: O(n^2); space: O(n)
//         if (!root) {
//             return true;
//         }
//         int left = depth(root->left);
//         int right = depth(root->right);
//         return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
//     }
// private:
//     int depth(TreeNode* node) {
//         if (!node) {
//             return 0;
//         }
//         return max(depth(node->left), depth(node->right)) + 1;
//     }
// };

// DFS Recursive Bottom-Up Method
class Solution {
public:
    bool isBalanced(TreeNode* root) { // time: O(n); space: O(n)
        return helper(root) != -1;
    }
private:
    int helper(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = helper(node->left);
        if (left == -1) {
            return -1;
        }
        int right = helper(node->right);
        if (right == -1) {
            return -1;
        }
        if (abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << (solution.isBalanced(root) ? "True" : "False") << endl;
    return 0;
}
