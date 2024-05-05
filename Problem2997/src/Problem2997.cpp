#include <bitset>
#include <vector>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/solutions/5089876/linear-solution-with-bitset/
 */
class Problem2997 {
public:
    int minOperations(const std::vector<int> &nums, int k) {
        const int bitsInInt = sizeof(int) * 8;
        std::bitset<bitsInInt> xorResult = k;
        for (int num: nums) {
            xorResult ^= num;
        }
        return xorResult.count();
    }
};

int main() {
    Problem2997 problem;
    assert(problem.minOperations({2, 1, 3, 4}, 1) == 2);
    assert(problem.minOperations({2, 0, 2, 0}, 0) == 0);
    return 0;
}