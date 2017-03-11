//
//  104_MaximumDepthofBinaryTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive DFS Method
class Solution {
public:
    int maxDepth(TreeNode* root) { // time: O(n); space: O(n)
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left), right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

// // Iterative BFS Method
// class Solution {
// public:
//     int maxDepth(TreeNode* root) { // time: O(n); space: O(n)
//         if (!root) {
//             return 0;
//         }
//         int depth = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             depth++;
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* cur = q.front();
//                 q.pop();
//                 if (cur->left) {
//                     q.push(cur->left);
//                 }
//                 if (cur->right) {
//                     q.push(cur->right);
//                 }
//             }
//         }
//         return depth;
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    root->left->left->right->left = new TreeNode(7);
    cout << solution.maxDepth(root) << endl;
    return 0;
}
