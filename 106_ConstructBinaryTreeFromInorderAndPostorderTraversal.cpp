//
//  106_ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { // time: O(n); space: O(n)
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        // record the corresponding index of numbers in inorder traversal
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(mp, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* build(unordered_map<int, int>& mp, vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1) {
        if (s0 > e0 || s1 > e1) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[e1]);
        int mid = mp[postorder[e1]]; // retrieve the middle index in inorder traversal
        int num = mid - s0;
        root->left = build(mp, inorder, s0, mid - 1, postorder, s1, s1 + num - 1);
        root->right = build(mp, inorder, mid + 1, e0, postorder, s1 + num, e1 - 1);
        return root;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> inorder({5,10,15,20,25,30,35}), postorder({5,15,10,25,35,30,20});
    TreeNode* res = solution.buildTree(inorder, postorder);
    queue<TreeNode*> q;
    q.push(res);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            TreeNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
    return 0;
}
