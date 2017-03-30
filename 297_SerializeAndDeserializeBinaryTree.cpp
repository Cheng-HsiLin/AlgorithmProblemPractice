//
//  297_SerializeAndDeserializeBinaryTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Intuitive Naive Iterative Method
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // time: O(n); space: O(n)
        string res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        res += to_string(root->val);
        res += ",";
        while (q.empty() == false) {
            TreeNode* node = q.front();
            if (node->left != nullptr) {
                res += to_string(node->left->val);
                res += ",";
                q.push(node->left);
            } else {
                res += "#,";
            }
            if (node->right != nullptr) {
                res += to_string(node->right->val);
                res += ",";
                q.push(node->right);
            } else {
                res += "#,";
            }
            q.pop();
        }
        // trimming ',' and '#' from the end
        int i = res.length() - 1;
        for (--i; i >= 0 && res[i] == '#'; i -= 2) {}
        return res.substr(0, i + 1);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // time: O(n); space: O(n)
        TreeNode* root = nullptr;
        if (data.empty() == true) {
            return root;
        }
        queue<TreeNode*> q;
        int offset = 0;
        int nodeValue = stoi(getNextNode(data, offset));
        root = new TreeNode(nodeValue);
        q.push(root);
        while (q.empty() == false) {
            TreeNode* node = q.front();
            if (offset < data.length()) {
                string sValue = getNextNode(data, offset);
                if (sValue != "#") {
                    int leftNodeValue = stoi(sValue);
                    node->left = new TreeNode(leftNodeValue);
                    q.push(node->left);
                }
            }
            if (offset < data.length()) {
                string sValue = getNextNode(data, offset);
                if (sValue != "#") {
                    int rightNodeValue = stoi(sValue);
                    node->right = new TreeNode(rightNodeValue);
                    q.push(node->right);
                }
            }
            q.pop();
        }
        return root;
    }
    
private:
    string getNextNode(const string& data, int& offset) {
        int end = data.find(',', offset);
        if (end == string::npos) {
            end = data.length();
        }
        string sNodeValue = data.substr(offset, end - offset);
        offset = end + 1;
        return sNodeValue;
    }
};

// // Recursive Preorder Method with stringstream
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) { // time: O(n); space: O(n)
//         ostringstream out;
//         serialize(root, out);
//         return out.str();
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) { // time: O(n); space: O(n)
//         istringstream in(data);
//         return deserialize(in);
//     }
// private:
//     void serialize(TreeNode* root, ostringstream& out) {
//         if (root == nullptr) {
//             out << "# ";
//         } else {
//             out << root->val << " ";
//             serialize(root->left, out);
//             serialize(root->right, out);
//         }
//     }
//     TreeNode* deserialize(istringstream& in) {
//         string val;
//         in >> val;
//         if (val == "#") {
//             return nullptr;
//         }
//         TreeNode* root = new TreeNode(stoi(val));
//         root->left = deserialize(in);
//         root->right = deserialize(in);
//         return root;
//     }
// };

// Test
int main () {
    Codec solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    string serialization = solution.serialize(root);
    cout << serialization << endl;
    
    TreeNode* newRoot = solution.deserialize(serialization);
    queue<TreeNode*> q;
    q.push(newRoot);
    while (q.empty() == false) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front(); q.pop();
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
    cout << endl;
    return 0;
}
