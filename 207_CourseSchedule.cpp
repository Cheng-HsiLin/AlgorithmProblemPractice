//
//  207_CourseSchedule.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/29/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// BFS Method
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) { // time: O(numCourses^2); space: O(numCourses)
        // Build the graph
        vector<unordered_set<int> > graph = buildGraph(numCourses, prerequisites);
        
        // Calculate the number of prerequisites of each course
        vector<int> degrees = calculateIndegrees(graph);
        
        // Keep search for the nodes with zero degree and decrease degrees of their neighbors
        for (int i = 0; i < numCourses; i++) {
            int j;
            for (j = 0; j < numCourses; j++) {
                if (degrees[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j] = -1;
            for (int neigh : graph[j]) {
                degrees[neigh]--;
            }
        }
        return true;
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
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) { // time: O(numCourses^2); space: O(numCourses)
//         vector<unordered_set<int> > graph = buildGraph(numCourses, prerequisites);
//         vector<bool> visited(numCourses, false), onpath(numCourses, false);
//         for (int i = 0; i < numCourses; i++) {
//             // Detect if there is a cycle
//             if (visited[i] == false && dfsCycle(graph, i, onpath, visited) == true) {
//                 return false;
//             }
//         }
//         return true;
//     }
// private:
//     vector<unordered_set<int> > buildGraph(int numCourses, vector<pair<int, int> >& prerequisites) { // time: O(# of prerequisites
//         vector<unordered_set<int> > graph(numCourses);
//         for (auto& pre : prerequisites) {
//             graph[pre.second].insert(pre.first);
//         }
//         return graph;
//     }

//     bool dfsCycle(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
//         if (visited[node] == true) {
//             return false;
//         }
//         onpath[node] = visited[node] = true;
//         for (int neigh : graph[node]) {
//             if (onpath[neigh] == true || dfsCycle(graph, neigh, onpath, visited) == true) {
//                 return true;
//             }
//         }
//         return onpath[node] = false;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<pair<int, int> > prerequisites({{1, 0}, {0, 1}});
    cout << (solution.canFinish(2, prerequisites) ? "True" : "False") << endl; // False
    return 0;
}
