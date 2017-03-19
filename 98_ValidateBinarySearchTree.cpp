//
//  98_ValidateBinarySearchTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/18/17.
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

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) { // time: O(n); space: O(n)
//         return validate(root, nullptr, nullptr);
//     }
// private:
//     bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
//         if (!node) {
//             return true;
//         }
//         if ((minNode != nullptr && node->val <= minNode->val) || (maxNode != nullptr && node->val >= maxNode->val)) {
//             return false;
//         }
//         return validate(node->left, minNode, node) && validate(node->right, node, maxNode);
//     }
// };

// Like inorder traversal method (Fast)
class Solution {
public:
    bool isValidBST(TreeNode* root) { // time: O(n); space: O(n)
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
private:
    bool validate(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) {
            return true;
        }
        if (validate(node->left, prev) == false) {
            return false;
        }
        if (prev != nullptr && prev->val >= node->val) {
            return false;
        }
        prev = node;
        return validate(node->right, prev);
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << (solution.isValidBST(root) ? "True" : "False") << endl;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << (solution.isValidBST(root1) ? "True" : "False") << endl;
    return 0;
}
