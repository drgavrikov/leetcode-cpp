#include <cassert>
#include <string>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/solutions/5229978/linear-solution-without-additional-memory/
 */
class Problem1404 {
public:
    int numSteps(std::string s) {
        int operations = 0;
        int carry = 0;
        for (size_t index = s.length() - 1; index > 0; index--) {
            int digit = (s[index] - '0') + carry;
            if (digit % 2 == 1) {
                operations += 2;
                carry = 1;
            } else {
                ++operations;
            }
        }
        return operations + carry;
    }
};

int main() {
    Problem1404 problem;
    assert(problem.numSteps("1101") == 6);
    return 0;
}
