// 给定一个图，判断其是否可以二分，
#include "include/head.h"

class TrieNode {
   public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) {
            return true;
        }
        std::vector<int> color(n, 0);
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!color[i]) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const int& j : graph[node]) {
                    if (color[j] == 0) {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    } else if (color[node] == color[j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};