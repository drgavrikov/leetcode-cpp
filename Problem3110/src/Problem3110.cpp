#include <algorithm>
#include <vector>
#include <cassert>
#include <numeric>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/score-of-a-string/solutions/5242625/one-line-solution/
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