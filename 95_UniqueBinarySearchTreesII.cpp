//
//  95_UniqueBinarySearchTreesII.cpp
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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) { // time: O((4^n) / (n^1.5)); space: O(n)
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubTree = helper(start, i - 1);
            vector<TreeNode*> rightSubTree = helper(i + 1, end);
            for (TreeNode*& leftNode : leftSubTree) {
                for (TreeNode*& rightNode : rightSubTree) {
                    TreeNode* node = new TreeNode(i);
                    node->left = leftNode;
                    node->right = rightNode;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};

// Test
int main () {
    Solution solution;
    vector<TreeNode*> res = solution.generateTrees(3);
    for (auto t : res) {
        queue<TreeNode*> q;
        q.push(t);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
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
    }
    return 0;
}
