//
//  108_ConvertSortedArrayToBinarySearchTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/17/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { // time: O(n); space: O(logn)
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (nums.empty() || start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid - 1);
        node->right = helper(nums, mid + 1, end);
        return node;
    }
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || st.empty() == false) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        if (st.empty() == false) {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
    return res;
}

// Test
int main () {
    Solution solution;
    vector<int> nums({1,3,5,7,9});
    TreeNode* root = solution.sortedArrayToBST(nums);
    vector<int> res = inorderTraversal(root);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
