//
//  210_CourseScheduleII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// BFS Method
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) { // time: O(numCourses^2); space: O(numCourses)
        vector<unordered_set<int> > graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = calculateIndegrees(graph);
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                zeros.push(i);
            }
        }
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty() == true) {
                return {};
            }
            int zero = zeros.front();
            zeros.pop();
            res.push_back(zero);
            for (int neigh : graph[zero]) {
                if (--degrees[neigh] == 0) {
                    zeros.push(neigh);
                }
            }
        }
        return res;
    }
private:
    vector<unordered_set<int> > buildGraph(int& numCourses, vector<pair<int, int> >& prerequisites)  { // time: O(# of prerequisites)
        vector<unordered_set<int> > graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    vector<int> calculateIndegrees(vector<unordered_set<int> >& graph) { // time: O(numCourses^2)
        vector<int> degrees(graph.size(), 0);
        for (auto& neighbors : graph) {
            for (int neigh : neighbors) {
                degrees[neigh]++;
            }
        }
        return degrees; // represents how many prerequisites of each course (indegrees)
    }
};

// // DFS Method
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) { // time: O(numCourses^2); space: O(numCourses)
//         vector<unordered_set<int> > graph = buildGraph(numCourses, prerequisites);
//         vector<int> res;
//         vector<bool> onpath(numCourses, false), visited(numCourses, false);
//         for (int i = 0; i < numCourses; i++) {
//             if (visited[i] == false && dfsCycle(graph, i, onpath, visited, res) == true) {
//                 return vector<int>();
//             }
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// public:
//     vector<unordered_set<int> > buildGraph(int& numCourses, vector<pair<int, int> >& prerequisites) { // time: O(# of prerequisites)
//         vector<unordered_set<int> > graph(numCourses);
//         for (auto& pre : prerequisites) {
//             graph[pre.second].insert(pre.first);
//         }
//         return graph;
//     }

//     bool dfsCycle(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& res) {
//         if (visited[node] == true) {
//             return false;
//         }
//         onpath[node] = visited[node] = true;
//         for (int neigh : graph[node]) {
//             if (onpath[neigh] == true || dfsCycle(graph, neigh, onpath, visited, res) == true) {
//                 return true;
//             }
//         }
//         res.push_back(node);
//         return onpath[node] = false;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<pair<int, int> > prerequisites({{1, 0}});
    vector<int> res = solution.findOrder(2, prerequisites);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
