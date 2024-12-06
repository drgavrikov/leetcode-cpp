#include <string>
#include <cassert>
#include <unordered_set>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/solutions/6121161/loop-with-hash-table-to-skip-banned-numbers/
 */
class Problem2554 {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::unordered_set<int> bannedSet(banned.begin(), banned.end());
        int sum = 0;
        int count = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.contains(i)) {
                continue;
            }
            if (sum + i > maxSum) {
                break;
            }
            sum += i;
            ++count;
        }
        return count;
    }
};


int main() {
    Problem2554 problem;

    std::vector<int> banned1 = {2, 4};
    int n1 = 6, maxSum1 = 10;
    assert(problem.maxCount(banned1, n1, maxSum1) == 3);

    std::vector<int> banned2 = {1, 2, 3};
    int n2 = 4, maxSum2 = 6;
    assert(problem.maxCount(banned2, n2, maxSum2) == 1);
    return 0;
}
