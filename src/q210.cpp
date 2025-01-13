// 给定个课程和这些课程的前置必修课，求可以一次性上完所有课的顺序。
#include "include/head.h"

class TrieNode {
   public:
    std::vector<int> findOrder(int numCourses,
                               std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
        std::vector<int> indegree(numCourses, 0), res;
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        std::queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            res.push_back(u);
            q.pop();
            for (auto v : graph[u]) {
                --indegree[v];
                if (!indegree[v]) {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i]) {
                return std::vector<int>();
            }
        }
        return res;
    }
};