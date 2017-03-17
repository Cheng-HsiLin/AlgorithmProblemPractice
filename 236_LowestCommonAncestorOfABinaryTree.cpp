//
//  236_LowestCommonAncestorOfABinaryTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/17/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // time: O(n); space: O(n)
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
};

// // Iterative Method
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // time: O(n); space: O(n)
//         unordered_map<TreeNode*, TreeNode*> parents;
//         parents[root] = nullptr;
//         queue<TreeNode*> Q;
//         Q.push(root);
//         while(parents.count(p) == 0 || parents.count(q) == 0) {
//             int size = Q.size();
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = Q.front();
//                 Q.pop();
//                 if (node->left != nullptr) {
//                     parents[node->left] = node;
//                     Q.push(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     parents[node->right] = node;
//                     Q.push(node->right);
//                 }
//             }
//         }
//         unordered_set<TreeNode*> ancestors;
//         while (p != nullptr) {
//             ancestors.insert(p);
//             p = parents[p];
//         }
//         while (q != nullptr && ancestors.count(q) == 0) {
//             q = parents[q];
//         }
//         return q;
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* p1 = root->right, *q1 = root, *p2 = root->left->right->right, *q2 = root->left;
    TreeNode* LCA1 = solution.lowestCommonAncestor(root, p1, q1), *LCA2 = solution.lowestCommonAncestor(root, p2, q2);
    cout << LCA1->val << endl;
    cout << LCA2->val << endl;
    return 0;
}
