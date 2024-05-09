#include <string>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/number-of-wonderful-substrings/solutions/5093288/bit-manipulation-solution-with-linear-complexity/
 */
class Problem1915 {
public:
    long long wonderfulSubstrings(std::string word) {
        const int size = 1 << 10;
        long long frequencies[size];

        std::fill(frequencies, frequencies + size, 0LL);

        frequencies[0] = 1;

        long long result = 0;

        int mask = 0;
        for (size_t i = 0; i < word.length(); ++i) {
            int bit = word[i] - 'a';
            mask ^= (1 << bit);

            result += frequencies[mask];
            for (int odd_bit = 0; odd_bit < 10; ++odd_bit) {
                result += frequencies[mask ^ (1 << odd_bit)];
            }
            frequencies[mask]++;
        }
        return result;
    }
};

int main() {
    Problem1915 problem;
    assert(problem.wonderfulSubstrings("aba") == 4);
    assert(problem.wonderfulSubstrings("aabb") == 9);
    return 0;
}