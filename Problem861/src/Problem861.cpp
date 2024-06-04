#include <vector>
#include <cassert>

using std::vector;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/score-after-flipping-matrix/solutions/5154334/greedy-solution/
 */
class Problem861 {
public:
    int matrixScore(vector<vector<int>> &grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        for (size_t row = 0; row < n; ++row) {
            if (grid[row][0] == 1) continue;
            for (size_t col = 0; col < m; ++col) grid[row][col] = 1 - grid[row][col];
        }

        for (size_t col = 1; col < m; ++col) {
            int count = 0;
            for (size_t row = 0; row < n; ++row) count += grid[row][col];
            if (count >= static_cast<int>(n) - count) continue;
            for (size_t row = 0; row < n; ++row) grid[row][col] = 1 - grid[row][col];
        }

        int result = 0;
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col < m; ++col) {
                result += grid[row][col] << (m - 1 - col);
            }
        }
        return result;
    }
};

int main() {
    Problem861 problem;
    vector<vector<int>> grid = {
            {0, 0, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0}
    };
    assert(problem.matrixScore(grid) == 39);

    vector<vector<int>> grid2 = {
            {0, 1},
            {0, 1},
            {0, 1},
            {0, 0}
    };
    assert(problem.matrixScore(grid2) == 11);
    return 0;
}
