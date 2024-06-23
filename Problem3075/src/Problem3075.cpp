#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/maximize-happiness-of-selected-children/solutions/5136970/sorting-greedy-solution/
 */
class Problem3075 {
public:
    static long long maximumHappinessSum(std::vector<int> &happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        long long result = 0;
        for (size_t step = 0; step < static_cast<size_t>(k); step++) {
            int value = happiness[step] - static_cast<int>(step);
            if (value < 0) break;
            result += value;
        }
        return result;
    }
};

int main() {
    Problem3075 problem;
    std::vector<int> happiness = {1, 2, 3};

    std::map<int, int> mymap;
    mymap[3] = 4;
    mymap.erase(3);

    assert(problem.maximumHappinessSum(happiness, 2) == 4);
    std::vector<int> happiness2 = {1, 1, 1, 1};
    assert(problem.maximumHappinessSum(happiness2, 2) == 1);
    return 0;
}