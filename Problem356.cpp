#include <vector>
#include <unordered_set>
#include <cassert>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::numeric_limits;

class Problem356 {
public:
    bool isReflected(vector<vector<int> > &points) {
        unordered_map<int, unordered_set<int> > coordinates;
        int maxX = numeric_limits<int>::min();
        int minX = numeric_limits<int>::max();

        for (const vector<int>& point : points) {
            const int x = point[0];
            const int y = point[1];
            coordinates[x].insert(y);

            if (x > maxX) maxX = x;
            if (x < minX) minX = x;
        }

        double middle = (maxX + minX) / 2.0;
        for (const vector<int>& point : points) {
            const int x = point[0];
            const int y = point[1];
            const int reflectedX = static_cast<int>(middle - (x - middle));
            if (coordinates.count(reflectedX) == 0 || coordinates[reflectedX].count(y) == 0) return false;
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