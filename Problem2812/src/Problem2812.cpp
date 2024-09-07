#include <string>
#include <cassert>
#include <vector>
#include <queue>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/find-the-safest-path-in-a-grid/submissions/1382145632/
 */
class Problem2812 {
private:
    static bool isPathExists(const std::vector<std::vector<int>> &grid, int upper_factor) {
        size_t n = grid.size();
        std::queue<std::pair<size_t, size_t>> queue;
        std::vector<std::vector<bool>> used(n);
        for (size_t x = 0; x < n; ++x) {
            used[x].resize(n, false);
        }

        if (grid[0][0] >= upper_factor) {
            queue.push({0, 0});
            used[0][0] = true;
        }

        while (!queue.empty()) {
            auto point = queue.front();
            queue.pop();

            size_t x = point.first;
            size_t y = point.second;
            if (x == n - 1 && y == n - 1) {
                return true;
            }

            if (y + 1 < n && !used[x][y + 1] && grid[x][y + 1] >= upper_factor) {
                used[x][y + 1] = true;
                queue.push({x, y + 1});
            }
            if (y >= 1 && !used[x][y - 1] && grid[x][y - 1] >= upper_factor) {
                used[x][y - 1] = true;
                queue.push({x, y - 1});
            }
            if (x + 1 < n && !used[x + 1][y] && grid[x + 1][y] >= upper_factor) {
                used[x + 1][y] = true;
                queue.push({x + 1, y});
            }
            if (x >= 1 && !used[x - 1][y] && grid[x - 1][y] >= upper_factor) {
                used[x - 1][y] = true;
                queue.push({x - 1, y});
            }
        }
        return false;
    }

public:
    static int maximumSafenessFactor(std::vector<std::vector<int>> &grid) {
        size_t n = grid.size();
        assert(grid[0].size() == n);

        std::queue<std::pair<size_t, size_t>> queue;
        for (size_t x = 0; x < n; ++x) {
            for (size_t y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    queue.push({x, y});
                    grid[x][y] = 0;
                } else {
                    grid[x][y] = INT16_MAX;
                }
            }
        }

        while (!queue.empty()) {
            auto point = queue.front();
            queue.pop();

            size_t x = point.first;
            size_t y = point.second;

            if (y + 1 < n && grid[x][y] + 1 < grid[x][y + 1]) {
                grid[x][y + 1] = grid[x][y] + 1;
                queue.push({x, y + 1});
            }
            if (y >= 1 && grid[x][y] + 1 < grid[x][y - 1]) {
                grid[x][y - 1] = grid[x][y] + 1;
                queue.push({x, y - 1});
            }
            if (x + 1 < n && grid[x][y] + 1 < grid[x + 1][y]) {
                grid[x + 1][y] = grid[x][y] + 1;
                queue.push({x + 1, y});
            }
            if (x >= 1 && grid[x][y] + 1 < grid[x - 1][y]) {
                grid[x - 1][y] = grid[x][y] + 1;
                queue.push({x - 1, y});
            }
        }

        int left = 0;
        int right = static_cast<int>(2 * n);
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isPathExists(grid, mid)) {
                result = mid;
                left = mid + 1;
            } else right = mid - 1;
        }

        return result;
    }
};

int main() {
    Problem2812 problem;
    std::vector<std::vector<int>> grid;
    grid.push_back({0, 0, 0, 1});
    grid.push_back({0, 0, 0, 0});
    grid.push_back({0, 0, 0, 0});
    grid.push_back({1, 0, 0, 0});
    assert(problem.maximumSafenessFactor(grid) == 2);
    return 0;
}
