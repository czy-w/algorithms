#include <climits>
#include <iostream>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

typedef std::pair<int, int> Edge;

const int MAX_VERTICES = 100;
const int NO_EDGE = INT_MAX;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct GraphMatrix {
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

    GraphMatrix(int v)
        : vertices(v), adjMatrix(v, std::vector<int>(v, NO_EDGE)) {}

    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        }
    }
};

struct GraphList {
    int vertices;                  
    std::vector<std::vector<Edge>> adjList;
    GraphList(int v) : vertices(v), adjList(v) {}
    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].emplace_back(v, weight);
            adjList[v].emplace_back(u, weight);
        }
    }
};