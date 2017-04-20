//
//  114_FlattenBinaryTreeToLinkedList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/19/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative Method
class Solution {
public:
    void flatten(TreeNode* root) { // time: O(n); space: O(1)
        if (!root) {
            return;
        }
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* pre = cur->left;
                // Find the prenode of the current node to connect to the right substree of the current node
                while (pre->right) {
                    pre = pre->right;
                }
                // Replace the right substree of the current node with the left substree
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

// // Bottom-Up Method
// class Solution {
// public:
//     void flatten(TreeNode* root) { // time: O(n); space: O(n)
//         if (!root) {
//             return;
//         }
//         TreeNode* prev = nullptr;
//         helper(root, prev);
//     }
// private:
//     void helper(TreeNode* node, TreeNode* &prev) {
//         if (!node) {
//             return;
//         }
//         helper(node->right, prev);
//         helper(node->left, prev);
//         node->right = prev;
//         node->left = nullptr;
//         prev = node;
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    solution.flatten(root);
    TreeNode* cur = root;
    queue<TreeNode*> q;
    q.push(cur);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
    return 0;
}
