//
//  107_BinaryTreeLevelOrderTraversalII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
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

// BFS Method
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) { // time: O(n); space: O(n)
        vector<vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            vector<int> cur;
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                cur.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(cur);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// // DFS Method
// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) { // time: O(n); space: O(n)
//         vector<vector<int> > res;
//         levelOrder(res, root, 0);
//         reverse(res.begin(), res.end());
//         return res;
//     }
// private:
//     void levelOrder(vector<vector<int> >& res, TreeNode* node, int level) {
//         if (!node) {
//             return;
//         }
//         if (res.size() <= level) {
//             res.push_back({});
//         }
//         res[level].push_back(node->val);
//         if (node->left) {
//             levelOrder(res, node->left, level + 1);
//         }
//         if (node->right) {
//             levelOrder(res, node->right, level + 1);
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
    vector<vector<int> > res = solution.levelOrderBottom(root);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
