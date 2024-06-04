#include <cassert>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using std::vector;
using std::iostream;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/largest-local-values-in-a-matrix/solutions/5149791/sliding-window-solution/
 */
class Problem2373 {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        auto size = grid.size();
        auto result = vector(size - 2, vector<int>(size - 2));
        for (size_t row = 0; row < size - 2; ++row) {
            std::deque<int> deque;
            deque.push_back(std::max(grid[row][0], std::max(grid[row + 1][0], grid[row + 2][0])));
            deque.push_back(std::max(grid[row][1], std::max(grid[row + 1][1], grid[row + 2][1])));
            deque.push_back(std::max(grid[row][2], std::max(grid[row + 1][2], grid[row + 2][2])));

            result[row][0] = *std::max_element(deque.begin(), deque.end());

            for (size_t col = 1; col < size - 2; ++col) {
                deque.pop_front();
                deque.push_back(std::max(grid[row][col + 2], std::max(grid[row + 1][col + 2], grid[row + 2][col + 2])));

                result[row][col] = *std::max_element(deque.begin(), deque.end());
            }
        }
        return result;
    }
};

int main() {
    Problem2373 problem;
    vector<vector<int>> grid =
            {{9, 9, 8, 1},
             {5, 6, 2, 6},
             {8, 2, 6, 4},
             {6, 2, 2, 2}};
    vector<vector<int>> result =
            {{9, 9},
             {8, 6}};
    assert(problem.largestLocal(grid) == result);
    return 0;
}