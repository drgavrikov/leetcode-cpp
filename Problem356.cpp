#include <vector>
#include <unordered_set>
#include <cassert>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::numeric_limits;
using std::max;
using std::min;

class Problem356 {
public:
    bool isReflected(vector<vector<int> > &points) {
        unordered_map<int, unordered_set<int> > coordinates;
        int maxX = numeric_limits<int>::min();
        int minX = numeric_limits<int>::max();

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            coordinates[x].insert(y);

            maxX = max(maxX, x);
            minX = min(minX, x);
        }

        double middle = (maxX + minX) / 2.0;
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int reflectedX = static_cast<int>(middle - (x - middle));
            if (coordinates.find(reflectedX) == coordinates.end() ||
                coordinates[reflectedX].find(y) == coordinates[reflectedX].end())
                return false;
        }
        return true;
    }
};

int main() {
    Problem356 problem356;
    vector<vector<int>> points = {{1, -1}, {1, 1}};
    assert(problem356.isReflected(points));
    return 0;
}