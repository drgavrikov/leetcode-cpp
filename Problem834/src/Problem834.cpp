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
        auto size = (size_t) n;
        graph = vector<vector<int>>(size);
        for (const auto &edge: edges) {
            const int from = edge[0];
            const int to = edge[1];
            graph[(size_t) from].push_back(to);
            graph[(size_t) to].push_back(from);
        }
        vertexCount = vector<int>(size, 1);
        sumSubtree = vector<int>(size, 0);

        dfs(0);
        dfs2(0);

        graph.clear();
        return sumSubtree;
    }

    void dfs(size_t vertex, size_t parent = SIZE_MAX) {
        for (int nextInt : graph[vertex]) {
            auto next = static_cast<size_t>(nextInt);
            if (next == parent) continue;
            dfs(next, vertex);
            vertexCount[vertex] += vertexCount[next];
            sumSubtree[vertex] += sumSubtree[next] + vertexCount[next];
        }
    }

    void dfs2(size_t vertex, size_t parent = SIZE_MAX) {
        for (int nextInt : graph[vertex]) {
            auto next = static_cast<size_t>(nextInt);
            if (next == parent) continue;
            sumSubtree[next] = sumSubtree[vertex] - vertexCount[next] + ((int) graph.size() - vertexCount[next]);
            dfs2(next, vertex);
        }
    }
};

int main() {
    Problem834 problem;
    vector<vector<int>> edges = {{0, 1},
                                 {0, 2},
                                 {2, 3},
                                 {2, 4},
                                 {2, 5}};
    vector<int> sumSubtree = {8, 12, 6, 10, 10, 10};
    assert(sumSubtree == problem.sumOfDistancesInTree(6, edges));
    return 0;
}
