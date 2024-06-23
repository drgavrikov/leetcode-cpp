#include <algorithm>
#include <vector>
#include <cassert>
#include <numeric>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/solutions/5089876/linear-solution-with-bitset/
 */
class Problem3110 {
public:
    int scoreOfString(const std::string& s) {
        auto next = s.begin();
        return std::accumulate(s.begin(), s.end() - 1, 0, [&](int acc, char value) {
            ++next;
            return acc + std::abs(value - *next);
        });
    }
};

int main() {
    Problem3110 problem;
    assert(problem.scoreOfString("hello") == 13);
    return 0;
}