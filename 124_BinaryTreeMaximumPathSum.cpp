//
//  124_BinaryTreeMaximumPathSum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) { // time: O(n); space: O(n)
        int res = INT_MIN;
        maxPathSumDown(root, res);
        return res;
    }
private:
    int maxPathSumDown(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, maxPathSumDown(root->left, res));
        int right = max(0, maxPathSumDown(root->right, res));
        res = max(res, left + root->val + right);
        return max(left, right) + root->val;
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << solution.maxPathSum(root) << endl;
    return 0;
}
