//
//  230_KthSmallestElementInABST.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/19/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// // DFS BST Method
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) { // time: O(nlogn); space: O(n)
//         int leftTotal = countNodes(root->left);
//         if (k <= leftTotal) {
//             return kthSmallest(root->left, k);
//         } else if (k > leftTotal + 1) {
//             return kthSmallest(root->right, k - 1 - leftTotal);
//         } else { // k == leftTotal + 1
//             return root->val;
//         }
//     }
// private:
//     int countNodes(TreeNode* node) {
//         if (node == nullptr) {
//             return 0;
//         }
//         return 1 + countNodes(node->left) + countNodes(node->right);
//     }
// };

// DFS Inorder Iterative Method
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) { // time: O(n); space: O(n)
        stack<TreeNode*> st;
        TreeNode* p = root;
        int count = 0;
        while (st.empty() == false || p != nullptr) {
            if (p != nullptr) {
                st.push(p);
                p = p->left;
            } else {
                TreeNode* node = st.top();
                st.pop();
                if (++count == k) {
                    return node->val;
                }
                p = node->right;
            }
        }
        return -1;
    }
};

// // DFS Inorder Recursive Method
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) { // time: O(n); space: O(n)
//         int count = k, res = 0;
//         helper(root, count, res);
//         return res;
//     }
// private:
//     void helper(TreeNode* node, int& count, int& res) {
//         if (node->left != nullptr) {
//             helper(node->left, count, res);
//         }
//         count--;
//         if (count == 0) {
//             res = node->val;
//             return;
//         }
//         if (node->right != nullptr) {
//             helper(node->right, count, res);
//         }
//     }
// };

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(16);
    cout << solution.kthSmallest(root, 3) << endl;
    return 0;
}
