//
//  138_CopyListWithRandomPointer.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

// // Naive Hashtable Method
// class Solution {
// public:
//     RandomListNode *copyRandomList(RandomListNode *head) { // time: O(n); space: (n)
//         if (head == nullptr) {
//             return nullptr;
//         }
//         unordered_map<RandomListNode*, RandomListNode*> mp;
//         // Copy all nodes
//         RandomListNode* node = head;
//         while (node != nullptr) {
//             mp[node] = new RandomListNode(node->label);
//             node = node->next;
//         }
//         node = head; // reset to head
//         // modulate next and random pointers
//         while (node != nullptr) {
//             mp[node]->next = mp[node->next];
//             mp[node]->random = mp[node->random];
//             node = node->next;
//         }
//         return mp[head];
//     }
// };

// Optimized Space Method
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) { // time: O(n); space: O(1)
        if (head == nullptr) {
            return nullptr;
        }
        // Iterate the original list and duplicate each node
        // Connect the copied node after its original node
        RandomListNode *ptr = head, *next = nullptr;
        while (ptr != nullptr) {
            next = ptr->next;
            RandomListNode *node = new RandomListNode(ptr->label);
            ptr->next = node;
            node->next = next;
            ptr = next;
        }
        ptr = head; // reset to head
        // Modulate random pointers
        while (ptr != nullptr) {
            if (ptr->random != nullptr) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        ptr = head; // reset to head
        // Extract the copied list
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *p = dummy;
        while (ptr != nullptr) {
            next = ptr->next;
            p->next = next;
            p = p->next;
            ptr->next = next->next;
            ptr = ptr->next;
        }
        RandomListNode* h = dummy->next;
        delete dummy;
        return h;
    }
};

// Test
int main () {
    Solution solution;
    string s1 = "aaabb", s2 = "ababbc";
    cout << solution.longestSubstring(s1, 3) << endl;
    cout << solution.longestSubstring(s2, 2) << endl;
    return 0;
}
