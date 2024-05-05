#include <vector>
#include <cassert>

using std::vector;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/sum-of-distances-in-tree/solutions/5095463/linear-solution-with-two-dfs/
 */
class Problem834 {

    vector<vector<int>> graph;
    vector<int> vertexCount;
    vector<int> sumSubtree;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        graph = vector<vector<int>>(n);
        for (const auto &edge: edges) {
            const int from = edge[0];
            const int to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vertexCount = vector<int>(n, 1);
        sumSubtree = vector<int>(n, 0);

        dfs(0);
        dfs2(0);

        graph.clear();
        return sumSubtree;
    }

private:
    void dfs(int vertex, int parent = -1) {
        for (const auto &next: graph[vertex]) {
            if (next == parent) continue;
            dfs(next, vertex);
            vertexCount[vertex] += vertexCount[next];
            sumSubtree[vertex] += sumSubtree[next] + vertexCount[next];
        }
    }

    void dfs2(int vertex, int parent = -1) {
        for (const auto &next: graph[vertex]) {
            if (next == parent) continue;
            sumSubtree[next] = sumSubtree[vertex] - vertexCount[next] + (graph.size() - vertexCount[next]);
            dfs2(next, vertex);
        }
    }
};

int main() {
    Problem834 problem;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> sumSubtree = { 8, 12, 6, 10, 10, 10 };
    assert(sumSubtree == problem.sumOfDistancesInTree(6, edges));
    return 0;
}