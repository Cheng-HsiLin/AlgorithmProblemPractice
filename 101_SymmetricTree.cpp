//
//  101_SymmetricTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/15/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// // Recursive Method
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) { // time: O(n); space: O(n)
//         if (root == nullptr) {
//             return true;
//         }
//         return helper(root->left, root->right);
//     }
// private:
//     bool helper(TreeNode* p, TreeNode* q) {
//         if (p == nullptr && q == nullptr) {
//             return true;
//         }
//         if (p == nullptr || q == nullptr) {
//             return false;
//         }
//         return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
//     }
// };

// Iterative Method
class Solution {
public:
    bool isSymmetric(TreeNode* root) { // time: O(n); space: O(n)
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (q.empty() == false) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }
            if (node1 == nullptr ||
                node2 == nullptr ||
                node1->val != node2->val) {
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << (solution.isSymmetric(root) ? "True" : "False") << endl;
    return 0;
}
