//
//  100_SameTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/02/17.
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

// Recursive Method
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // time: O(n); space: O(n)
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// // Iterative Method
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) { // time: O(n); space:O (n)
//         // Use 2 stacks for preorder traversal
//         stack<TreeNode*> sp, sq;
//         if (p != nullptr) {
//             sp.push(p);
//         }
//         if (q != nullptr) {
//             sq.push(q);
//         }
//         while (sp.empty() == false && sq.empty() == false) {
//             TreeNode *pn = sp.top(), *qn = sq.top();
//             sp.pop(), sq.pop();
//             if (pn->val != qn->val) {
//                 return false;
//             }
//             if (pn->right != nullptr) {
//                 sp.push(pn->right);
//             }
//             if (qn->right != nullptr) {
//                 sq.push(qn->right);
//             }
//             if (sp.size() != sq.size()) {
//                 return false;
//             }
//             if (pn->left != nullptr) {
//                 sp.push(pn->left);
//             }
//             if (qn->left != nullptr) {
//                 sq.push(qn->left);
//             }
//             if (sp.size() != sq.size()) {
//                 return false;
//             }
//         }
//         return sp.size() == sq.size();
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode *root1 = new TreeNode(3), *root2 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root2->left = new TreeNode(1);
    root1->right = new TreeNode(5);
    root2->right = new TreeNode(5);
    cout << (solution.isSameTree(root1, root2) ? "True" : "False") << endl;
    return 0;
}
