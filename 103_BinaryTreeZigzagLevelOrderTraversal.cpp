//
//  103_BinaryTreeZigzagLevelOrderTraversal.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { // time: O(n); space: O(n)
        vector<vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (q.empty() != true) {
            int n = q.size();
            vector<int> curLevel(n);
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                int index = leftToRight ? i : (n - 1 - i);
                curLevel[index] = cur->val;
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(curLevel);
        }
        return res;
    }
};

// // Recursive DFS Method
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) { // time: O(n); space: O(n)
//         vector<vector<int> > res;
//         dfs(root, 0, res);
//         for (int i = 1; i < res.size(); i += 2) {
//             reverse(res[i].begin(), res[i].end());
//         }
//         return res;
//     }
// private:
//     void dfs(TreeNode* node, int level, vector<vector<int> >& res) {
//         if (node == nullptr) {
//             return;
//         }
//         if (res.size() <= level) {
//             res.push_back(vector<int>());
//         }
//         res[level].push_back(node->val);
//         if (node->left != nullptr) {
//             dfs(node->left, level + 1, res);
//         }
//         if (node->right != nullptr) {
//             dfs(node->right, level + 1, res);
//         }
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
    vector<vector<int> > res = solution.zigzagLevelOrder(root);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
