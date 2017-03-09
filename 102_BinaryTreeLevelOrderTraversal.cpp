//
//  102_BinaryTreeLevelOrderTraversal.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
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
    vector<vector<int>> levelOrder(TreeNode* root) { // time: O(n); space: O(n)
        vector<vector<int> > res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = nullptr;
        while (!q.empty()) {
            int n = q.size(); // the number of nodes in the current level
            vector<int> tmp; // the result of the current level
            for (int i = 0; i < n; i++) {
                cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.push_back(tmp); // put the current level result into res
        }
        return res;
    }
};

// // Recursive Method
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) { // time: O(n); space: O(n)
//         vector<vector<int> > res;
//         helper(root, 0, res);
//         return res;
//     }
// private:
//     void helper(TreeNode* root, int level, vector<vector<int> >& res) {
//         if (!root) {
//             return;
//         }
//         if (level == res.size()) {
//             res.push_back({});
//         }
//         res[level].push_back(root->val);
//         helper(root->left, level + 1, res);
//         helper(root->right, level + 1, res);
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int> > res = solution.levelOrder(root);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
