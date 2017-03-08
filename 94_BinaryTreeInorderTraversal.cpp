//
//  94_BinaryTreeInorderTraversal.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// // Recursive Inorder Traversal
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) { // time: O(n); space: O(n)
//         vector<int> res;
//         helper(root, res);
//         return res;
//     }
// private:
//     void helper(TreeNode* node, vector<int>& res) {
//         if (!node) {
//             return;
//         }
//         helper(node->left, res);
//         res.push_back(node->val);
//         helper(node->right, res);
//     }
// };

// // Iterative Inorder Traversal
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) { // time: O(n); space: O(n)
//         vector<int> res;
//         if (!root) {
//             return res;
//         }
//         stack<TreeNode*> st;
//         TreeNode* cur = root;
//         while (cur || !st.empty()) {
//             while (cur) { // add left nodes first
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             if (!st.empty()) {
//                 cur = st.top();
//                 st.pop();
//                 res.push_back(cur->val);
//                 cur = cur->right;
//             }
//         }
//         return res;
//     }
// };

// Morris Traversal Algorithm (Space Optimization)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { // time: O(n); space: O(1)
        vector<int> res;
        TreeNode *cur = root, *prev = nullptr;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else { // cur->left != nullptr
                // find the predecessor
                prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) { // connect the predecessor to cur
                    prev->right = cur;
                    cur = cur->left;
                } else { // disconnect
                    prev->right = nullptr;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = solution.inorderTraversal(root);
    for (int& val : res) {
        cout << val << endl;
    }
    return 0;
}
