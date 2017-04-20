//
//  129_SumRootToLeafNumbers.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/20/17.
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

class Solution {
public:
    int sumNumbers(TreeNode* root) { // time: O(n); space: O(n)
        int res = 0;
        if (!root) {
            return res;
        }
        dfs(root, res, 0);
        return res;
    }
private:
    void dfs(TreeNode* node, int& res, int num) {
        if (!node) {
            return;
        }
        num = num * 10 + node->val;
        if (!node->left && !node->right) {
            res += num;
        }
        dfs(node->left, res, num);
        dfs(node->right, res, num);
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << solution.sumNumbers(root) << endl;
    return 0;
}
