//
//  112_PathSum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/19/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// // Recursive DFS Method
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) { // time: O(n); space: O(n)
//         if (!root) {
//             return false;
//         }
//         int rest = sum - root->val;
//         if (!root->left && !root->right && rest == 0) {
//             return true;
//         }
//         return hasPathSum(root->left, rest) || hasPathSum(root->right, rest);
//     }
// };

// Iterative DFS Method
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) { // time: O(n); space: O(n)
        if (!root) {
            return false;
        }
        stack<TreeNode*> st;
        TreeNode* pre = nullptr, *cur = root;
        int total = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                total += cur->val;
                cur = cur->left;
            }
            cur = st.top();
            if (!cur->left && !cur->right && total == sum) {
                return true;
            }
            if (cur->right && pre != cur->right) {
                cur = cur->right;
            } else {
                pre = cur;
                total -= cur->val;
                st.pop();
                cur = nullptr;
            }
        }
        return false;
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    cout << (solution.hasPathSum(root, 22) ? "True" : "False") << endl;
    return 0;
}
