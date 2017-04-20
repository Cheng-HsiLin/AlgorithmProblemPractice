//
//  199_BinaryTreeRightSideView.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/20/17.
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

// Iterative BFS Method
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { // time: O(n); space: O(n)
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur;
            size_t n = q.size();
            for (int i = 0; i < n; i++) {
                cur = q.front();
                q.pop();
                if (i == n - 1) {
                    res.push_back(cur->val);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};

// // Recursive DFS Method
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) { // time: O(n); space: O(n)
//         vector<int> res;
//         dfs(root, 0, res);
//         return res;
//     }
// private:
//     void dfs(TreeNode* node, int level, vector<int>& res) {
//         if (!node) {
//             return;
//         }
//         if (level == res.size()) {
//             res.push_back(node->val);
//         }
//         dfs(node->right, level + 1, res);
//         dfs(node->left, level + 1, res);
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> res = solution.rightSideView(root);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
