//
//  116_PopulatingNextRightPointersInEachNode.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// // Recursive DFS Method (Unacceptable)
// class Solution {
// public:
//     void connect(TreeLinkNode *root) { // time: O(n); space: O(n)
//         if (root == nullptr) {
//             return;
//         }
//         if (root->left != nullptr) {
//             root->left->next = root->right;
//             if (root->next != nullptr) {
//                 root->right->next = root->next->left;
//             }
//         }
//         connect(root->left);
//         connect(root->right);
//     }
// };

// Iterative Level Order Traversal Method
class Solution {
public:
    void connect(TreeLinkNode* root) { // time: O(n); space: O(1)
        if (root == nullptr) {
            return;
        }
        TreeLinkNode* p = root;
        while (p->left != nullptr) {
            TreeLinkNode* cur = p;
            while (cur != nullptr) {
                cur->left->next = cur->right;
                if (cur->next != nullptr) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            p = p->left;
        }
    }
};

// Test
int main () {
    Solution solution;
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    solution.connect(root);
    TreeLinkNode* ptr = root;
    while (ptr != nullptr) {
        TreeLinkNode* cur = ptr;
        cout << cur->val;
        while (cur->next != nullptr) {
            cout << " -> " << cur->next->val;
            cur = cur->next;
        }
        cout << " -> " << "NULL" << endl;
        ptr = ptr->left;
    }
    return 0;
}
