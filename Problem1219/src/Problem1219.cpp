#include <string>
#include <array>
#include <cassert>
#include <vector>
#include <functional>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/path-with-maximum-gold/
 */
class Problem1219 {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        
        auto check = [&](size_t x, size_t y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        int maxScore = 0;

        std::function<void(size_t, size_t, int)> dfs = [&](size_t x, size_t y, int score) {
            maxScore = std::max(maxScore, score);
            if (!check(x, y)) return;
            if (grid[x][y] == 0) return;
            int cellScore = grid[x][y];
            grid[x][y] = 0;

            if (y + 1 < m) dfs(x, y + 1, score + cellScore);
            if (y > 0) dfs(x, y - 1, score + cellScore);
            if (x + 1 < n) dfs(x + 1, y, score + cellScore);
            if (x > 0) dfs(x - 1, y, score + cellScore);
            
            grid[x][y] = cellScore;
        };

        for (size_t x = 0; x < n; ++x) {
            for (size_t y = 0; y < m; ++y) {
                int deg = 0;

                if (y + 1 < m && grid[x][y + 1] != 0) deg++;
                if (y > 0 && grid[x][y - 1] != 0) deg++;
                if (x + 1 < n && grid[x + 1][y] != 0) deg++;
                if (x > 0 && grid[x - 1][y] != 0) deg++;

                if (deg <= 2) dfs(x, y, 0);
            }
        }

        return maxScore;
    }
};

int main() {
    Problem1219 problem;
    std::vector<std::vector<int>> grid = {{0,6,0}, {5,8,7}, {0,9,0}};
    assert(problem.getMaximumGold(grid) == 24);
    return 0;
}
