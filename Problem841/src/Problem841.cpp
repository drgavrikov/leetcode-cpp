#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>


/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/keys-and-rooms/solutions/5028904/dfs-easy-solution/
 */
class Problem841 {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        size_t size = rooms.size();
        auto used = std::vector<bool>(size, false);

        std::function<void(size_t)> dfs = [&](size_t vertex) {
            used[vertex] = true;
            for (auto next: rooms[vertex]) {
                auto nextVertex = static_cast<size_t>(next);
                if (!used[nextVertex]) dfs(nextVertex);
            }
        };
        dfs(0);

        return std::all_of(used.begin(), used.end(), [](bool v) { return v; });
    }
};

int main() {
    Problem841 problem;
    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    assert(problem.canVisitAllRooms(rooms));
    return 0;
}
