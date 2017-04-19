//
//  113_PathSumII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/19/17.
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

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) { // time: O(n); space: O(n)
        vector<vector<int> > res;
        if (!root) {
            return res;
        }
        vector<int> cur;
        dfs(root, sum, cur, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int sum, vector<int>& cur, vector<vector<int> >& res) {
        if (!node) {
            return;
        }
        cur.push_back(node->val);
        if (!node->left && !node->right && sum == node->val) {
            res.push_back(cur);
        }
        dfs(node->left, sum - node->val, cur, res);
        dfs(node->right, sum - node->val, cur, res);
        cur.pop_back();
    }
};

// Test
int main () {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    vector<vector<int> > res = solution.pathSum(root, 22);
    for (vector<int>& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
